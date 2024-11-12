//
// AREA PROJECT, 2020
// AREA
// File description:
// Utils
//

export const GLOBALS = {
    USER_ID: null,
    AREA_ID: null,
    ERROR_CODE: null,
};

export function checkIfURLCorrect(url) {
    const expression = /[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)?/gi;
    const regex = new RegExp(expression);

    if (url.match(regex)) {
        return (true);
    } else {
        return (false);
    }
}

export function fixedEncodeURIComponent(str) {
    return encodeURIComponent(str).replace(/[!'()*]/g, function(c) {
        return '%' + c.charCodeAt(0).toString(16);
    });
}
