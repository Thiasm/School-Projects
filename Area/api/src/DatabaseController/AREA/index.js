//
// AREA PROJECT, 2020
// AREA
// File description:
// AREA Controller
//

import {db} from '../../db';

export async function addAction(data, user_id, action_id, sub_action_id) {
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO actions (data, user_id, action_id, sub_action_id) VALUES (?, ?, ?, ?)', [data, user_id, action_id, sub_action_id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve(result.insertId);
        });
    });
}

export async function addReaction(data, user_id, action_id, reaction_id) {
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO reactions (data, user_id, link_action_reaction, reaction_id) VALUES (?, ?, ?, ?)', [data, user_id, action_id, reaction_id], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve('OK');
        });
    });
}

export async function addAREA(name, description, user_id, action_id) {
    return new Promise(function(resolve, reject) {
        db.query('INSERT INTO areas (user_uuid, name, description, action_id, enabled) VALUES (?, ?, ?, ?, ?)', [user_id, name, description, action_id, true], function(err, result, fields) {
            if (err) {
                console.log(err);
                resolve(null);
            }
            resolve('OK');
        });
    });
}

export async function getTriggersQuery() {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM actions', [], function(err, result, fields) {
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

export async function getReactionsQuery() {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM reactions', [], function(err, result, fields) {
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

export async function getAREAQuery() {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM areas', [], function(err, result, fields) {
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

export async function getActionsFromUser(user_id) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM actions WHERE user_id = ?', [user_id], function(err, result, fields) {
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
export async function getReactionsFromUser(user_id) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM reactions WHERE user_id = ?', [user_id], function(err, result, fields) {
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

export async function getAREAFromUser(user_id) {
    return new Promise(function(resolve, reject) {
        db.query('SELECT * FROM areas WHERE user_uuid = ?', [user_id], function(err, result, fields) {
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

export async function removeAREAFromUser(id, user_id) {
    return new Promise(function(resolve, reject) {
        db.query('DELETE FROM areas WHERE user_uuid = ? AND id = ?', [user_id, id], function(err, result, fields) {
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

export async function removeActionFromUser(id, user_id) {
    return new Promise(function(resolve, reject) {
        db.query('DELETE FROM actions WHERE user_id = ? AND id = ?', [user_id, id], function(err, result, fields) {
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

export async function removeReactionsFromUser(id, user_id) {
    return new Promise(function(resolve, reject) {
        db.query('DELETE FROM reactions WHERE user_id = ? AND link_action_reaction = ?', [user_id, id], function(err, result, fields) {
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

export async function removeReactionStoreFromUser(id, user_id) {
    return new Promise(function(resolve, reject) {
        db.query('DELETE FROM store WHERE user_uuid = ? AND link_action_reaction = ?', [user_id, id], function(err, result, fields) {
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

export async function updateStatusAREAFromUser(id, user_id, state) {
    return new Promise(function(resolve, reject) {
        db.query('UPDATE areas SET enabled = ? WHERE user_uuid = ? AND id = ?', [state, user_id, id], function(err, result, fields) {
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
