//
// AREA PROJECT, 2020
// AREA
// File description:
// Gitlab services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {ActionInterface} from '../interface';
import {GITLAB_ACTION_CONSTANTS} from '../../../constants';
import {findOAuthService} from '../../OAuth';
import axios from 'axios';

class Gitlab {
    static async commits(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE REPOSITORY NAME FROM THE DATABASE */
        const repository = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Gitlab').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.access_token;

        /* GET LATEST COMMITS FROM REPOSITORY */
        const res = await axios.get(GITLAB_ACTION_CONSTANTS.COMMITS_URL(repository), {
            headers: {
                'Authorization': `Bearer ${oauthAccessToken}`,
            },
        });

        if (res.data.length == 0) {
            instance.setState(false);
            return (instance);
        }

        /* GET THE DIFFERENCE OF TIME BETWEEN THE COMMIT AND NOW */
        const date = new Date(res.data[0].created_at);
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff / 1000) / 60);

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', res.data[0].title);
        instance.setVariable('$2$', res.data[0].author_name);
        instance.setVariable('$3$', res.data[0].created_at);

        /* IF THE COMMIT IS FROM LESS THAN TWO MINUTES THEN RETURN OK */
        if (minutes < 2) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async commits_error(data) {
        return (true);
    }
}

export {Gitlab};
