//
// AREA PROJECT, 2020
// AREA
// File description:
// Github actions file
//

import axios from 'axios';
import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {GITHUB_AUTHTHENTIFICATION_CONSTANTS} from '../../../constants';
import {findOAuthService} from '../../OAuth';
import * as querystring from 'querystring';

class Github {
    static async createRepository(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET REPOSITORY */
        const repository = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Github').id);

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
        const res = await axios.post(GITHUB_AUTHTHENTIFICATION_CONSTANTS.CREATE_REPO_URL, params, {
            headers: {
                'Authorization': `Token ${oauthAccessToken}`,
            },
            validateStatus: false,
        });

        if (res.status == 201) {
            return (true);
        }

        return (false);
    }
}

export {Github};
