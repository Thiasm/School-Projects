//
// EPITECH PROJECT, 2020
// AREA
// File description:
// ConfirmEmail
//

import * as React from 'react';
import CircularProgress from '@material-ui/core/CircularProgress';
import PropTypes from 'prop-types';
import { confirmEmailRequest } from '../../api/bridge';

const styles = {
    position: 'fixed',
    top: '50%',
    left: '50%',
    transform: `translate(-50%, -50%)`,
};

export class ConfirmEmail extends React.Component {
    constructor(props) {
        super(props);
    }

    async componentDidMount() {
        const url = window.location.href;
        const code = url.substring(url.indexOf('=') + 1);
        confirmEmailRequest(code).then((res) => {
            if (res.data == 'OK') {
                window.close();
            }
        });
    }

    render() {
        return (
            <div style={styles} >
                <div style={styles}>
                    <CircularProgress />
                </div>
                <div style={{ paddingTop: '50%' }}>
                    Confirming your account
                </div>
            </div>
        );
    }
}

ConfirmEmail.propTypes = {
    location: PropTypes.object,
    history: PropTypes.object,
};
