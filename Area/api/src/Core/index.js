//
// AREA PROJECT, 2020
// AREA
// File description:
// Core
//

import {getTriggersQuery, getReactionsQuery, getAREAQuery} from '../DatabaseController/AREA';
import {getUsers} from '../DatabaseController/User';
import {Services} from '../Config/Actions';
import {Actions} from '../Config/Reactions';
import {GLOBALS} from '../utils';
import {insertLog} from '../Logs';
const cron = require('node-cron');

const colors = {
    reset: '\x1b[0m',
    red: '\x1b[31m',
    green: '\x1b[32m',
};

export let timers = [];

export async function addUserTimer(i, user) {
    const d = new Date();
    d.setMinutes(d.getMinutes() + user.timer);
    timers.push({
        i: i,
        id: user.uuid,
        initial_timer: user.timer,
        next_timer: d,
        is_launched: false,
    });
}

export async function parseUsersTimers() {
    timers = [];
    const users = await getUsers();

    for (let i = 0; i != users.length; i++) {
        addUserTimer(i, users[i]);
    }
}

parseUsersTimers();

// Cron task that runs every minutes
cron.schedule('* * * * *', async () => {
    /*
    const now = new Date();

    for (let i = 0; i != timers.length; i++) {
        if (now >= timers[i].next_timer) {
            const d = new Date();
            d.setMinutes(d.getMinutes() + timers[i].initial_timer);
            timers[i].next_timer = d;
            timers[i].is_launched = true;
        }
    }
    */
    await core();
});


/*
    This core function will be called every minute (or in debug with the route /debug/trigger)
    to fetch every actions and reactions and check if the triggers are triggered
*/
export async function core() {
    console.log('[Core] Fetching the triggers...');
    /* FETCH ALL THE AREAS / ACTIONS / REACTIONS FROM THE DATABASE */
    const actions = await getTriggersQuery();
    const reactions = await getReactionsQuery();
    const areas = await getAREAQuery();

    /* CHECK IF THERE IS NO ACTIONS */
    if (actions.length == 0 || actions == []) {
        console.log('[Core] No triggers.');
        return;
    }

    /* PARSE EVERY ACTIONS */
    for (let i = 0; i != actions.length; i++) {
        const element = actions[i];

        /* FIND THE AREA FROM THE DATABASE */
        const area = areas.find((_area) => _area.action_id == element.id);

        /* CHECK IF AREA HAS TO BE LAUNCHED FROM TIMER */
        // const _timer_by_area = timers.find((_timer) => _timer.id == area.user_uuid);

        /*
        if (_timer_by_area.is_launched == false) {
            console.log(`[Core] [${_timer_by_area.id}] Next passage is at ${new Date(_timer_by_area.next_timer)}`);
            continue;
        } else {
            timers[_timer_by_area.i].is_launched = false;
        }
        */

        /* SET GLOBALS FOR LOGS */
        GLOBALS.USER_ID = area.user_uuid;
        GLOBALS.AREA_ID = area.id;

        if (area.enabled == false) {
            insertLog(1, 'AREA is disabled');
            console.log(`[Core] AREA ${area.name} is disabled, skipping.`);
            continue;
        }

        /* GET THE ACTION CONFIG FROM THE ACTION FILE */
        const action_config = Services.find((service) => service.id == element.action_id);
        if (!action_config) {
            console.log(`${colors.red}[Core] [Error] Service is not found in the trigger id : ${element.id}${colors.reset}`);
            return;
        }
        /* GET THE SUB ACTION CONFIG FROM THE ACTION FILE */
        const sub_action_config = action_config.triggers.find((sub_service) => sub_service.id == element.sub_action_id);
        if (!sub_action_config) {
            console.log(`${colors.red}[Core] [Error] Sub service is not found in the trigger id : ${element.id}${colors.reset}`);
            return;
        }

        /* CALL THE ACTION FUNCTION */
        /* IT CHECKS IF THE ACTION HAS BEEN TRIGERED */
        /* IF STATE == TRUE, THE ACTION HAS BEEN TRIGERED */
        /* IF STATE == FALSE, THE ACTION HAS NOT BEEN TRIGERED */
        const instance = await sub_action_config.function(element);
        if (instance.state == true) {
            /* GET ALL THE REACTIONS CONFIG FROM THE DATABASE */
            const reaction_link_action = reactions.filter((reaction) => reaction.link_action_reaction == element.id);

            /* PARSE EVERY REACTIONS LINKED TO THE ACTION */
            for (let j = 0; j != reaction_link_action.length; j++) {
                /* GET THE REACTION CONFIG FROM THE REACTIONS FILE */
                const reaction_config = Actions.find((action) => action.id == reaction_link_action[j].reaction_id);
                insertLog(0, 'Action has been trigered');
                console.log(`[Core] [${area.name}] [${action_config.name}] => [${reaction_config.name}] The action has been triggered, calling the action...`);

                /* REPLACE ALL ACTIONS VARIABLES IN REACTIOSN */
                if (sub_action_config.variables != undefined && instance.variables != []) {
                    sub_action_config.variables.forEach((_var) => {
                        reaction_link_action[j].data = reaction_link_action[j].data.replace(_var.value, instance.variables[_var.value]);
                    });
                }
                /* END REPLACE ALL*/

                /* CALL THE REACTION FUNCTION */
                const is_action_done = await reaction_config.function(reaction_link_action[j]);

                /* CHECK IF THE REACTION HAS BEEN EXECUTED PROPERLY */
                if (is_action_done == true) {
                    insertLog(0, 'Reaction output : OK');
                    console.log(`[Core] [${area.name}] [${action_config.name}] => [${reaction_config.name}] The reaction status is ${colors.green}OK${colors.reset}`);
                } else {
                    insertLog(1, 'Reaction output : KO');
                    console.log(`[Core] [${area.name}] [${action_config.name}] => [${reaction_config.name}] ${colors.red}The reaction has encoutered a problem.${colors.reset}`);
                }
            }
        } else {
            insertLog(1, 'Action has not been trigered');
            console.log(`[Core] [${action_config.name}] Action has not been triggered, going next.`);
        }
    };
}
