//
// AREA PROJECT, 2020
// AREA
// File description:
// Index
//

import * as express from 'express';
import {router as register} from './Register';
import {router as login} from './Login';
import {router as area} from './Area';
import {router as auth} from './Auth';
import {router as about} from './About';
import {router as timer} from './Timer';

const router = new express.Router();
import {core} from '../Core';
import {Actions} from '../Config/Reactions';
import {Services} from '../Config/Actions';
import {OAuth} from '../Config/OAuth';

router.get('/', (req, res) => res.send('Welcome to the AREA API !'));

/* LOGIN & REGISTER */
router.post('/register', register);
router.post('/login', login);

/* GET ACTIONS AND REACTIONS LIST */
router.get('/services/get', (req, res) => res.send(Services));
router.get('/actions/get', (req, res) => res.send(Actions));

/* GET MY AREAS // POST AN AREA // DELETE AN AREA // DISABLE/ENABLE AN AREA */
router.post('/area/list', area);
router.post('/area', area);
router.post('/area/delete', area);
router.post('/area/update_enable', area);

/* GET ALL OAUTH AVAILABLES // GET LINKED OAUTH SERVICES // UNLINK A OAUTH SERVICE */
router.get('/auth/default_list', auth);
router.post('/auth/list', auth);
router.get('/unlink', auth);

/* USER TIMER */
router.get('/user/timer', timer);
router.post('/user/timer', timer);

/* ABOUT.JSON */
router.get('/about.json', about);

// Debug
router.get('/debug/triggers', async (req, res) => {
    await core();
    res.send('OK');
});

router.get('*', async (req, res) => {
    const is_auth = OAuth.find((_oauth) => _oauth.route == req.path);
    if (is_auth) {
        return (is_auth.f_auth(req, res));
    }

    const is_callback = OAuth.find((_oauth) => _oauth.callback == req.path);
    if (is_callback) {
        return (is_callback.f_callback(req, res));
    }
    res.send('KO');
});

export {router};
