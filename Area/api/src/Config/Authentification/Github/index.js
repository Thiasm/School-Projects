//
// AREA PROJECT, 2020
// AREA
// File description:
// Gitlab
//

import axios from 'axios';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import {GITHUB_AUTHTHENTIFICATION_CONSTANTS} from '../../../constants';
import * as path from 'path';
import * as querystring from 'querystring';

export class Github_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('No UUID');
            return;
        }

        const params = {
            client_id: GITHUB_AUTHTHENTIFICATION_CONSTANTS.CLIENT_ID,
            client_secret: GITHUB_AUTHTHENTIFICATION_CONSTANTS.SECRET_ID,
            redirect_uri: GITHUB_AUTHTHENTIFICATION_CONSTANTS.REDIRECT,
            scope: 'repo',
            state: uuid,
        };
        res.redirect(GITHUB_AUTHTHENTIFICATION_CONSTANTS.GITHUB_AUTH_AUTHORIZE(querystring.stringify(params)));
    }

    static async callback(req, res) {
        const {code, state} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Github');

        if (!code || !state) {
            res.send('No code or no state');
            return;
        }

        const params = {
            client_id: GITHUB_AUTHTHENTIFICATION_CONSTANTS.CLIENT_ID,
            client_secret: GITHUB_AUTHTHENTIFICATION_CONSTANTS.SECRET_ID,
            code: code,
            redirect_uri: GITHUB_AUTHTHENTIFICATION_CONSTANTS.REDIRECT,
            state: state,
        };

        /* GET THE ACCESS TOKEN */
        const response = await axios.post(GITHUB_AUTHTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params), {
            headers: {
                'Accept': 'application/json',
            },
        });

        /* INSERT THE ACCESS TOKEN IN THE DB */
        await insertOAuthData(JSON.stringify(response.data), state, id);

        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
