//
// EPITECH PROJECT, 2020
// AREA
// File description:
// DarkTheme
//

import { lightTheme, darkTheme } from './Theme';
import { STORAGE } from '../../globals/Constants';

export function loadDarkTheme() {
    if (STORAGE.get('DARK_THEME') == null) {
        STORAGE.set('DARK_THEME', false);
    } else {
        return ({ DARK_THEME: (STORAGE.get('DARK_THEME') == 'true' ? true : false) });
    }
}

export function setBackgroundDarkTheme() {
    const theme = (STORAGE.get('DARK_THEME') == 'true' ? true : false);
    document.body.style.backgroundColor = theme == true ? '#212121' : '#FFFFFF';
}

export function provideTheme() {
    const theme = (STORAGE.get('DARK_THEME') == 'true' ? true : false);
    return (theme == true ? darkTheme : lightTheme);
}

export function textTheme() {
    const theme = (STORAGE.get('DARK_THEME') == 'true' ? true : false);
    return ({ color: (theme ? '#FFFFFF' : '#212121') });
}

export function updateTheme() {
    const newTheme = (STORAGE.get('DARK_THEME') == 'true' ? true : false);
    let newnewTheme = null;
    if (newTheme == true) {
        newnewTheme = false;
    } else {
        newnewTheme = true;
    }
    STORAGE.set('DARK_THEME', newnewTheme);
    return ({ DARK_THEME: newnewTheme });
}
