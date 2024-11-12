//
// AREA PROJECT, 2020
// AREA
// File description:
// MD5 Util
//

import crypto from 'crypto';

const md5 = (data) => {
    return (crypto.createHash('md5').update(data).digest('hex'));
};

export {md5};
