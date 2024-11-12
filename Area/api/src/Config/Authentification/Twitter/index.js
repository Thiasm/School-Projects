//
// AREA PROJECT, 2020
// AREA
// File description:
// Twitter
//

import * as controller from '../../../OAuthController/Twitter';
import * as path from 'path';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import {TWITTER_AUTHTHENTIFICATION_CONSTANTS} from '../../../constants';
import 'isomorphic-fetch';

let oauthRequestTokenTemp = '';
let oauthRequestTokenSecretTemp = '';

let UUIDTemp = '';

export class Twitter_OAuth {
    static async auth(req, res) {
        const {uuid} = req.query;

        /* CHECK IF UUID IS PROVIDED IN QUERY OTHERWISE RETURN */
        if (!uuid) {
            res.send('Missing UUID');
            return;
        }

        /* INIT THE TWITTER CONTROLLER */
        const tokens = await controller.getTwitterOauth();

        /* SET THE TEMP VARIABLES */
        UUIDTemp = uuid;
        oauthRequestTokenTemp = tokens.oauthRequestToken;
        oauthRequestTokenSecretTemp = tokens.oauthRequestTokenSecret;

        /* REDIRECT THE USER TO THE AUTHORIZATION URL */
        res.redirect(TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_AUTHORIZE(tokens.oauthRequestToken));
    }

    static async callback(req, res) {
        const {oauth_token, oauth_verifier} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Twitter');

        /* CHECK IF THERE IS THE OAUTH TOKEN AND THE OAUTH VERIFIER */
        if (!oauth_token || !oauth_verifier) {
            res.send('Missing oauth_token and oauth_verifier');
            return;
        }

        /* INIT THE TWITTER CONTROLLER AND GET THE ACCESS TOKEN RELATIVE TO THE QUERY */
        const tokens = await controller.getOAuthAccessTokenWith(oauthRequestTokenTemp, oauthRequestTokenSecretTemp, oauth_verifier);

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
