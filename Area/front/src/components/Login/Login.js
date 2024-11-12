//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Login
//

import React from 'react';
import PropTypes from 'prop-types';
import { login } from '../../api/bridge';
import { Link, Button, Container, Grid, TextField, Typography, MuiThemeProvider } from '@material-ui/core';
import { loadDarkTheme, provideTheme, setBackgroundDarkTheme, textTheme } from '../DarkTheme/DarkTheme';
import { LANG } from '../../globals/Traductions';
import { ROUTES, STORAGE } from '../../globals/Constants';
import { isEmailValid } from '../../globals/Email';

export class Login extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            email: '',
            password: '',
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
            GOOGLE_URL: '',
            error: undefined,
            DARK_THEME: false,
        };
        if (this.state.USER_MAIL && this.state.USER_UUID) {
            this.props.history.push(ROUTES.REDIRECT_HOME);
        }
        this.handleSubmit = this.handleSubmit.bind(this);
        this.onMailChange = this.onMailChange.bind(this);
        this.onPasswordChange = this.onPasswordChange.bind(this);
    }

    async componentDidMount() {
        const query = new URLSearchParams(this.props.location.search);
        const method = query.get('oauth');
        if (method != null) {
            if (method == 'google') {
                const email = query.get('email');
                const uuid = query.get('uuid');
                STORAGE.set(STORAGE.MAIL, email);
                STORAGE.set(STORAGE.UUID, uuid);
                this.props.history.push(ROUTES.REDIRECT_HOME);
            }
        }
        this.setState(loadDarkTheme());
    }

    handleSubmit(e) {
        e.preventDefault();
        if (!isEmailValid(this.state.email)) {
            this.setState({ error: LANG.WRONG_EMAIL });
            return;
        }
        login(this.state.email, this.state.password).then((response) => response)
            .then((responseJson) => {
                if (responseJson.status == 200) {
                    STORAGE.set(STORAGE.MAIL, responseJson.data.email);
                    STORAGE.set(STORAGE.UUID, responseJson.data.uuid);
                    this.props.history.push(ROUTES.REDIRECT_HOME);
                } else {
                    this.setState({ error: responseJson.data.error });
                }
            });
    }

    onMailChange(e) {
        this.setState({ email: e.target.value });
    }

    onPasswordChange(e) {
        this.setState({ password: e.target.value });
    }

    render() {
        const query = new URLSearchParams(this.props.location.search);
        const title = (query.get(ROUTES.QUERY_FROM_REGISTER) == 'true' ? LANG.AFTER_REGISTER_MSG : '');
        setBackgroundDarkTheme(this.state.DARK_THEME);

        return (
            <MuiThemeProvider theme={provideTheme(this.state.DARK_THEME)}>
                <Container component="main" maxWidth="xs" style={{ alignItems: 'center', textAlign: 'center' }}>
                    <img className="mb-4" src="https://i.ibb.co/vQn9Lkq/B-DEV-500-dashboard-Page-01-Image-0002-removebg-preview.png" alt="" width="50%" style={{ marginTop: '10%' }} />
                    <Typography style={textTheme(this.state.DARK_THEME)}>{LANG.SIGN_IN}</Typography>
                    <Typography style={textTheme(this.state.DARK_THEME)}>{title}</Typography>
                    <form onSubmit={this.handleSubmit} noValidate>
                        <Typography style={{ color: 'red' }}>
                            {this.state.error == undefined ? null : this.state.error}
                        </Typography>
                        <TextField
                            onChange={this.onMailChange}
                            variant='outlined'
                            margin='normal'
                            required
                            fullWidth
                            id='email'
                            label={LANG.EMAIL_ADDRESS}
                            name='email'
                            autoComplete='email'
                            autoFocus
                            error={(this.state.error == undefined ? false : true)}
                        />
                        <TextField
                            onChange={this.onPasswordChange}
                            variant='outlined'
                            margin='normal'
                            required
                            fullWidth
                            name='password'
                            label={LANG.PASSWORD}
                            type='password'
                            id='password'
                            autoComplete='current-password'
                            error={(this.state.error == undefined ? false : true)}
                        />
                        <Button
                            onClick={this.handleSubmit}
                            type='submit'
                            fullWidth
                            variant='contained'
                            color='primary'
                            style={{ marginTop: '10px' }}
                            size='large'
                        >
                            {LANG.SIGN_IN}
                        </Button>
                    </form>
                    <Link href={`https://area.antoncazalet.fr:8080/auth/google`}>
                        <Button
                            type='submit'
                            variant='contained'
                            color='primary'
                            size='small'
                        >
                            {LANG.SIGN_IN_GOOGLE}
                        </Button>
                    </Link>
                    <Grid container style={{ marginTop: '10px' }}>
                        <Grid item>
                            <Link href={ROUTES.REGISTER} variant="body2">
                                {LANG.REGISTER_POPUP}
                            </Link>
                        </Grid>
                    </Grid>
                </Container>
            </MuiThemeProvider>
        );
    }
}

Login.propTypes = {
    location: PropTypes.object,
    history: PropTypes.object,
};
