//
// AREA PROJECT, 2020
// AREA
// File description:
// Register
//

import express from 'express';
import { addUserTimer, timers } from '../../Core';
import {registerQuery} from '../../DatabaseController/Register';
import {checkUserExistsQuery, getUserByUUID, USER_EXISTS_ENUM} from '../../DatabaseController/User/';
import {error} from '../../error';
const router = new express.Router({mergeParams: true});

export const ERROR = {
    'PASSWORD_NOT_CONFIRMED': 'Password and password confirmation are not the same',
};

router.post('/register', async (req, res) => {
    const {email, password, passwordConfirmation} = req.body;

    if (password != passwordConfirmation) {
        res.status(201).send(JSON.stringify(error(ERROR.PASSWORD_NOT_CONFIRMED)));
        return;
    }
    const doesUserExist = await checkUserExistsQuery(email);
    if (doesUserExist == USER_EXISTS_ENUM.EXISTS) {
        res.status(201).send(JSON.stringify(error(USER_EXISTS_ENUM.EXISTS)));
        return;
    }
    const response = await registerQuery(email, password);
    const user = await getUserByUUID(response.uuid);
    await addUserTimer(timers.length, user);
    res.send(JSON.stringify(response));
});

export {router};
