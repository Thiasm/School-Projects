//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Twitter Controller
//

import {fixedEncodeURIComponent} from '../../utils';
import {TWITTER_AUTHTHENTIFICATION_CONSTANTS} from '../../constants';
const oauth = require('oauth');
const {promisify} = require('util');

const oauthConsumer = new oauth.OAuth(
    TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_AUTH[0], TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_AUTH[1],
    TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_API_KEY,
    TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_API_KEY_SECRET,
    '1.0A', TWITTER_AUTHTHENTIFICATION_CONSTANTS.TWITTER_CALLBACK, 'HMAC-SHA1');

export async function getTwitterOauth() {
    return new Promise((resolve, reject) => {
        oauthConsumer.getOAuthRequestToken(function(error, oauthRequestToken, oauthRequestTokenSecret, results) {
            if (error) {
                console.log(error);
                reject(new Error('Error getting OAuth request token'));
            } else {
                resolve({oauthRequestToken, oauthRequestTokenSecret, results});
            }
        });
    });
}

export async function oauthGetUserById(userId, oauthAccessToken, oauthAccessTokenSecret) {
    return promisify(oauthConsumer.get.bind(oauthConsumer))(`https://api.twitter.com/1.1/users/show.json?user_id=${userId}`, oauthAccessToken, oauthAccessTokenSecret)
        .then((body) => JSON.parse(body));
}

export async function oauthGetUserByName(userId, oauthAccessToken, oauthAccessTokenSecret) {
    return promisify(oauthConsumer.get.bind(oauthConsumer))(`https://api.twitter.com/1.1/users/show.json?screen_name=${userId}`, oauthAccessToken, oauthAccessTokenSecret)
        .then((body) => JSON.parse(body));
}

export async function oauthGetTimeline(userId, oauthAccessToken, oauthAccessTokenSecret) {
    return promisify(oauthConsumer.get.bind(oauthConsumer))(`https://api.twitter.com/1.1/statuses/home_timeline.json`, oauthAccessToken, oauthAccessTokenSecret)
        .then((body) => JSON.parse(body));
}

export async function oauthGetTimelineByUser(userId, oauthAccessToken, oauthAccessTokenSecret) {
    return promisify(oauthConsumer.get.bind(oauthConsumer))(`https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=${userId}&count=3`, oauthAccessToken, oauthAccessTokenSecret)
        .then((body) => JSON.parse(body));
}

export async function oauthPostTweet(tweet, oauthAccessToken, oauthAccessTokenSecret) {
    return promisify(oauthConsumer.post.bind(oauthConsumer))(`https://api.twitter.com/1.1/statuses/update.json?status=${fixedEncodeURIComponent(tweet)}`, oauthAccessToken, oauthAccessTokenSecret, {}, {})
        .then((body) => JSON.parse(body)).catch((err) => console.log(err));
}

export async function getOAuthAccessTokenWith(oauthRequestToken, oauthRequestTokenSecret, oauthVerifier) {
    return new Promise((resolve, reject) => {
        oauthConsumer.getOAuthAccessToken(oauthRequestToken, oauthRequestTokenSecret, oauthVerifier, function(error, oauthAccessToken, oauthAccessTokenSecret, results) {
            return error ? reject(new Error('Error getting OAuth access token')) : resolve({oauthAccessToken, oauthAccessTokenSecret, results});
        });
    });
}
