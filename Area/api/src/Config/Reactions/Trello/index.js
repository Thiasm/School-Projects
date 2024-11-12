//
// AREA PROJECT, 2020
// AREA
// File description:
// Trello reactions file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {TRELLO_AUTHENTIFICATION_CONSTANTS} from '../../../constants';
import {findOAuthService} from '../../OAuth';
import axios from 'axios';

class Trello {
    static async createBoard(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE BOARD NAME FROM THE DATABASE */
        const board_name = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Trello').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessToken').value;

        /* CREATE THE QUERY */
        const params = {
            key: TRELLO_AUTHENTIFICATION_CONSTANTS.API_KEY,
            token: oauthAccessToken,
            name: board_name,
        };

        /* POST THE QUERY */
        const res = await axios.post(TRELLO_AUTHENTIFICATION_CONSTANTS.CREATE_BOARD_URL, params, {
            validateStatus: false,
        });

        if (res.status == 200) {
            return (true);
        }
        return (false);
    }
}

export {Trello};
