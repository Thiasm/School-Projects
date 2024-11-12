//
// AREA PROJECT, 2020
// AREA
// File description:
// Database encapsulation
//

import mysql from 'mysql';
import dotenv from 'dotenv';
import * as process from 'process';

dotenv.config();

const pool = mysql.createPool({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    password: process.env.DB_PASSWORD,
    database: process.env.DB_DB,
    port: process.env.DB_PORT,
});

// This code is from https://stackoverflow.com/questions/17015590/node-js-mysql-needing-persistent-connection
const db = {
    query: function(...args) {
        const queryArgs = Array.prototype.slice.call(args);
        const events = [];
        const eventNameIndex = {};

        pool.getConnection(function(err, conn) {
            if (err) {
                console.debug(err);
                if (eventNameIndex.error) {
                    eventNameIndex.error();
                }
            }
            if (conn) {
                const q = conn.query(...queryArgs);
                q.on('end', function() {
                    conn.release();
                });

                events.forEach(function(args) {
                    q.on(...args);
                });
            }
        });

        return {
            on: function(eventName, callback, ...args) {
                events.push(Array.prototype.slice.call(args));
                eventNameIndex[eventName] = callback;
                return this;
            },
        };
    },
};

export {db};
