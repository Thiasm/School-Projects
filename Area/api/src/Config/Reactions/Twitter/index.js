//
// AREA PROJECT, 2020
// AREA
// File description:
// Twitter actions file
//


import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import * as controller from '../../../OAuthController/Twitter';
import {findOAuthService} from '../../OAuth';

class Twitter {
    static async tweet(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* GET TWEET TO BE POSTED */
        const tweet_content = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Twitter').id);

        if (oauth_data == null) {
            return (false);
        }

        /* GET THE OAUTH ACCESS TOKEN AND TOKEN SECRET */
        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessToken').value;
        const oauthAccessTokenSecret = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessTokenSecret').value;

        /* POST THE QUERY */
        await controller.oauthPostTweet(tweet_content, oauthAccessToken, oauthAccessTokenSecret);
        return (true);
    }
}

export {Twitter};
