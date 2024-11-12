//
// AREA PROJECT, 2020
// AREA
// File description:
// Google services file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {Google_Service} from '../../../OAuthController/Google';
import {ActionInterface} from '../interface';
import {findOAuthService} from '../../OAuth';
import {YOUTUBE_ACTION_CONSTANTS} from '../../../constants';
import axios from 'axios';

class Google {
    static async getMails(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);
        const OAuth2 = new Google_Service();

        /* FIND THE TARGET WORD */
        const target_word = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Google').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        OAuth2.setAccessToken(formatted_oauth_data.access_token);

        const res = await OAuth2.isNewMail();
        /* CHECK IF USER HAS EMAILS NOR AN ERROR FROM THE API */
        if (res == null) {
            instance.setState(false);
            return (instance);
        }

        /* VARIABLES FROM MAIL */
        const email_date = res.internalDate;
        const email_text_base64 = res.payload.parts[0].body.data;
        const email_headers = res.payload.headers;

        /* GET THE DIFFERENCE OF TIME BETWEEN THE EMAIL AND NOW */
        const date = new Date(parseInt(email_date));
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff / 1000) / 60);

        /* DECODE THE EMAIL FROM BASE64 TO ASCII */
        const buff = new Buffer.from(email_text_base64, 'base64');
        const mailContent = buff.toString('ascii');

        /* FIND THE SENDER OF THE EMAIL FROM THE HEADERS (FOR THE VARIABLES) */
        const sender = email_headers.find((_header) => _header.name == 'From');

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', mailContent.replace(/[\n\r]+/g, '')); // REMOVES CARRIAGE RETURN FOR THE REACTIONS QUERIES
        instance.setVariable('$2$', date);
        instance.setVariable('$3$', sender.value);

        /* IF THE EMAIL IS FROM LESS THAN TWO MINUTES THEN CONTINUE */
        if (minutes > 2) {
            instance.setState(false);
            return (instance);
        }

        /* CHECK IF THE TARGET WORD IS IN THE EMAIL */
        if (mailContent.includes(target_word)) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async google_error(data) {
        return (true);
    }

    static async getDriveLastModifiedFile(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);
        const OAuth2 = new Google_Service();

        /* GET THE OAUTH DATA FROM THE DATABASE */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Google').id);

        /* CHECK IF USER LINKED HIS ACCOUNT */
        if (oauth_data == null) {
            instance.setState(false);
            return (instance);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        OAuth2.setAccessToken(formatted_oauth_data.access_token);
        const files = await OAuth2.getDriveFiles();

        /* GET THE DATE OF TODAY TO SORT THE FILES */
        const now = new Date();

        /* SORT ALL THE FILES DATE => RETURNS THE CLOSEST DATE IN THE FIRST ELEMENT */
        files.sort(function(a, b) {
            const distancea = Math.abs(now - a.modifiedDate);
            const distanceb = Math.abs(now - b.modifiedDate);
            return distancea - distanceb;
        });

        /* GET THE FILE CLOSEST TO NOW */
        const target_file = files[0];

        /* GET THE DIFFERENCE OF TIME BETWEEN THE FILE MODIFICATION AND NOW */
        const date = new Date(target_file.modifiedDate);
        const diff = Math.abs(date - new Date());
        const minutes = Math.floor((diff/1000)/60);

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', `${target_file.title}`);
        instance.setVariable('$2$', `${target_file.lastModifyingUser.displayName}`);
        instance.setVariable('$3$', `${target_file.modifiedDate}`);

        if (minutes < 2) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async getSubscribers(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE CHANEL NAME */
        const target_chanel = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* FIND THE TRIGGER SUBSCRIBER NUMBER */
        const target_n_subscribers = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* FIND CHANEL SEARCHED */
        const profile_response = await axios.get(YOUTUBE_ACTION_CONSTANTS.YOUTUBER_ID_URL(target_chanel), {validateStatus: false});

        /* CHECK IF THE YOUTUBE REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!profile_response.data.items[0]) {
            instance.setState(false);
            return (instance);
        }

        /* PARSE THE CHANEL ID */
        const channel_id = profile_response.data.items[0].snippet.channelId;

        /* GET CHANEL INFO */
        const id_response = await axios.get(YOUTUBE_ACTION_CONSTANTS.YOUTUBER_INFO_URL(channel_id), {validateStatus: false});

        /* CHECK IF THE YOUTUBE REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!profile_response.data.items[0]) {
            instance.setState(false);
            return (instance);
        }

        /* GET THE CHANEL SUBSCRIBERS NUMBER */
        const subscribers = id_response.data.items[0].statistics.subscriberCount;

        /* SET THE VARIABLES NAME FOR THE ACTION */
        instance.setVariable('$1$', `${profile_response.data.items[0].snippet.channelTitle}`);
        instance.setVariable('$2$', `${subscribers}`);
        instance.setVariable('$3$', `${id_response.data.items[0].statistics.viewCount}`);

        /* IF THE SUBSCRIBERS NUMBER IS MORE THAN THE TRIGGER NUMBER RETURN TRUE */
        if (Number(subscribers) >= Number(target_n_subscribers)) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async getViews(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE CHANEL NAME */
        const target_chanel = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* FIND THE TRIGGER VIEWS NUMBER */
        const target_n_views = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* FIND CHANEL SEARCHED */
        const profile_response = await axios.get(YOUTUBE_ACTION_CONSTANTS.YOUTUBER_ID_URL(target_chanel), {validateStatus: false});

        /* CHECK IF THE YOUTUBE REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!profile_response.data.items) {
            instance.setState(false);
            return (instance);
        }

        /* PARSE THE CHANEL ID */
        const channel_id = profile_response.data.items[0].snippet.channelId;

        /* GET CHANEL INFO */
        const id_response = await axios.get(YOUTUBE_ACTION_CONSTANTS.YOUTUBER_INFO_URL(channel_id), {validateStatus: false});

        /* CHECK IF THE YOUTUBE REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!profile_response.data.items) {
            instance.setState(false);
            return (instance);
        }

        /* GET THE CHANEL VIEWS NUMBER */
        const views = id_response.data.items[0].statistics.viewCount;

        /* SET THE VARIABLES NAME FOR THE ACTION */
        instance.setVariable('$1$', `${profile_response.data.items[0].snippet.channelTitle}`);
        instance.setVariable('$2$', `${id_response.data.items[0].statistics.subscriberCount}`);
        instance.setVariable('$3$', `${views}`);

        /* IF THE VIEWS NUMBER IS MORE THAN THE TRIGGER NUMBER RETURN TRUE */
        if (Number(views) > Number(target_n_views)) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async getViewsVideo(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE VIDEO ID */
        const video_id = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* FIND THE TRIGGER VIEWS NUMBER */
        const target_n_views = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* FIND VIDEO BY ID */
        const response = await axios.get(YOUTUBE_ACTION_CONSTANTS.YOUTUBER_VIDEO_VIEW_URL(video_id), {validateStatus: false});

        /* CHECK IF THE YOUTUBE REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!response.data.items[0]) {
            instance.setState(false);
            return (instance);
        }
        /* GET THE VIDEO VIEWS NUMBER */
        const views = response.data.items[0].statistics.viewCount;

        instance.setVariable('$1$', `${views}`);
        instance.setVariable('$2$', `${response.data.items[0].statistics.likeCount}`);
        instance.setVariable('$3$', `${response.data.items[0].statistics.dislikeCount}`);
        instance.setVariable('$4$', `${response.data.items[0].statistics.commentCount}`);

        /* IF THE VIDEO VIEWS NUMBER IS MORE THAN THE TRIGGER NUMBER RETURN TRUE */
        if (Number(views) >= Number(target_n_views)) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static getYoutubeError(data) {
        return (true);
    }
}

export {Google};
