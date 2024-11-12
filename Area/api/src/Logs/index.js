//
// AREA PROJECT, 2020
// AREA
// File description:
// Logs encapsulation
//

import {addLogs} from '../DatabaseController/Logs';
import {GLOBALS} from '../utils';

export async function insertLog(error_code, data) {
    const user_id = GLOBALS.USER_ID;
    const area_id = GLOBALS.AREA_ID;

    await addLogs(user_id, area_id, error_code, data);
}
