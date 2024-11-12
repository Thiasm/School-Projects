//
// AREA PROJECT, 2020
// AREA
// File description:
// Google
//

import * as path from 'path';
import {createNewUserQuery, getUserByEmail} from '../../../DatabaseController/Register';
import {insertOAuthData} from '../../../DatabaseController/OAuth';
import {Google_Service} from '../../../OAuthController/Google';
import {findOAuthService} from '../../OAuth';
import {GOOGLE_AUTHTHENTIFICATION_CONSTANTS} from '../../../constants';
import {md5} from '../../../md5';

var mobileTmp = false;

export class Google_OAuth {
    static async auth(req, res) {
        const {uuid, mobile} = req.query;

        const _mobile = (mobile == 'true');
        if (_mobile == true) {
            mobileTmp = true;
        } else {
            mobileTmp = false;
        }

        /* REDIRECT THE USER TO THE AUTHORIZATION URL */
        res.redirect(Google_Service.getAuthorizeURL(uuid));
    }

    static async callback(req, res) {
        const {code, state} = req.query;

        /* GET THE ID OF THE OAUTH SERVICE (FOR STORING IN DB) */
        const {id} = findOAuthService('Google');

        /* SETUP THE GOOGLE APIS MODULE */
        const instance = new Google_Service();
        const data = await instance.getRawData(code);
        instance.setAccessToken(data.access_token);
        const user_infos = await instance.getUserInfos();

        /* IF THERE IS NO STATE IT MEANS THAT USER IS CURRENTLY REGISTERING WITH THE GOOGLE REGISTER OPTION */
        /* IF THAT'S THE CASE, CREATE AN ACCOUNT, AND LINK THE OAUTH DATA TO THE ACCOUNT */
        if (!state) {
            /* CHECK IF THE USER EXISTS, IF THAT'S THE CASE, RETURN THE LOGIN URL TO LOGIN */
            /* OTHERWISE REGISTER AN ACCOUNT */
            const doesUserExist = await getUserByEmail(user_infos.email);
            if (doesUserExist == true) {
                /* REDIRECT TO LOGIN PAGE */
                if (mobileTmp == true) {
                    res.redirect(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_AUTH_CALLBACK_MOBILE_LOGIN(user_infos.email, md5(user_infos.email)));
                } else {
                    res.redirect(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_AUTH_CALLBACK_LOGIN(user_infos.email, md5(user_infos.email)));
                }
                return;
            } else {
                /* CREATE NEW USER */
                const user = await createNewUserQuery(user_infos.email);

                /* INSERT THE OAUTH DATA */
                await insertOAuthData(JSON.stringify(data), user.uuid, id);

                /* REDIRECT TO LOGIN PAGE */
                if (mobileTmp == true) {
                    res.redirect(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_AUTH_CALLBACK_MOBILE_LOGIN(user_infos.email, md5(user_infos.email)));
                } else {
                    res.redirect(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_AUTH_CALLBACK_LOGIN(user_infos.email, md5(user_infos.email)));
                }
                return;
            }
        } else {
            /* INSERT THE OAUTH DATA IN THE DB */
            await insertOAuthData(JSON.stringify(data), state, id);
        }
        /* CLOSE THE POPUP FOR THE FRONT */
        res.sendFile(path.resolve('./public/index.html'));
    }
}
