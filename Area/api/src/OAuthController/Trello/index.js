//
// AREA PROJECT, 2020
// AREA
// File description:
// Trello controller
//

import {TRELLO_AUTHENTIFICATION_CONSTANTS} from '../../constants';
const OAuth = require('oauth').OAuth;

const oauthClient = new OAuth(TRELLO_AUTHENTIFICATION_CONSTANTS.requestURL, TRELLO_AUTHENTIFICATION_CONSTANTS.accessURL, TRELLO_AUTHENTIFICATION_CONSTANTS.API_KEY, TRELLO_AUTHENTIFICATION_CONSTANTS.SECRET, '1.0A', TRELLO_AUTHENTIFICATION_CONSTANTS.loginCallback, 'HMAC-SHA1');


export async function getImgurToken() {
    return new Promise((resolve, reject) => {
        oauthClient.getOAuthRequestToken(function(error, oauthRequestToken, oauthRequestTokenSecret, results) {
            if (error) {
                reject(new Error('Error getting OAuth request token'));
            } else {
                resolve({oauthRequestToken, oauthRequestTokenSecret, results});
            }
        });
    });
}

export async function getOAuthAccessTokenWith(oauthRequestToken, oauthRequestTokenSecret, oauthVerifier) {
    return new Promise((resolve, reject) => {
        oauthClient.getOAuthAccessToken(oauthRequestToken, oauthRequestTokenSecret, oauthVerifier, function(error, oauthAccessToken, oauthAccessTokenSecret, results) {
            return error ? reject(new Error('Error getting OAuth access token')) : resolve({oauthAccessToken, oauthAccessTokenSecret, results});
        });
    });
}
