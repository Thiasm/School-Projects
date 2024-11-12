//
// AREA PROJECT, 2020
// AREA
// File description:
// Gitlab
//

import axios from 'axios';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import {GITLAB_AUTHTHENTIFICATION_CONSTANTS} from '../../../constants';
import * as path from 'path';
import * as querystring from 'querystring';

export class Gitlab_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('No UUID');
            return;
        }

        /* CREATE AUTHORIZE URL FOR USER */
        const params = {
            client_id: GITLAB_AUTHTHENTIFICATION_CONSTANTS.APP_ID,
            client_secret: GITLAB_AUTHTHENTIFICATION_CONSTANTS.SECRET,
            response_type: 'code',
            redirect_uri: GITLAB_AUTHTHENTIFICATION_CONSTANTS.REDIRECT,
            state: uuid,
            scope: 'api',
        };
        res.redirect(GITLAB_AUTHTHENTIFICATION_CONSTANTS.GITLAB_AUTH_AUTHORIZE(querystring.stringify(params)));
    }

    static async callback(req, res) {
        const {code, state} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Gitlab');

        if (!code || !state) {
            res.send('No code or no state');
            return;
        }

        /* CREATE ACCESS TOKEN GETTER URL FOR STORING DATA */
        const params = {
            client_id: GITLAB_AUTHTHENTIFICATION_CONSTANTS.APP_ID,
            client_secret: GITLAB_AUTHTHENTIFICATION_CONSTANTS.SECRET,
            code: code,
            redirect_uri: GITLAB_AUTHTHENTIFICATION_CONSTANTS.REDIRECT,
            grant_type: 'authorization_code',
        };

        /* GET THE ACCESS TOKEN */
        const response = await axios.post(GITLAB_AUTHTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params));

        /* INSERT THE ACCESS TOKEN IN THE DB */
        await insertOAuthData(JSON.stringify(response.data), state, id);

        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
