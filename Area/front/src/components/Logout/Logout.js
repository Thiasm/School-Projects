//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Logout
//

import * as React from 'react';
import { STORAGE } from '../../globals/Constants';
import { Redirect } from 'react-router-dom';

export class Logout extends React.Component {
    constructor(props) {
        super(props);

        const dark = STORAGE.get('DARK_THEME');
        STORAGE.clear();
        STORAGE.set('DARK_THEME', dark);
    }

    render() {
        return (
            <Redirect to="/" />
        );
    }
}
