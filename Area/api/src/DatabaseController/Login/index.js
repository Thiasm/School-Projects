//
// AREA PROJECT, 2020
// AREA
// File description:
// Login Controller
//

import {db} from '../../db';
import {md5} from '../../md5';

export const LOGIN_ENUM = {
    'UNKNOWN_ERROR': 'Unknown error',
    'UNKWOWN_ACCOUNT': 'Account does not exists',
};

export async function loginQuery(email, password) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM users WHERE email = ? AND password = ?', [email, md5(password)], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(LOGIN_ENUM.UNKNOWN_ERROR);
            }
            if (result.length) {
                resolve({
                    email: result[0].email,
                    uuid: result[0].uuid,
                });
            } else {
                resolve(LOGIN_ENUM.UNKWOWN_ACCOUNT);
            }
        });
    });
}
