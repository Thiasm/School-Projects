//
// AREA PROJECT, 2020
// AREA
// File description:
// Google actions file
//

import {getOAuthDataByUUID, getReactionDataFromStore, insertReactionDataToStore} from '../../../DatabaseController/OAuth';
import {Google_Service} from '../../../OAuthController/Google';
import {findOAuthService} from '../../OAuth';

class Google {
    static async sendEmail(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET EMAIL AND MESSAGE TO BE SENT */
        const target_email = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const content_email = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Google').id);

        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT GOOGLE SERVICE */
        const api = new Google_Service();

        /* SET TOKEN AND SEND EMAIL */
        api.setAccessToken(access_token);
        api.sendEmail(target_email, content_email);
        return (true);
    }

    static async write_sheet(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TEXT TO WRITE */
        const to_write = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Google').id);

        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT GOOGLE SERVICE */
        const api = new Google_Service();

        /* SET TOKEN AND SEND EMAIL */
        api.setAccessToken(access_token);

        /* GET DATA FROM THE STORE */
        const reaction_data = await getReactionDataFromStore(_data.id);
        let sheet_id = null;

        /* IF NO DATA IS PRESENT, CREATE A NEW SHEET */
        if (reaction_data == null) {
            /* CREATE THE SHEET */
            sheet_id = await api.createSheet();

            /* STORE THE SHEET ID IN THE STORE */
            await insertReactionDataToStore(_data.user_id, _data.id, _data.link_action_reaction, JSON.stringify({
                spritesheetId: sheet_id,
            }));
        } else {
            sheet_id = JSON.parse(reaction_data.data).spritesheetId;
        }

        /* WRITE TO SHEET */
        const status = await api.writeSheet(sheet_id, to_write);

        if (status === false) {
            return (false);
        }
        return (true);
    }

    static async write_doc(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET TEXT TO WRITE */
        const to_write = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Google').id);

        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT GOOGLE SERVICE */
        const api = new Google_Service();

        /* SET TOKEN */
        api.setAccessToken(access_token);
        const reaction_data = await getReactionDataFromStore(_data.id);
        let doc_id = null;

        /* IF NO DATA IS PRESENT, CREATE A NEW DOC */
        if (reaction_data == null) {
            /* CREATE THE DOC */
            doc_id = await api.createDoc();

            /* STORE THE DOC ID IN THE STORE */
            await insertReactionDataToStore(_data.user_id, _data.id, _data.link_action_reaction, JSON.stringify({
                documentId: doc_id,
            }));
        } else {
            doc_id = JSON.parse(reaction_data.data).documentId;
        }

        /* WRITE TO DOC */
        const status = await api.writeDoc(doc_id, to_write);

        if (status === false) {
            return (false);
        }
        return (true);
    }
}

export {Google};
