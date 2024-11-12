//
// AREA PROJECT, 2020
// AREA
// File description:
// Google services file
//

import axios from 'axios';
import {ActionInterface} from '../interface';
import {NEWS_AUTHENTIFICATION_CONSTANTS} from '../../../constants';

class News {
    static async getNewsByCategory(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE CATEGORY PARAM */
        const news_category = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* FIND NEWS BY CATEGORY */
        const response = await axios.get(NEWS_AUTHENTIFICATION_CONSTANTS.NEWS_URL_CATEGORY(news_category), {validateStatus: false});

        /* CHECK IF THE NEWS API REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (!response.data.articles[0]) {
            instance.setState(false);
            return (instance);
        }

        /* GET THE NEWS PUBLISHED DATE */
        const newsDate = response.data.articles[0].publishedAt;

        /* GET THE CURRENT DATE AND HOURS */
        const currentDate = new Date();
        currentDate.setTime(currentDate.getTime() - new Date().getTimezoneOffset() * 60 * 1000);

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', `${response.data.articles[0].title}`);
        instance.setVariable('$2$', `${response.data.articles[0].description}`);
        instance.setVariable('$3$', `${response.data.articles[0].author}`);

        /* CHECK IF LAST NEWS WAS POSTED IN THE LAST MINUTE */
        if (Date.parse(currentDate) - Date.parse(newsDate) <= 60000) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async getNewsByKeyword(_data) {
        const instance = new ActionInterface();
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE KEYWORD PARAM */
        const news_keyword = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* GET THE CURRENT DATE AND HOURS */
        const currentDate = new Date();
        currentDate.setTime(currentDate.getTime() - new Date().getTimezoneOffset() * 59 * 1000);

        /* FIND NEWS BY KEYWORD */
        const response = await axios.get(NEWS_AUTHENTIFICATION_CONSTANTS.NEWS_URL_KEYWORD(news_keyword, currentDate.toISOString()), {validateStatus: false});

        /* CHECK IF THE NEWS API REPONSE IS OK OTHERWISE CHANEL DOENST EXISTS OR API IS DOWN */
        if (response.data.articles.length == 0) {
            instance.setState(false);
            return (instance);
        }

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', `${response.data.articles[0].title}`);
        instance.setVariable('$2$', `${response.data.articles[0].description}`);
        instance.setVariable('$3$', `${response.data.articles[0].author}`);

        /* CHECK IF API FIND NEWS POSTED IN THE LAST MINUTE */
        if (response.data.articles[0]) {
            instance.setState(true);
            return (instance);
        }
    }

    static async newsError(data) {
        return (true);
    }
}

export {News};
