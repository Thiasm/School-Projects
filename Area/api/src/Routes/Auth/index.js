//
// AREA PROJECT, 2020
// AREA
// File description:
// Auth linking
//

import express from 'express';
import 'isomorphic-fetch';
import {getOAuthLinkToUser, removeOAuthLinkUser} from '../../DatabaseController/OAuth';
import {OAuth} from '../../Config/OAuth';
const router = new express.Router({mergeParams: true});
import * as path from 'path';

router.get('/auth/default_list', async (req, res) => {
    res.send(OAuth);
});

router.post('/auth/list', async (req, res) => {
    const {uuid} = req.body;

    if (!uuid) {
        res.send('Missing UUID');
        return;
    }
    const response = await getOAuthLinkToUser(uuid);
    const resp = [];

    for (let i = 0; i != response.length; i++) {
        const _service = OAuth.find((_oauth) => _oauth.id === response[i].oauth_id);
        resp.push(_service);
    }
    res.send(resp);
});

router.get('/unlink', async (req, res) => {
    const {id, uuid} = req.query;

    if (!id || !uuid) {
        res.send('Missing id or uuid');
        return;
    }
    const response = await removeOAuthLinkUser(id, uuid);
    if (!response) {
        res.send('null');
    }
    res.sendFile(path.resolve('./public/index.html'));
});

export {router};
