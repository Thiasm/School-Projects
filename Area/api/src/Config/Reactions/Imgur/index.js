//
// AREA PROJECT, 2020
// AREA
// File description:
// Imgur actions file
//

import {Imgur_Service} from '../../../OAuthController/Imgur';
import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {findOAuthService} from '../../OAuth';
import axios from 'axios';

class Imgur {
    static async postPicture(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);
        const OAuth2 = new Imgur_Service();

        /* GET THE RECEIVER NUMBER AND THE MESSAGE TO BE SENT */
        const title = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const description = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const link_image = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_3$').value;
        let res = null;

        /* FETCH THE IMAGE GIVEN IN PARAMETER */
        try {
            res = await axios.get(link_image, {responseType: 'arraybuffer', validateStatus: false});
        } catch (err) {
            return (false);
        }

        if (res.data == null) {
            return (false);
        }

        /* CONVERT THE IMAGE TO BASE64 */
        const buffer = Buffer.from(res.data, 'binary').toString('base64');

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Imgur').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            return (false);
        }

        /* FORMAT OAUTH DATA */
        const formatted_oauth_data = JSON.parse(oauth_data.data);

        /* SET ACCESS TOKEN AND POST THE IMAGE */
        OAuth2.setAccessToken(formatted_oauth_data.access_token);
        const response = await OAuth2.postImage(title, description, buffer);

        if (response == null) {
            return (false);
        }
        return (true);
    }
}

export {Imgur};
