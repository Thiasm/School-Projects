//
// AREA PROJECT, 2020
// AREA
// File description:
// OAuth file
//

import {Github_OAuth} from '../Authentification/Github';
import {Gitlab_OAuth} from '../Authentification/Gitlab';
import {Google_OAuth} from '../Authentification/Google';
import {Imgur_OAuth} from '../Authentification/Imgur';
import {Office_OAuth} from '../Authentification/Outlook';
import {Trello_OAuth} from '../Authentification/Trello';
import {Twitter_OAuth} from '../Authentification/Twitter';


export const OAuth = [
    {
        name: 'Office 365',
        id: 1,
        route: '/auth/outlook',
        callback: '/auth/outlook/callback',
        f_auth: Office_OAuth.auth,
        f_callback: Office_OAuth.callback,
    },
    {
        name: 'Twitter',
        id: 2,
        route: '/auth/twitter',
        callback: '/auth/twitter/callback',
        f_auth: Twitter_OAuth.auth,
        f_callback: Twitter_OAuth.callback,
    },
    {
        name: 'Google',
        id: 3,
        route: '/auth/google',
        callback: '/auth/google/callback',
        f_auth: Google_OAuth.auth,
        f_callback: Google_OAuth.callback,
    },
    {
        name: 'Gitlab',
        id: 4,
        route: '/auth/gitlab',
        callback: '/auth/gitlab/callback',
        f_auth: Gitlab_OAuth.auth,
        f_callback: Gitlab_OAuth.callback,
    },
    {
        name: 'Imgur',
        id: 5,
        route: '/auth/imgur',
        callback: '/auth/imgur/callback',
        f_auth: Imgur_OAuth.auth,
        f_callback: Imgur_OAuth.callback,
    },
    {
        name: 'Github',
        id: 6,
        route: '/auth/Github',
        callback: '/auth/github/callback',
        f_auth: Github_OAuth.auth,
        f_callback: Github_OAuth.callback,
    },
    {
        name: 'Trello',
        id: 7,
        route: '/auth/trello',
        callback: '/auth/trello/callback',
        f_auth: Trello_OAuth.auth,
        f_callback: Trello_OAuth.callback,
    },
];

export function findOAuthService(name) {
    return (OAuth.find((_tmp) => _tmp.name === name));
}
