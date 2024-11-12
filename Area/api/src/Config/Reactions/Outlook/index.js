//
// AREA PROJECT, 2020
// AREA
// File description:
// Outlook actions file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {Outlook_Service} from '../../../OAuthController/Outlook';
import {findOAuthService} from '../../OAuth';

class Outlook {
    static async sendEmail(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET EMAIL AND MESSAGE TO BE SENT */
        const target_email = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const content_email = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Office 365').id);

        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT OUTLOOK SERVICE */
        const api = new Outlook_Service();

        /* SET THE TOKEN AND SEND EMAIL */
        api.setAccessToken(access_token);
        api.sendEmail(target_email, content_email);
        return (true);
    }

    static Email_Error(value) {
        const re = /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

        return (re.test(value));
    }
}

export {Outlook};
