//
// AREA PROJECT, 2020
// AREA
// File description:
// Actions file
//

import {Outlook} from './Outlook';
import {CalendarOffice} from './OfficeCalendar';
import {CalendarGoogle} from './GoogleCalendar';
import {Twitter} from './Twitter';
import {SMS} from './SMS';
import {Google} from './Google';
import {Discord} from './Discord';
import {Imgur} from './Imgur';
import {Github} from './Github';
import {Gitlab} from './Gitlab';
import {Trello} from './Trello';

import {findOAuthService} from '../OAuth';

export const Actions = [
    {
        name: 'Post a message (Discord webhook)',
        description: `A bot send a custom message a discord's channel using webhooks`,
        depends_on: null,
        id: 0,
        function: Discord.webhook_send,
        parameters: [
            {
                name: 'Webhook URL',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Message',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Set an event on the Calendar (Office)',
        description: `User Set an event to a specific date`,
        depends_on: findOAuthService('Office 365'),
        id: 1,
        function: CalendarOffice.setEvent,
        parameters: [
            {
                name: 'Event Name',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Due date',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Send a tweet',
        description: `Send a tweet on your profile`,
        depends_on: findOAuthService('Twitter'),
        id: 2,
        function: Twitter.tweet,
        parameters: [
            {
                name: 'Tweet',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Send a SMS',
        description: `Send a SMS to someone (France only)`,
        depends_on: null,
        id: 3,
        function: SMS.send,
        parameters: [
            {
                name: 'Number',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Content',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Send an email (Google)',
        description: `User sends an email to a specfic address`,
        depends_on: findOAuthService('Google'),
        id: 4,
        function: Google.sendEmail,
        parameters: [
            {
                name: 'Email address',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Email content',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Send an email (Outlook)',
        description: `User sends an email to a specfic address`,
        depends_on: findOAuthService('Office 365'),
        id: 5,
        parameters: [
            {
                name: 'Email address',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Email content',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
        function: Outlook.sendEmail,
        checkError: Outlook.Email_Error,
    },
    {
        name: 'Write to spreadsheet (Google / Sheets / Drive)',
        description: `No desc`,
        depends_on: findOAuthService('Google'),
        id: 6,
        function: Google.write_sheet,
        parameters: [
            {
                name: 'Message',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Write to GDoc (Google / Docs / Drive)',
        description: `No desc`,
        depends_on: findOAuthService('Google'),
        id: 7,
        function: Google.write_doc,
        parameters: [
            {
                name: 'Message',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Set an event on the Calendar (Google)',
        description: `User Set an event to a specific date`,
        depends_on: findOAuthService('Google'),
        id: 8,
        function: CalendarGoogle.setEvent,
        parameters: [
            {
                name: 'Event Name',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Due date',
                value: '$PARAM_2$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Post an image (Imgur)',
        description: `Post an image on your Imgur profile`,
        depends_on: findOAuthService('Imgur'),
        id: 9,
        function: Imgur.postPicture,
        parameters: [
            {
                name: 'Title',
                value: '$PARAM_1$',
                type: 'string',
            },
            {
                name: 'Description',
                value: '$PARAM_2$',
                type: 'string',
            },
            {
                name: 'Link to the image',
                value: '$PARAM_3$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Create repository (Github)',
        description: `Create a repository`,
        depends_on: findOAuthService('Github'),
        id: 10,
        function: Github.createRepository,
        parameters: [
            {
                name: 'Repository name',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Create repository (Gitlab)',
        description: `Create a repository`,
        depends_on: findOAuthService('Gitlab'),
        id: 11,
        function: Gitlab.createRepository,
        parameters: [
            {
                name: 'Repository name',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
    {
        name: 'Create a board (Trello)',
        description: `Create a board`,
        depends_on: findOAuthService('Trello'),
        id: 12,
        function: Trello.createBoard,
        parameters: [
            {
                name: 'Board name',
                value: '$PARAM_1$',
                type: 'string',
            },
        ],
    },
];
