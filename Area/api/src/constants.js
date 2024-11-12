//
// AREA PROJECT, 2020
// AREA
// File description:
// Constants file
//

export const ERROR_LOGIN = 'Invalid email or password / Email is not confirmed';
export const ERROR_REGISTER = 'User already exists';
export const ERROR_REGISTER_PASSWORD = 'Password & password confirmation are not the same';

export const SITE = 'http://area.antoncazalet.fr:8081';
export const DEPLOY = 'https://area.antoncazalet.fr:8080';

export const GITLAB_ACTION_CONSTANTS = {
    COMMITS_URL(repo) {
        return (`https://gitlab.com/api/v4/projects/${encodeURIComponent(repo)}/repository/commits`);
    },
    CREATE_REPO_URL: 'https://gitlab.com/api/v4/projects/',
};

export const CRYPTO_ACTION_CONSTANTS = {
    CRYPTO_PRICE_URL(crypto_key) {
        return ('https://min-api.cryptocompare.com/data/price?fsym=' + crypto_key +'&tsyms=EUR')
    }
}

export const WEATHER_ACTION_CONSTANTS = {
    API_KEY: `c46996bad5e0fd76a65209e11d11f6b9`,
    WEATHER_CITY_URL(city) {
        return (`http://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${this.API_KEY}&units=metric`);
    },
};

export const GITLAB_AUTHTHENTIFICATION_CONSTANTS = {
    APP_ID: '2738fc9819e62b48c15a00fd968bb9fd03a10250f78731d4c5722c9f359551b4',
    SECRET: '2f6d510c08c4506cfa4cb427e770b802274cb7c30d2a5df5388f2945eac2b164',
    REDIRECT: `${DEPLOY}/auth/gitlab/callback`,
    GITLAB_AUTH_AUTHORIZE(params) {
        return `https://gitlab.com/oauth/authorize?${params}`;
    },
    TOKEN_URL: 'https://gitlab.com/oauth/token',
};

export const GOOGLE_AUTHTHENTIFICATION_CONSTANTS = {
    GOOGLE_AUTH_CALLBACK_MOBILE_LOGIN(email, uuid) {
        return `http://mobile.area.antoncazalet.fr/login?oauth=google&email=${email}&uuid=${uuid}`;
    },
    GOOGLE_AUTH_CALLBACK_LOGIN(email, uuid) {
        return `${SITE}/login?oauth=google&email=${email}&uuid=${uuid}`;
    },
    API_CLIENT_ID: `172192870859-np2ejd1c2odtojpt838mmln8uv03j8p5.apps.googleusercontent.com`,
    API_CLIENT_SECRET: `t4J2Dsqb0ILyh2omjGdCmxYY`,
    API_AUTHORIZE_URL: `https://accounts.google.com/o/oauth2/v2/auth`,
    REDIRECT_URL: `${DEPLOY}/auth/google/callback`,
    GOOGLE_SCOPE: 'https://www.googleapis.com/auth/drive https://www.googleapis.com/auth/documents https://www.googleapis.com/auth/spreadsheets https://www.googleapis.com/auth/userinfo.profile https://www.googleapis.com/auth/userinfo.email https://mail.google.com/ https://www.googleapis.com/auth/gmail.modify https://www.googleapis.com/auth/gmail.compose https://www.googleapis.com/auth/gmail.send https://www.googleapis.com/auth/calendar https://www.googleapis.com/auth/calendar.events',
    TOKEN_URL: 'https://www.googleapis.com/oauth2/v4/token',
    INFO_URL(accessToken) {
        return `https://www.googleapis.com/oauth2/v1/userinfo?alt=json&access_token=${accessToken}`;
    },
};

export const OFFICE_AUTHTHENTIFICATION_CONSTANTS = {
    API_CLIENT_ID: `8384d537-99ad-4531-b283-053d9ab910ee`,
    API_CLIENT_SECRET: `PTgH2DK_.x.s~lZY85GnMyh8.~c~F5tgfs`,
    API_AUTHORIZE_URL: `https://login.microsoftonline.com/organizations/oauth2/v2.0/authorize`,
    REDIRECT_URL: `${DEPLOY}/auth/outlook/callback`,
    SCOPE: 'https://graph.microsoft.com/Mail.Send https://graph.microsoft.com/User.Read https://graph.microsoft.com/Mail.Send https://graph.microsoft.com/Calendars.ReadWrite https://graph.microsoft.com/Mail.ReadBasic https://graph.microsoft.com/Mail.Read https://graph.microsoft.com/Mail.ReadWrite',
    TOKEN_URL: 'https://login.microsoftonline.com/organizations/oauth2/v2.0/token',
};

export const TWITTER_AUTHTHENTIFICATION_CONSTANTS = {
    TWITTER_AUTHORIZE(requestToken) {
        return `https://api.twitter.com/oauth/authorize?oauth_token=${requestToken}`;
    },
    TWITTER_API_KEY: 'J1sZJeRR5VjiGrfVbNA0f9OrZ',
    TWITTER_API_KEY_SECRET: 'RXxhIO0mjcNUJ73BqQAHP8wKoLSzYeB66XBkrjpc9dBiQTRSsC',
    TWITTER_BEARER: 'AAAAAAAAAAAAAAAAAAAAALY8KAEAAAAAgv3ZPKLRdjcOavPpO8vG0eEEsWA%3D26xfkogeB1c1qgZuowhlrHxFrqt7XsxWDEKXcLD9byxWdQCILh',
    TWITTER_CALLBACK: `${DEPLOY}/auth/twitter/callback`,
    TWITTER_AUTH: [
        'https://twitter.com/oauth/request_token',
        'https://twitter.com/oauth/access_token',
    ],
};

export const DISCORD_REACTION_CONSTANTS = {
    WEBHOOK_NAME: 'AREA',
    WEBHOOK_PIC: 'https://i.ibb.co/vQn9Lkq/B-DEV-500-dashboard-Page-01-Image-0002-removebg-preview.png',
};

export const SMS_OVH_REACTION_CONSTANTS = {
    CONSTRUCTOR: {
        endpoint: 'ovh-eu',
        appKey: 'kEt0mBaYmeHtbp4X',
        appSecret: 'yYCFePxwkRFWKqKd1QxHhL65N7zgBHLh',
        consumerKey: 'mtQeoVFh6Fu3cBEY917Xata0f7A2ZeuP',
    },
    POST_QUERY: '/sms/sms-ca202600-1/jobs/',
    SENDER_NAME: 'AREA',
};

export const YOUTUBE_ACTION_CONSTANTS = {
    API_KEY: `AIzaSyB_PFiFqMH2tXFycg1_YzC6uKhpEOkqPsQ`,
    YOUTUBER_ID_URL(target_youtuber) {
        return (`https://youtube.googleapis.com/youtube/v3/search?part=snippet&type=channel&key=${this.API_KEY}&maxResults=1&order=viewCount&q=${target_youtuber}`);
    },
    YOUTUBER_INFO_URL(target_id) {
        return (`https://youtube.googleapis.com/youtube/v3/channels?part=statistics&key=${this.API_KEY}&id=${target_id}`);
    },
    YOUTUBER_VIDEO_VIEW_URL(target_id) {
        return (`https://youtube.googleapis.com/youtube/v3/videos?part=statistics&key=${this.API_KEY}&id=${target_id}`);
    },
};

export const IMGUR_AUTHENTIFICATION_CONSTANTS = {
    CLIENT_ID: '9b5c6cf1a0805e0',
    CLIENT_SECRET: '8495e2302ac2e8d38b6ff359331492ffa234e743',
    AUTHORIZE_URL(uuid) {
        return (`https://api.imgur.com/oauth2/authorize?client_id=${this.CLIENT_ID}&response_type=code&state=${uuid}`);
    },
    TOKEN_URL: 'https://api.imgur.com/oauth2/token',
};

export const NEWS_AUTHENTIFICATION_CONSTANTS = {
    API_KEY: '7dcf99df9ff149b3a6fcb748db78e2f7',
    NEWS_URL_CATEGORY(target_category) {
        return (`https://newsapi.org/v2/top-headlines?country=fr&apiKey=${this.API_KEY}&category=${target_category}&page=1&pageSize=1`);
    },
    NEWS_URL_KEYWORD(target_keyword, target_date) {
        return (`https://newsapi.org/v2/everything?apiKey=${this.API_KEY}&pageSize=1&sortBy=publishedAt&language=fr&page=1&q=${target_keyword}&from=${target_date}`);
    },
};

export const GITHUB_AUTHTHENTIFICATION_CONSTANTS = {
    CLIENT_ID: '3a31c9a229367f100a6a',
    SECRET_ID: 'f750023cf15422e5cabb5bb83dad86fb50e63f78',
    REDIRECT: `${DEPLOY}/auth/github/callback`,
    GITHUB_AUTH_AUTHORIZE(params) {
        return `https://github.com/login/oauth/authorize?${params}`;
    },
    TOKEN_URL: 'https://github.com/login/oauth/access_token',
    COMMITS_URL(repository) {
        return `https://api.github.com/repos/${repository}/commits`;
    },
    CREATE_REPO_URL: 'https://api.github.com/user/repos',
};

export const COVID_ACTION_CONSTANTS = {
    COVID_COUNTRY_URL(country) {
        return (`https://api.covid19api.com/country/${country}/status/confirmed`);
    },
};

export const STEAM_ACTION_CONSTANTS = {
    ALL_GAMES_URL() {
        return (`http://api.steampowered.com/ISteamApps/GetAppList/v2`);
    },
    NB_PLAYERS_GAME_URL(gameId) {
        return (`https://api.steampowered.com/ISteamUserStats/GetNumberOfCurrentPlayers/v1/?appid=${gameId}`);
    },
};

export const TRELLO_AUTHENTIFICATION_CONSTANTS = {
    requestURL: 'https://trello.com/1/OAuthGetRequestToken',
    accessURL: 'https://trello.com/1/OAuthGetAccessToken',
    authorizeURL: 'https://trello.com/1/OAuthAuthorizeToken',
    appName: 'EpiAREA',
    scope: 'read,write',
    expiration: 'never',
    API_KEY: '7f4227df6384e052d23981e7bde024e4',
    SECRET: '3ab9b9064519473c3411e4986393cf350d5d4eaa07cebcb1920399e9fac5d07b',
    loginCallback: `${DEPLOY}/auth/trello/callback`,
    CREATE_BOARD_URL: 'https://api.trello.com/1/boards/',
    GET_BOARDS_URL: 'https://api.trello.com/1/members/me/boards?',
};
