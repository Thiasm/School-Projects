//
// AREA PROJECT, 2020
// AREA
// File description:
// Google
//

import {google} from 'googleapis';
import {GOOGLE_AUTHTHENTIFICATION_CONSTANTS} from '../../constants';
import axios from 'axios';
import * as querystring from 'querystring';

const oauth2Client = new google.auth.OAuth2(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_ID, GOOGLE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_SECRET, GOOGLE_AUTHTHENTIFICATION_CONSTANTS.REDIRECT_URL);

export class Google_Service {
    setAccessToken(accessToken) {
        this.accessToken = accessToken;
        oauth2Client.setCredentials({access_token: accessToken});
    }

    static getAuthorizeURL(uuid) {
        if (!uuid) {
            return oauth2Client.generateAuthUrl({
                access_type: 'offline',
                prompt: 'consent',
                scope: GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_SCOPE,
            });
        }
        return oauth2Client.generateAuthUrl({
            access_type: 'offline',
            prompt: 'consent',
            scope: GOOGLE_AUTHTHENTIFICATION_CONSTANTS.GOOGLE_SCOPE,
            state: uuid,
        });
    }

    async getRawData(code) {
        const params = {
            code: code,
            redirect_uri: GOOGLE_AUTHTHENTIFICATION_CONSTANTS.REDIRECT_URL,
            client_id: GOOGLE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_ID,
            client_secret: GOOGLE_AUTHTHENTIFICATION_CONSTANTS.API_CLIENT_SECRET,
            grant_type: 'authorization_code',
        };
        const response = await axios.post(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.TOKEN_URL, querystring.stringify(params));
        const data = response.data;
        return (data);
    }

    async sendEmail(address, content) {
        const messageParts = [
            'From: me',
            'To: ' + address,
            'Content-Type: text/html; charset=utf-8',
            'MIME-Version: 1.0',
            'Subject: Email from AREA',
            '',
            content,
        ];
        const message = messageParts.join('\n');
        const encodedMessage = Buffer.from(message)
            .toString('base64')
            .replace(/\+/g, '-')
            .replace(/\//g, '_')
            .replace(/=+$/, '');
        const gmail = google.gmail('v1');
        await gmail.users.messages.send({
            userId: 'me',
            requestBody: {
                raw: encodedMessage,
            },
            headers: {
                'Authorization': 'Bearer ' + this.accessToken,
            },
        });
    }

    async getDriveFiles() {
        const drive = google.drive('v2');

        const res = await drive.files.list({
            auth: oauth2Client,
        });
        return (res.data.items);
    }

    async writeSheet(id, message) {
        const sheets = google.sheets('v4');

        const request = {
            spreadsheetId: id,
            range: 'A1:A1',
            valueInputOption: 'USER_ENTERED',
            insertDataOption: 'INSERT_ROWS',
            resource: {
                'majorDimension': 'ROWS',
                'values': [[message]],
            },
            auth: oauth2Client,
        };
        try {
            await sheets.spreadsheets.values.append(request);
        } catch (err) {
            if (err.response.status == 404) {
                return (false);
            }
        }
        return (true);
    }

    async createSheet() {
        const sheets = google.sheets('v4');

        const resource = {
            properties: {
                title: 'AREA',
            },
        };
        const res = await sheets.spreadsheets.create({
            auth: oauth2Client,
            resource,
        });
        return (res.data.spreadsheetId);
    }

    async createDoc() {
        const docs = google.docs('v1');

        const res = await docs.documents.create({
            auth: oauth2Client,
            requestBody: {
                title: 'AREA',
            },
        });
        return (res.data.documentId);
    }

    async writeDoc(id, message) {
        const docs = google.docs('v1');

        try {
            await docs.documents.batchUpdate({
                auth: oauth2Client,
                documentId: id,
                requestBody: {
                    requests: [
                        {
                            insertText: {
                                endOfSegmentLocation: {},
                                text: `${message}\n`,
                            },
                        }],
                },
            });
        } catch (err) {
            if (err.response.status == 404) {
                return (false);
            }
        }
        return (true);
    }

    getMailId() {
        return new Promise((resolve, reject) => {
            const gmail = google.gmail('v1');
            gmail.users.messages.list({
                auth: oauth2Client,
                userId: 'me',
                maxResults: 1,
                labelIds: 'INBOX',
            }, (err, response) => {
                if (err) {
                    resolve(null);
                    return;
                }
                if (response.data.messages == undefined) {
                    resolve(null);
                    return;
                }
                const id = response.data.messages[0].id;
                resolve(id);
            });
        });
    }

    async isNewMail() {
        const gmail = google.gmail('v1');
        const id = await this.getMailId(oauth2Client);
        if (id == null) {
            return (null);
        }
        const res = await gmail.users.messages.get({
            'userId': 'me',
            'format': 'full',
            'id': id,
            'headers': {
                'Authorization': 'Bearer ' + this.accessToken,
            },
        });
        return (res.data);
    }

    async getUserInfos() {
        const googleUser = await axios.get(GOOGLE_AUTHTHENTIFICATION_CONSTANTS.INFO_URL(this.accessToken));
        return (googleUser.data);
    }

    async setEvent(title, startDate, endDate) {
        const calendar = google.calendar({version: 'v3', oauth2Client});
        const event = {
            summary: title,
            location: '',
            description: '',
            start: {
                dateTime: startDate,
                timeZone: 'Europe/Paris',
            },
            end: {
                dateTime: endDate,
                timeZone: 'Europe/Paris',
            },
            recurrence: [],
            attendees: [],
            reminders: {
                useDefault: false,
                overrides: [
                    {method: 'email', minutes: 24 * 60},
                    {method: 'popup', minutes: 10},
                ],
            },
        };
        calendar.events.insert(
            {
                auth: oauth2Client,
                calendarId: 'primary',
                resource: event,
            });
    }
}
