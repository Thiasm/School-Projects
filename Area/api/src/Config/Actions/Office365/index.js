//
// AREA PROJECT, 2020
// AREA
// File description:
// Google services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {Outlook_Service} from '../../../OAuthController/Outlook';
import {ActionInterface} from '../interface';
import {findOAuthService} from '../../OAuth';

class Outlook {
    static async getOfficeMails(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET WORD */
        const target_word = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Office 365').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT OUTLOOK SERVICE */
        const api = new Outlook_Service();

        /* SET THE TOKEN AND GET THE LAST EMAIL */
        api.setAccessToken(access_token);
        const res = await api.getLastMail();

        /* CHECK IF USER HAS EMAILS NOR AN ERROR FROM THE API */
        if (res == null) {
            instance.setState(false);
            return (instance);
        }

        /* VARIABLES FROM MAIL */
        const email_date = res.receivedDateTime;
        const email_text = res.body.content;

        /* GET THE DIFFERENCE OF TIME BETWEEN THE EMAIL AND NOW */
        const date = new Date(email_date);
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff / 1000) / 60);

        /* FIND THE SENDER OF THE EMAIL FROM THE HEADERS (FOR THE VARIABLES) */
        const sent_from = res.sender.emailAddress.address;

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', email_text.replace(/[\n\r]+/g, ''));
        instance.setVariable('$2$', date);
        instance.setVariable('$3$', sent_from);

        /* IF THE EMAIL IS FROM LESS THAN TWO MINUTES THEN CONTINUE */
        if (minutes > 2) {
            instance.setState(false);
            return (instance);
        }

        /* CHECK IF THE TARGET WORD IS IN THE EMAIL */
        if (email_text.includes(target_word)) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async getmail_error(data) {
        return (true);
    }
}

export {Outlook};
