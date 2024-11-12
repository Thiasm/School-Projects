//
// AREA PROJECT, 2020
// AREA
// File description:
// Google services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {Imgur_Service} from '../../../OAuthController/Imgur';
import {ActionInterface} from '../interface';
import {findOAuthService} from '../../OAuth';
import {OAuth} from 'oauth';

class Imgur {
    static async getUserPicture(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);
        const OAuth2 = new Imgur_Service();

        /* FIND THE TARGET WORD */
        const target_user = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Imgur').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        /* FORMAT OAUTH DATA */
        const formatted_oauth_data = JSON.parse(oauth_data.data);

        /* SET ACCESS TOKEN TO ACESS THE API */
        OAuth2.setAccessToken(formatted_oauth_data.access_token);

        /* FETCH LAST SUBMISSIONS */
        const photos_user = await OAuth2.getUserPictures(target_user);

        if (photos_user == null) {
            instance.setState(false);
            return (instance);
        }

        /* GET LAST PHOTO TO BE POSTED */
        const last_photo = photos_user[0];

        /* GET THE DIFFERENCE OF TIME BETWEEN NOW AND THE PHOTOS */
        const photo_date = new Date(last_photo.datetime * 1000);
        const diff = Math.abs(photo_date - new Date());
        const minutes = Math.floor((diff / 1000) / 60);

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', last_photo.title);
        instance.setVariable('$2$', new Date(last_photo.datetime * 1000));
        instance.setVariable('$3$', last_photo.account_url);
        instance.setVariable('$4$', last_photo.link);

        if (minutes < 2) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async getUserPictureError(data) {
        return (true);
    }
}

export {Imgur};
