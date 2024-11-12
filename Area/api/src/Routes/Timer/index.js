//
// AREA PROJECT, 2020
// AREA
// File description:
// Timer
//

import express from 'express';
import {timers} from '../../Core';
import {getUserByUUID, setTimerByUUID} from '../../DatabaseController/User';

const router = new express.Router({mergeParams: true});

router.get('/user/timer', async (req, res) => {
    const {uuid} = req.query;

    if (!uuid) {
        res.send('KO');
        return;
    }
    const timer = await getUserByUUID(uuid);
    res.send({timer: timer.timer});
});

router.post('/user/timer', async (req, res) => {
    const {uuid} = req.query;
    const {timer} = req.body;

    if (!uuid || !timer) {
        res.send('KO');
        return;
    }

    const nb = parseInt(timer);

    if (isNaN(nb)) {
        res.status(201).send('Timer is not a number');
        return;
    }
    if (nb < 1) {
        res.status(201).send('Timer must be greater than 1 minute');
        return;
    }
    await setTimerByUUID(uuid, timer);
    const find_i = timers.find((_timer) => _timer.id == uuid);
    const d = new Date();
    d.setMinutes(parseInt(d.getMinutes()) + nb);
    timers[find_i.i].initial_timer = timer;
    timers[find_i.i].next_timer = d;
    res.send('OK');
});


export {router};
