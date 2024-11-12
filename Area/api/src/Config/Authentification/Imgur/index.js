//
// AREA PROJECT, 2020
// AREA
// File description:
// Imgur
//

import axios from 'axios';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import {IMGUR_AUTHENTIFICATION_CONSTANTS} from '../../../constants';
import * as path from 'path';
import * as querystring from 'querystring';

export class Imgur_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('No UUID');
            return;
        }

        /* CREATE AUTHORIZE URL FOR USER */
        res.redirect(IMGUR_AUTHENTIFICATION_CONSTANTS.AUTHORIZE_URL(uuid));
    }

    static async callback(req, res) {
        const {code, state} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Imgur');

        if (!code || !state) {
            res.send('No code or no state');
            return;
        }

        /* CREATE ACCESS TOKEN GETTER URL FOR STORING DATA */
        const params = {
            client_id: IMGUR_AUTHENTIFICATION_CONSTANTS.CLIENT_ID,
            client_secret: IMGUR_AUTHENTIFICATION_CONSTANTS.CLIENT_SECRET,
            code: code,
            grant_type: 'authorization_code',
        };

        /* GET THE ACCESS TOKEN */
        const response = await axios.post(IMGUR_AUTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params));

        /* INSERT THE ACCESS TOKEN IN THE DB */
        await insertOAuthData(JSON.stringify(response.data), state, id);

        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
