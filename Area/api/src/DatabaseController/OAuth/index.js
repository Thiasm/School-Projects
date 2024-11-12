//
// AREA PROJECT, 2020
// AREA
// File description:
// OAuth Controller
//

import {db} from '../../db';

export async function insertOAuthData(data, uuid, oauth_id) {
    const does_exist = await getOAuthDataByUUID(uuid, oauth_id);
    if (does_exist != undefined) {
        return new Promise(function(resolve, reject) {
            console.log('User already linked');
            resolve(does_exist);
        });
    }
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO oauth (user_uuid, data, oauth_id) VALUES (?, ?, ?)', [uuid, data, oauth_id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve(result.insertId);
        });
    });
}

export async function getOAuthDataByUUID(user_uuid, oauth_id) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM oauth WHERE user_uuid = ? AND oauth_id = ?', [user_uuid, oauth_id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            if (result.length == 0) {
                resolve(null);
            } else {
                resolve(result[0]);
            }
        });
    });
}

export async function getReactionDataFromStore(reaction_id) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM store WHERE reaction_id = ?', [reaction_id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            if (result.length == 0) {
                resolve(null);
            } else {
                resolve(result[0]);
            }
        });
    });
}

export async function insertReactionDataToStore(user_id, reaction_id, link_id, data) {
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO store (user_uuid, reaction_id, link_action_reaction, data) VALUES (?, ?, ?, ?)', [user_id, reaction_id, link_id, data], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve('OK');
        });
    });
}

export async function getOAuthLinkToUser(user_uuid) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM oauth WHERE user_uuid = ?', [user_uuid], function(err, result, fields) {
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

export async function removeOAuthLinkUser(id, user_id) {
    return new Promise(function(resolve, reject) {
        db.query('DELETE FROM oauth WHERE user_uuid = ? AND oauth_id = ?', [user_id, id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve(result);
        });
    });
}
