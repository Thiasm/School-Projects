//
// AREA PROJECT, 2020
// AREA
// File description:
// Register Controller
//

import {db} from '../../db';
import {md5} from '../../md5';

export async function registerQuery(email, password) {
    return new Promise(function(resolve, reject) {
        const uuid = md5(email);
        db.query('INSERT INTO users (email, password, uuid, verified, timer) VALUES (?, ?, ?, ?, ?)', [email, md5(password), uuid, 0, 1], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve({
                    email: 'null',
                    uuid: 'null',
                });
            }
            resolve({
                email: email,
                uuid: uuid,
            });
        });
    });
}

export async function createNewUserQuery(email) {
    return new Promise(function(resolve, reject) {
        const uuid = md5(email);
        db.query('INSERT INTO users (email, password, uuid, verified, timer) VALUES (?, ?, ?, ?, 1)', [email, null, uuid, 0, 1], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve({
                    email: 'null',
                    uuid: 'null',
                });
            }
            resolve({
                email: email,
                uuid: uuid,
            });
        });
    });
}

export async function getUserByEmail(email) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM users WHERE email = ?', [email], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(false);
            }
            if (!result.length) {
                resolve(false);
            } else {
                resolve(true);
            }
        });
    });
}
