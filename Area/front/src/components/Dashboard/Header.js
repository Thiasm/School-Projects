//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Login
//

import * as React from 'react';
import PropTypes from 'prop-types';
import { Link, BrowserRouter } from 'react-router-dom';
import { LANG } from '../../globals/Traductions';
import { STORAGE } from '../../globals/Constants';
import Brightness4Icon from '@material-ui/icons/Brightness4';
import BrightnessHighIcon from '@material-ui/icons/BrightnessHigh';
import SettingsIcon from '@material-ui/icons/Settings';
import { AppBar, Toolbar, Typography, IconButton } from '@material-ui/core';

export class Header extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
        };
        this.changeTheme = this.changeTheme.bind(this);
        this.showSettings = this.showSettings.bind(this);
        this.showMain = this.showMain.bind(this);
    }

    showSettings(e) {
        e.preventDefault();
        this.props.showSettings();
    }

    changeTheme(e) {
        e.preventDefault();
        this.props.changeTheme();
    }

    showMain(e) {
        e.preventDefault();
        this.props.showMain();
    }

    render() {
        return (
            <AppBar position='static' color="default">
                <Toolbar>
                    <BrowserRouter>
                        <Link onClick={this.showMain} to='' style={{ flex: 1, textDecoration: 'none' }}>
                            <Typography variant="h5">
                                AREA
                            </Typography>
                        </Link>
                    </BrowserRouter>
                    <Typography style={{ overflow: 'auto' }}>
                        {LANG.HELLO}{this.state.USER_MAIL}
                    </Typography>
                    <IconButton id="theme" onClick={this.changeTheme}>
                        {this.props.darkMode == false ? <Brightness4Icon /> : <BrightnessHighIcon />}
                    </IconButton>
                    <IconButton id="setting" onClick={this.showSettings}>
                        <SettingsIcon />
                    </IconButton>
                </Toolbar>
            </AppBar >
        );
    }
}

Header.propTypes = {
    changeTheme: PropTypes.func,
    darkMode: PropTypes.bool,
    showSettings: PropTypes.func,
    showMain: PropTypes.func,
};
