//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Settings
//

import React from 'react';
import PropTypes from 'prop-types';

import { Button, ButtonGroup, Card, CardContent, CardHeader, CircularProgress, Container, Divider, FormControl, Grid, IconButton, Input, InputLabel, Menu, MenuItem, TextField, Typography } from '@material-ui/core';
import AccountCircleIcon from '@material-ui/icons/AccountCircle';
import RefreshIcon from '@material-ui/icons/Refresh';

import { LANG } from '../../globals/Traductions';
import { STORAGE } from '../../globals/Constants';

import { getLinks, getAllOAuthServices, getTimerUser, setTimerUser } from '../../api/bridge';

export class Settings extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            services: null,
            links: null,
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
            URLS: [],
            timer: '',
        };
        this.loadAllLinks = this.loadAllLinks.bind(this);
        this.openNewPopup = this.openNewPopup.bind(this);
        this.onChangeTimer = this.onChangeTimer.bind(this);
        this.getTimer = this.getTimer.bind(this);
        this.sendTimer = this.sendTimer.bind(this);
    }

    async componentDidMount() {
        await this.getTimer();
        await this.loadAllLinks();
    }

    async getTimer() {
        const timer = await getTimerUser(this.state.USER_UUID);
        this.setState({ timer: timer.data.timer });
    }

    async sendTimer() {
        const { USER_UUID, timer } = this.state;
        const res = await setTimerUser(USER_UUID, timer);
    }

    async loadAllLinks() {
        const services = await getAllOAuthServices(this.state.USER_UUID);
        const links = await getLinks(this.state.USER_UUID);

        this.setState({
            services: services.data,
            links: links.data,
        });
    }

    delay(ms) {
        return (new Promise((res) => setTimeout(res, ms)));
    }

    openNewPopup(link) {
        const win = window.open(link, 'popup', 'width=600,height=600');
        win.onunload = async () => {
            await this.delay(2000);
            await this.loadAllLinks();
        };
    }

    renderLinkButton(_service) {
        const _is_linked = this.state.links.find((_link) => _link.id == _service.id);
        if (!_is_linked) {
            return (
                <Button
                    key={_service.name}
                    variant="contained"
                    target="_blank"
                    onClick={() => this.openNewPopup(`https://area.antoncazalet.fr:8080${_service.route}?uuid=` + this.state.USER_UUID)}
                    color='primary'
                    style={{ width: '100%' }}
                >
                    {LANG.CONNECT_WITH} {_service.name}
                </Button>
            );
        } else {
            return (
                <Button
                    key={_service.name}
                    variant="contained"
                    target="_blank"
                    onClick={() => this.openNewPopup(`https://area.antoncazalet.fr:8080/unlink?id=${_service.id}&uuid=` + this.state.USER_UUID)}
                    color='primary'
                    style={{ width: '100%' }}
                >
                    {_service.name} {LANG.LINKED}
                </Button>
            );
        }
    }

    onChangeTimer(e) {
        this.setState({
            timer: e.target.value,
        });
    }

    render() {
        const darkTheme = this.props.darkMode;

        return (
            <React.Fragment>
                <Grid container spacing={1} justify='center' style={{ width: '100%', padding: '12px', margin: 0 }}>
                    <Grid item xs={12}>
                        <Card>
                            <CardHeader title={LANG.ACCOUNT_INFORMATION} />
                            <Divider />
                            <CardContent style={{ display: 'flex' }}>
                                <IconButton disabled>
                                    <AccountCircleIcon style={{ fontSize: 120 }} />
                                </IconButton>
                                <Container>
                                    <FormControl fullWidth>
                                        <InputLabel >{LANG.YOUR_EMAIL_ADDRESS}</InputLabel>
                                        <Input fullWidth disabled id="component-disabled" value={this.state.USER_MAIL || ''} />
                                    </FormControl>
                                    <InputLabel style={{ marginTop: '12px' }}>{this.state.USER_UUID}</InputLabel>
                                </Container>
                            </CardContent>
                        </Card>
                    </Grid>
                    <Grid item xs={12}>
                        <Card>
                            <CardHeader title={LANG.ACCOUNT_LINKS}
                                action={
                                    <IconButton onClick={async () => await this.loadAllLinks()}>
                                        <RefreshIcon />
                                    </IconButton>
                                }
                            />
                            <Divider />
                            <CardContent>
                                {!this.state.services || !this.state.links ?
                                    <Container style={{ textAlign: 'center', marginTop: '50%' }}>
                                        <CircularProgress size={64} />
                                    </Container> :
                                    <Grid container spacing={3} style={{ width: '100%', margin: 0 }}>
                                        {this.state.services.map((service, index) => {
                                            return (
                                                <Grid item key={index} xs={12} sm={6} md={3}>
                                                    {this.renderLinkButton(service)}
                                                </Grid>
                                            );
                                        })}
                                    </Grid>
                                }
                            </CardContent>
                        </Card>
                    </Grid>
                    <Grid item xs={4}>
                        <Button variant="contained" href='/logout' fullWidth>
                            {LANG.LOGOUT}
                        </Button>
                    </Grid>
                </Grid>
            </React.Fragment>
        );
    }
}

Settings.propTypes = {
    darkMode: PropTypes.bool,
};
