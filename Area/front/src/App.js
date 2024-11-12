//
// EPITECH PROJECT, 2020
// AREA
// File description:
// App
//

import React from 'react';
import {
    BrowserRouter as Router,
    Switch,
    Route,
} from 'react-router-dom';
import { Login } from './components/Login/Login';
import { Register } from './components/Register/Register';
import { Home } from './components/Dashboard/Dashboard';
import { Logout } from './components/Logout/Logout';
import { ConfirmEmail } from './components/ConfirmEmail/ConfirmEmail';
import { Detail } from './components/Dashboard/Detail';

export default class App extends React.Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <Router>
                <Switch>
                    <Route exact path="/" component={Login} />
                    <Route path="/logout" component={Logout} />
                    <Route path="/register" component={Register} />
                    <Route path="/home" component={Home} />
                    <Route path="/detail" component={Detail} />
                    <Route path="/confirm_email" component={ConfirmEmail} />
                    <Route component={Login} />
                </Switch>
            </Router>
        );
    }
}
