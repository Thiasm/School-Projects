//
// AREA PROJECT, 2020
// AREA
// File description:
// Services file
//

import {Timer} from './Timer';
import {Twitter} from './Twitter';
import {Weather} from './Weather';
import {Google} from './Google';
import {Gitlab} from './Gitlab';
import {Outlook} from './Office365';
import {Steam} from './Steam';
import {Covid} from './Covid';
import {Imgur} from './Imgur';
import {News} from './News';
import {Github} from './Github';
import {Crypto} from './Crypto';
import {Trello} from './Trello';

import {findOAuthService} from '../OAuth';

export const Services = [
    {
        name: 'Timer',
        description: 'This service enable the time possibilities triggers',
        depends_on: null,
        id: 0,
        triggers: [
            {
                name: 'Date',
                description: 'When the given day has come',
                id: 0,
                parameters: [
                    {
                        name: 'Day',
                        description: 'Value of the day d/m/y (ex: "11/03/2000")',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Day',
                        description: 'Value of the day d/m/y (ex: "11/03/2000")',
                        value: '$1$',
                        type: 'string',
                    },
                ],
                function: Timer.date,
                checkError: Timer.Date_Error,
            },
            {
                name: 'Time',
                description: 'When the given time has come',
                id: 1,
                parameters: [
                    {
                        name: 'Time',
                        description: 'Value of the time h:m (ex: "12:31")',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Time',
                        description: 'Value of the day d/m/y (ex: "11/03/2000")',
                        value: '$1$',
                        type: 'string',
                    },
                ],
                function: Timer.time,
                checkError: Timer.Time_Error,
            },
        ],
    },
    {
        name: 'Twitter',
        description: 'This service enable the Twitter possibilities of triggers',
        depends_on: findOAuthService('Twitter'),
        id: 1,
        triggers: [
            {
                name: 'Tweet',
                description: 'When a user post a tweet',
                id: 0,
                parameters: [
                    {
                        name: 'Twitter username',
                        description: 'Username in the following format : @user',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Tweet content',
                        description: 'Tweet content',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Tweet author',
                        description: 'Tweet author',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Tweet date',
                        description: 'Tweet date',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Twitter.tweet,
                checkError: Twitter.tweet_error,
            },
        ],
    },
    {
        name: 'Weather',
        description: 'This service enable the weather possibilities of triggers',
        depends_on: null,
        id: 2,
        triggers: [
            {
                name: 'Weather',
                description: 'when the weather is as the user specified it',
                id: 0,
                parameters: [
                    {
                        name: 'Weather',
                        description: 'Weather (Ex: Rain/Snow/Clear)',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                    {
                        name: 'City',
                        description: 'City (Ex: Paris/London/Tokyo)',
                        value: '$PARAM_2$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Weather state',
                        description: 'Weather state',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'City',
                        description: 'City',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Weather.weather,
                checkError: Weather.weather_error,
            },
            {
                name: 'Temperature',
                description: 'when the temperature is as the user specified it',
                id: 1,
                parameters: [
                    {
                        name: 'Temperature',
                        description: 'Temperature (Ex: 10)',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                    {
                        name: '- or +',
                        description: 'Check if you want to know when its colder or hotter than the temperature',
                        value: '$PARAM_2$',
                        type: 'string',
                        optional: false,
                    },
                    {
                        name: 'City',
                        description: 'City (Ex: Paris/London/Tokyo)',
                        value: '$PARAM_3$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Temperature',
                        description: 'Temperature',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'City',
                        description: 'City',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Weather.temperature,
                checkError: Weather.temperature_error,
            },
        ],
    },
    {
        name: 'Gitlab',
        description: 'This service enable the gitlab possibilities of triggers',
        depends_on: findOAuthService('Gitlab'),
        id: 3,
        triggers: [
            {
                name: 'Commits',
                description: 'When a commits appears on a repo',
                id: 0,
                parameters: [
                    {
                        name: 'Repo',
                        description: 'Repository',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Commit content',
                        description: 'Commit content',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Commit author',
                        description: 'Commit author',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Commit date',
                        description: 'Commit date',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Gitlab.commits,
                checkError: Gitlab.commits_error,
            },
        ],
    },
    {
        name: 'Google',
        description: 'This service enable the Google possibilities of triggers',
        depends_on: findOAuthService('Google'),
        id: 4,
        triggers: [
            {
                name: 'Get mail',
                description: 'When a user receives a mail containing a specific expression',
                id: 0,
                parameters: [
                    {
                        name: 'Expression',
                        description: 'Check if the last mail contains the expression',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: true,
                    },
                ],
                variables: [
                    {
                        name: 'Mail content',
                        description: 'Commit content',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Date',
                        description: 'Date',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Sender',
                        description: 'Sender',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Google.getMails,
                checkError: Google.google_error,
            },
            {
                name: 'Get last modified Google Drive file',
                description: 'When a user modify a file in Google Drive',
                id: 1,
                parameters: null,
                variables: [
                    {
                        name: 'Filename',
                        description: 'Name of the file',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Date',
                        description: 'Date',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Author',
                        description: 'Author',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Google.getDriveLastModifiedFile,
                checkError: Google.google_error,
            },
        ],
    },
    {
        name: 'Office 365',
        description: 'This service triggers a reaction every time the user get a mail',
        depends_on: findOAuthService('Office 365'),
        id: 5,
        triggers: [
            {
                name: 'Received mail with specific word',
                description: 'When a mail is received and has a specific word or sentence',
                id: 0,
                parameters: [
                    {
                        name: 'received specific mail',
                        description: 'any words or sentence',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Mail content',
                        description: 'Commit content',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Date',
                        description: 'Date',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Sender',
                        description: 'Sender',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Outlook.getOfficeMails,
                checkError: Outlook.getmail_error,
            },
        ],
    },
    {
        name: 'Steam',
        description: 'This service enable the steam possibilities of triggers',
        depends_on: null,
        id: 6,
        triggers: [
            {
                name: 'Number of players (more)',
                description: 'When more people play a specific game',
                id: 0,
                parameters: [
                    {
                        name: 'Game name',
                        description: 'The name of the game to check number of players',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of players',
                        description: 'The number of players required to trigger the action',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Game Name',
                        description: 'Game Name',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of players',
                        description: 'Number of players currently ingame',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Steam.checkMorePlayer,
                checkError: Steam.nbPlayerError,
            },
            {
                name: 'Number of players (less)',
                description: 'When less people play a specific game',
                id: 1,
                parameters: [
                    {
                        name: 'Game name',
                        description: 'The name of the game to check number of players',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of players',
                        description: 'The number of players required to trigger the action',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Game Name',
                        description: 'Game Name',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of players',
                        description: 'Number of players currently ingame',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Steam.checkLessPlayer,
                checkError: Steam.nbPlayerError,
            },
        ],
    },
    {
        name: 'Imgur',
        description: 'This service enable the imgur possibilities of triggers',
        depends_on: findOAuthService('Imgur'),
        id: 7,
        triggers: [
            {
                name: 'User post picture',
                description: 'When user post a picture',
                id: 0,
                parameters: [
                    {
                        name: 'User',
                        description: 'The username of the user',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Post title',
                        description: 'Title of the post',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Post date',
                        description: 'Date of the post',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Post user',
                        description: 'User of the post',
                        value: '$3$',
                        type: 'string',
                    },
                    {
                        name: 'Link user',
                        description: 'Link of the post',
                        value: '$4$',
                        type: 'string',
                    },
                ],
                function: Imgur.getUserPicture,
                checkError: Imgur.getUserPictureError,
            },
        ],
    },
    {
        name: 'Youtube',
        description: 'This service triggers a reaction related to Youtube',
        depends_on: null,
        id: 8,
        triggers: [
            {
                name: 'Channel reach number of subscribers',
                description: 'A channel reach a defined number of subscribers',
                id: 0,
                parameters: [
                    {
                        name: 'Channel',
                        description: 'Name of the channel',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Subscribers',
                        description: 'Number of subscribers to reach',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Name',
                        description: 'Chanel Full Name',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Subscribers',
                        description: 'Chanel subscribers number',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Views',
                        description: 'Chanel total views number',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Google.getSubscribers,
                checkError: Google.getYoutubeError,
            },
            {
                name: 'Channel reach number of view',
                description: 'A channel reach a defined number of view',
                id: 1,
                parameters: [
                    {
                        name: 'Channel',
                        description: 'Name of the channel',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Views',
                        description: 'Number of views to reach',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Name',
                        description: 'Chanel Full Name',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Subscribers',
                        description: 'Chanel subscribers number',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Views',
                        description: 'Chanel total views number',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Google.getViews,
                checkError: Google.getYoutubeError,
            },
            {
                name: 'Video reach number of view',
                description: 'A Video reach a defined number of view',
                id: 2,
                parameters: [
                    {
                        name: 'Video ID',
                        description: 'ID of the video (this can be found in the video\'s url)',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Views',
                        description: 'Number of views to reach',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Views',
                        description: 'Video\'s views',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Likes',
                        description: 'Video\'s likes',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Dislikes',
                        description: 'Video\'s views',
                        value: '$3$',
                        type: 'string',
                    },
                    {
                        name: 'Comments Count',
                        description: 'Video\'s comments count',
                        value: '$4$',
                        type: 'string',
                    },
                ],
                function: Google.getViewsVideo,
                checkError: Google.getYoutubeError,
            },
        ],
    },
    {
        name: 'News',
        description: 'This service enable the News possibilities of triggers',
        depends_on: null,
        id: 9,
        triggers: [
            {
                name: 'Get Last Trend News by category',
                description: 'The next published Trend News with this category will trigger',
                id: 0,
                parameters: [
                    {
                        name: 'Category',
                        description: 'Select a category: business, entertainment, general, health, science, sports, technology',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Title',
                        description: 'Title of the news',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Description',
                        description: 'Description of the news',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Author',
                        description: 'Author of the news',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: News.getNewsByCategory,
                checkError: News.newsError,
            },
            {
                name: 'Get Last News by Keyword',
                description: 'The next published news with this keyword will trigger',
                id: 1,
                parameters: [
                    {
                        name: 'Keyword',
                        description: 'Select a Keyword, you can use the AND/OR/NOT, and group these with parenthesis. Ex: crypto AND (ethereum OR litecoin) NOT bitcoin.',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Title',
                        description: 'Title of the news',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Description',
                        description: 'Description of the news',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Author',
                        description: 'Author of the news',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: News.getNewsByKeyword,
                checkError: News.newsError,
            },
        ],
    },
    {
        name: 'Github',
        description: 'This service enable the github possibilities of triggers',
        depends_on: findOAuthService('Github'),
        id: 10,
        triggers: [
            {
                name: 'Commits',
                description: 'When a commits appears on a repo',
                id: 0,
                parameters: [
                    {
                        name: 'Repo',
                        description: 'Repository',
                        value: '$PARAM_1$',
                        type: 'string',
                        optional: false,
                    },
                ],
                variables: [
                    {
                        name: 'Commit content',
                        description: 'Commit content',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Commit author',
                        description: 'Commit author',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'Commit date',
                        description: 'Commit date',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Github.commits,
                checkError: Github.commits_error,
            },
        ],
    },
    {
        name: 'Covid',
        description: 'This service enable the covid possibilities of triggers',
        depends_on: null,
        id: 11,
        triggers: [
            {
                name: 'Number of cases',
                description: 'When a specific number of people are contaminated',
                id: 0,
                parameters: [
                    {
                        name: 'Country name',
                        description: 'The name of the country to check number of cases',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of cases',
                        description: 'The number of cases required to trigger the action',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Country name',
                        description: 'Name of the country',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Number of cases',
                        description: 'The number of cases in the country since the beginning of the pandemic',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Covid.checkNbCases,
                checkError: Covid.nbCasesError,
            },
        ],
    },
    {
        name: 'Crypto',
        description: 'This service enable the crypto possibilities of triggers',
        depends_on: null,
        id: 12,
        triggers: [
            {
                name: 'Price of a crypto',
                description: 'is triger when the specified crypto get under or above a specified price',
                id: 0,
                parameters: [
                    {
                        name: 'Crypto Key',
                        description: 'The key of the crypto to check price, example: BTC, DOGE, XPR',
                        value: '$PARAM_1$',
                        type: 'string',
                    },
                    {
                        name: 'Price',
                        description: 'The price required to trigger the action',
                        value: '$PARAM_2$',
                        type: 'string',
                    },
                    {
                        name: '+ or -',
                        description: '+ or -',
                        value: '$PARAM_3$',
                        type: 'string',
                    },
                ],
                variables: [
                    {
                        name: 'Crypto key',
                        description: 'Sender',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'price',
                        description: 'Sender',
                        value: '$2$',
                        type: 'string',
                    },
                ],
                function: Crypto.get_price,
                checkError: Crypto.crypto_error,
            },
        ],
    },
    {
        name: 'Trello',
        description: 'This service enable the trello possibilities of triggers',
        depends_on: findOAuthService('Trello'),
        id: 13,
        triggers: [
            {
                name: 'Get last board updated',
                description: 'is triger when the one of your boards is updated',
                id: 0,
                parameters: null,
                variables: [
                    {
                        name: 'Name',
                        description: 'The board name',
                        value: '$1$',
                        type: 'string',
                    },
                    {
                        name: 'Date',
                        description: 'Date of the last update',
                        value: '$2$',
                        type: 'string',
                    },
                    {
                        name: 'URL',
                        description: 'URL of the board',
                        value: '$3$',
                        type: 'string',
                    },
                ],
                function: Trello.getLastUpdatedBoard,
                checkError: Trello.getLastUpdatedBoardError,
            },
        ],
    },
];
