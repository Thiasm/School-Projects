//
// AREA PROJECT, 2020
// AREA
// File description:
// Trello
//

import * as path from 'path';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import {TRELLO_AUTHENTIFICATION_CONSTANTS} from '../../../constants';
import * as controller from '../../../OAuthController/Trello';
import 'isomorphic-fetch';

let oauthRequestTokenTmp = '';
let oauthRequestTokenSecretTmp = '';
let UUIDTemp = '';
export class Trello_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('Missing UUID');
            return;
        }

        /* GET TRELLO AUTHORIZE URL */
        const tokens = await controller.getImgurToken();

        /* SET THE TEMP VARIABLES */
        UUIDTemp = uuid;
        oauthRequestTokenTmp = tokens.oauthRequestToken;
        oauthRequestTokenSecretTmp = tokens.oauthRequestTokenSecret;

        /* REDIRECT TO THE AUTHORIZE URL */
        res.redirect(`${TRELLO_AUTHENTIFICATION_CONSTANTS.authorizeURL}?oauth_token=${tokens.oauthRequestToken}&name=${TRELLO_AUTHENTIFICATION_CONSTANTS.appName}&scope=${TRELLO_AUTHENTIFICATION_CONSTANTS.scope}&expiration=${TRELLO_AUTHENTIFICATION_CONSTANTS.expiration}`);
    }

    static async callback(req, res) {
        const {oauth_token, oauth_verifier} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Trello');

        /* INIT THE TWITTER CONTROLLER AND GET THE ACCESS TOKEN RELATIVE TO THE QUERY */
        const tokens = await controller.getOAuthAccessTokenWith(oauthRequestTokenTmp, oauthRequestTokenSecretTmp, oauth_verifier);

        /* GET THE ACCESS TOKENS VARIABLES */
        const oauthAccessToken = tokens.oauthAccessToken;
        const oauthAccessTokenSecret = tokens.oauthAccessTokenSecret;

        /* INSERT THE OAUTH DATA IN THE DB */
        await insertOAuthData(JSON.stringify([
            {
                name: 'oauthAccessToken',
                value: oauthAccessToken,
            },
            {
                name: 'oauthAccessTokenSecret',
                value: oauthAccessTokenSecret,
            },
        ]), UUIDTemp, id);

        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
