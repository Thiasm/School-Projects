//
// AREA PROJECT, 2020
// AREA
// File description:
// Index
//

import dotenv from 'dotenv';
import cors from 'cors';
import express from 'express';
import {router as routes} from './Routes';
import * as process from 'process';
import {Services} from './Config/Actions/';
import {Actions} from './Config/Reactions';
import {OAuth} from './Config/OAuth';

require('./Core/index');
const fs = require('fs');
const https = require('https');
const http = require('http');

function countAREA() {
    let services = 0;
    let actions = 0;
    let reactions = 0;

    Services.forEach((_action) => {
        _action.triggers.forEach((_sub) => {
            actions++;
        });
        services++;
    });

    Actions.forEach((_reaction) => {
        reactions++;
    });

    console.log(`Services: ${services}`);
    console.log(`Total actions: ${actions}`);
    console.log(`Total reactions ${reactions}`);
    console.log(`NBA + NBR = ${actions + reactions}`);
}

function verifyActions() {
    for (let i = 0; i != Services.length; i++) {
        const res = Services.filter((_tmp) => _tmp.id == i);
        if (res.length > 1) {
            throw Error('Error in Services. 2 Services have the same ID');
        }
    }
    for (let i = 0; i != Services.length; i++) {
        for (let j = 0; j != Services[i].triggers.length; j++) {
            const res = Services[i].triggers.filter((_tmp) => _tmp.id == j);
            if (res.length > 1) {
                throw Error('Error in Sub services. 2 Sub Services have the same ID');
            }
        }
    }
}

function verifiyReactions() {
    for (let i = 0; i != Actions.length; i++) {
        const res = Actions.filter((_tmp) => _tmp.id == i);
        if (res.length > 1) {
            throw Error('Error in Actions. 2 Actions have the same ID');
        }
    }
}

function verifyOAuth() {
    for (let i = 0; i != OAuth.length; i++) {
        const res = OAuth.filter((_tmp) => _tmp.id == i);
        if (res.length > 1) {
            throw Error('Error in OAuth. 2 OAuth Services have the same ID');
        }
    }

    for (let i = 0; i != OAuth.length; i++) {
        if (OAuth[i].name == undefined || OAuth[i].id == undefined || OAuth[i].route == undefined || OAuth[i].callback == undefined || OAuth[i].f_auth == undefined || OAuth[i].f_callback == undefined) {
            throw Error('Error in OAuth. Missing parameter undefined');
        }
    }
}

dotenv.config();

const app = express();

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({extended: true}));
app.use(routes);

countAREA();
verifyActions();
verifiyReactions();
verifyOAuth();

const privateKey = fs.readFileSync('./certs/privkey1.pem', 'utf8');
const certificate = fs.readFileSync('./certs/cert1.pem', 'utf8');
const ca = fs.readFileSync('./certs/chain1.pem', 'utf8');

const credentials = {
    key: privateKey,
    cert: certificate,
    ca: ca,
};

const httpServer = http.createServer(app);
const httpsServer = https.createServer(credentials, app);

httpServer.listen(4242, () => {
    console.log(`HTTP Server running on port 4242`);
});
httpsServer.listen(process.env.API_PORT, () => {
    console.log(`HTTPS Server running on port ${process.env.API_PORT}`);
});
