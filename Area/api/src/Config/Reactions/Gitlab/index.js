//
// AREA PROJECT, 2020
// AREA
// File description:
// Gitlab reactions file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {GITLAB_ACTION_CONSTANTS} from '../../../constants';
import {findOAuthService} from '../../OAuth';
import axios from 'axios';

class Gitlab {
    static async createRepository(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE REPOSITORY NAME FROM THE DATABASE */
        const repository = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Gitlab').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.access_token;


        /* CREATE THE QUERY */
        const params = {
            name: repository,
        };

        /* POST THE QUERY */
        const res = await axios.post(GITLAB_ACTION_CONSTANTS.CREATE_REPO_URL, params, {
            headers: {
                'Authorization': `Bearer ${oauthAccessToken}`,
            },
            validateStatus: false,
        });

        if (res.status == 201) {
            return (true);
        }
        return (false);
    }
}

export {Gitlab};
