//
// AREA PROJECT, 2020
// AREA
// File description:
// Outlook
//

import axios from 'axios';
import * as querystring from 'querystring';
import {OFFICE_AUTHTHENTIFICATION_CONSTANTS} from '../../constants';
const MicrosoftGraph = require('@microsoft/microsoft-graph-client');

export class Outlook_Service {
    async getLastMail() {
        const client = MicrosoftGraph.Client.init({
            authProvider: (done) => {
                done(null, this.accessToken);
            },
        });
        const res = await client.api('me/messages')
            .version('beta')
            .get();
        return (res.value[0]);
    }

    sendEmail(address, content) {
        const client = MicrosoftGraph.Client.init({
            authProvider: (done) => {
                done(null, this.accessToken);
            },
        });
        const mail = {
            subject: 'Hello',
            toRecipients: [{
                emailAddress: {
                    address: address,
                },
            }],
            body: {
                content: content,
                contentType: 'text',
            },
        };
        client
            .api('me/sendMail')
            .post({message: mail});
    }

    async setEvent(title, startDate, endDate) {
        const client = MicrosoftGraph.Client.init({
            authProvider: (done) => {
                done(null, this.accessToken);
            },
        });

        const email = await client.api('/me').get().then((res) => {
            return (res.mail);
        });
        const event = {
            subject: title,
            body: {
                contentType: 'HTML',
                content: title,
            },
            start: {
                dateTime: startDate,
                timeZone: 'Europe/Paris',
            },
            end: {
                dateTime: endDate,
                timeZone: 'Europe/Paris',
            },
        };
        client
            .api(`/users/${email}/events`)
            .post(event);
    }

    setAccessToken(accessToken) {
        this.accessToken = accessToken;
    }

    static getAuthorizeURL(uuid) {
        const params = {
            client_id: OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_ID,
            redirect_uri: OFFICE_AUTHTHENTIFICATION_CONSTANTS.REDIRECT_URL,
            response_type: 'code',
            response_mode: 'query',
            scope: OFFICE_AUTHTHENTIFICATION_CONSTANTS.SCOPE,
            state: uuid,
        };
        return (`${OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_AUTHORIZE_URL}?${querystring.stringify(params)}`);
    }

    async getAccessToken(code) {
        const params = {
            code: code,
            redirect_uri: OFFICE_AUTHTHENTIFICATION_CONSTANTS.REDIRECT_URL,
            client_id: OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_ID,
            client_secret: OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_SECRET,
            grant_type: 'authorization_code',
        };
        const response = await axios.post(OFFICE_AUTHTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params));
        const {access_token} = response.data;
        return (access_token);
    }

    async getRawData(code) {
        const params = {
            code: code,
            redirect_uri: OFFICE_AUTHTHENTIFICATION_CONSTANTS.REDIRECT_URL,
            client_id: OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_ID,
            client_secret: OFFICE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_SECRET,
            grant_type: 'authorization_code',
        };
        const response = await axios.post(OFFICE_AUTHTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params));
        const data = response.data;
        return (data);
    }
}
