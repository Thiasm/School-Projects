//
// AREA PROJECT, 2020
// AREA
// File description:
// Outlook
//

import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {Outlook_Service} from '../../../OAuthController/Outlook';
import {findOAuthService} from '../../OAuth';
import * as path from 'path';
import 'isomorphic-fetch';

export class Office_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('No UUID');
            return;
        }

        /* REDIRECT THE USER TO THE AUTHORIZATION URL */
        res.redirect(Outlook_Service.getAuthorizeURL(uuid));
    }

    static async callback(req, res) {
        const {code, state} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Office 365');

        if (!code || !state) {
            res.send('No code or no state');
            return;
        }

        /* SETUP THE OUTLOOK APIS MODULE */
        const instance = new Outlook_Service();
        const data = await instance.getRawData(code);

        /* INSERT THE OAUTH DATA IN THE DB */
        await insertOAuthData(JSON.stringify(data), state, id);

        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
