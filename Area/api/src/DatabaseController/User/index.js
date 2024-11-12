//
// AREA PROJECT, 2020
// AREA
// File description:
// Register Controller
//

import {db} from '../../db';

export const USER_EXISTS_ENUM = {
    'DOES_NOT_EXITS': 'User does not exists',
    'EXISTS': 'User exists',
    'UNKNOWN_ERROR': 'Unknown error',
};

export async function checkUserExistsQuery(email) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM users WHERE email = ?', [email], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(USER_EXISTS_ENUM.UNKNOWN_ERROR);
            }
            if (result.length) {
                resolve(USER_EXISTS_ENUM.EXISTS);
            } else {
                resolve(USER_EXISTS_ENUM.DOES_NOT_EXITS);
            }
        });
    });
}

export async function getUserByUUID(uuid) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM users WHERE uuid = ?', [uuid], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve([]);
            }
            resolve(result[0]);
        });
    });
}

export async function setTimerByUUID(uuid, timer) {
    return new Promise(function(resolve, reject) {
        db.query('UPDATE users SET timer = ? WHERE uuid = ?', [timer, uuid], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve('KO');
            }
            resolve('OK');
        });
    });
}

export async function getUsers() {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM users', function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve([]);
            }
            if (result.length) {
                resolve(result);
            } else {
                resolve([]);
            }
        });
    });
}
