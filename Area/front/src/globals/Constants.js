//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Constants
//

import { addToLocalStorage, getValueFromLocalStorage, clearLocalStorage } from '../controller/localStorage';

export const ROUTES = {
    DETAIL: `/detail`,
    REDIRECT_HOME: `/home`,
    REGISTER: `/register`,
    QUERY_FROM_REGISTER: `fromRegister`,
    REGISTER_OK: `/?fromRegister=true`,
    LOGIN: '/',
};

export const STORAGE = {
    MAIL: `USER_MAIL`,
    UUID: `USER_UUID`,
    set(type, value) {
        addToLocalStorage(type, value);
    },
    get(type) {
        return (getValueFromLocalStorage(type));
    },
    clear() {
        clearLocalStorage();
    },
    remove(type) {
        localStorage.removeItem(type);
    },
};
