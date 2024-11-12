//
// AREA PROJECT, 2020
// AREA
// File description:
// Logs Controller
//

import {db} from '../../db';

export async function addLogs(user_id, area_id, error_code, data) {
    data = JSON.stringify(data);
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO logs (user_id, area_id, error_code, data) VALUES (?, ?, ?, ?)', [user_id, area_id, error_code, data], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve('OK');
        });
    });
}
