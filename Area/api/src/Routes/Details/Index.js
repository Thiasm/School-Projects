//
// AREA PROJECT, 2020
// AREA
// File description:
// Detail
//

import express from 'express';
import {loginQuery, LOGIN_ENUM} from '../../DatabaseController/Login';
import {error} from '../../error';
const router = new express.Router({mergeParams: true});

router.post('/login', async (req, res) => {
    const {email, password} = req.body;

    const response = await loginQuery(email, password);
    if (response === LOGIN_ENUM.UNKWOWN_ACCOUNT) {
        res.status(201).send(JSON.stringify(error(LOGIN_ENUM.UNKWOWN_ACCOUNT)));
        return;
    }
    res.send(JSON.stringify(response));
});

export {router};
