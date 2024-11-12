//
// AREA PROJECT, 2020
// AREA
// File description:
// About.json
//

import express from 'express';
import {Services} from '../../Config/Actions';
import {Actions} from '../../Config/Reactions';
const router = new express.Router({mergeParams: true});

router.get('/about.json', async (req, res) => {
    const result = {
        client: {
            host: req.connection.remoteAddress,
        },
        server: {
            current_time: Date.now(),
            services: Services,
            actions: Actions,
        },
    };
    res.header('Content-Type', 'application/json');
    res.send(JSON.stringify(result, null, 4));
});

export {router};
