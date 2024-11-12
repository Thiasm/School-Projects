//
// AREA PROJECT, 2020
// AREA
// File description:
// Twitter services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import * as controller from '../../../OAuthController/Twitter';
import {ActionInterface} from '../interface';

class Twitter {
    static async tweet(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE USER TO LISTEN FOR HIS TWEET */
        const user = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, 2);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        /* FIND THE ACCESS TOKEN AND SECRET TOKEN TO USE THE TWITTER API */
        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const oauthAccessToken = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessToken').value;
        const oauthAccessTokenSecret = formatted_oauth_data.find((_tmp) => _tmp.name === 'oauthAccessTokenSecret').value;

        /* GET THE TWEETS FROM USER */
        const res = await controller.oauthGetTimelineByUser(user, oauthAccessToken, oauthAccessTokenSecret);

        /* CHECK IF USER HAS TWEETS */
        if (res.length == 0) {
            instance.setState(false);
            return (instance);
        }

        /* VARIABLES FROM TWEET */
        const tweet_info = res[0];
        const tweet_text = tweet_info.text;
        const tweet_author = tweet_info.user.screen_name;
        const tweet_date = tweet_info.created_at;

        /* GET THE DIFFERENCE OF TIME BETWEEN THE TWEET AND NOW */
        const date = new Date(tweet_date);
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff/1000)/60);

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', tweet_text);
        instance.setVariable('$2$', tweet_author);
        instance.setVariable('$3$', tweet_date);

        /* IF THE EMAIL IS FROM LESS THAN TWO MINUTES THEN RETURN TRUE */
        if (minutes < 2) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async tweet_error(data) {
        return (true);
    }
}

export {Twitter};
