import { createMuiTheme } from '@material-ui/core';
import { lightBlue } from '@material-ui/core/colors';

export const darkTheme = createMuiTheme({
    palette: {
        type: 'dark',
        primary: {
            main: '#067dda',
        },
        secondary: {
            main: lightBlue[900],
        },
    },
});

export const lightTheme = createMuiTheme({
    palette: {
        type: 'light',
        primary: {
            main: '#067dda',
        },
        secondary: {
            main: lightBlue[900],
        },
    },
});
