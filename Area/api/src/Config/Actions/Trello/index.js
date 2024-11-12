//
// AREA PROJECT, 2020
// AREA
// File description:
// Trello services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {TRELLO_AUTHENTIFICATION_CONSTANTS} from '../../../constants';
import {ActionInterface} from '../interface';
import {findOAuthService} from '../../OAuth';
import axios from 'axios';
import * as querystring from 'querystring';

class Trello {
    static async getLastUpdatedBoard(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Trello').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        /* FIND THE ACCESS TOKEN AND SECRET TOKEN TO USE THE TWITTER API */
        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessToken').value;

        /* CREATE THE QUERY */
        const params = {
            key: TRELLO_AUTHENTIFICATION_CONSTANTS.API_KEY,
            token: oauthAccessToken,
        };

        /* POST THE QUERY */
        const res = await axios.get(TRELLO_AUTHENTIFICATION_CONSTANTS.GET_BOARDS_URL + querystring.stringify(params), {
            validateStatus: false,
        });

        /* GET RESPONSE FROM QUERY */
        const list_of_boards = res.data;

        /* GET THE DATE OF TODAY TO SORT THE FILES */
        const now = new Date();

        /* SORT ALL THE FILES DATE => RETURNS THE CLOSEST DATE IN THE FIRST ELEMENT */
        list_of_boards.sort(function(a, b) {
            const distancea = Math.abs(now - new Date(a.dateLastActivity));
            const distanceb = Math.abs(now - new Date(b.dateLastActivity));
            return distancea - distanceb;
        });

        /* GET THE BOARD CLOSEST TO NOW */
        const target_board = list_of_boards[0];

        /* GET THE DIFFERENCE OF TIME BETWEEN THE FILE MODIFICATION AND NOW */
        const date = new Date(target_board.dateLastActivity);
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff/1000)/60);

        /* SET THE VARIABLES FOR REACTIONS */
        instance.setVariable('$1$', target_board.name);
        instance.setVariable('$2$', target_board.dateLastActivity);
        instance.setVariable('$3$', target_board.url);

        if (minutes < 2) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async getLastUpdatedBoardError(data) {
        return (true);
    }
}

export {Trello};
