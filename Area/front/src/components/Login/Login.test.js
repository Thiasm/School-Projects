import React from 'react';
import { render, screen } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';

import { Login } from './Login';
import { LANG } from '../../globals/Traductions';
import { createMemoryHistory } from 'history';


test('Render "Sign in with Google" button', () => {
    const history = createMemoryHistory('/login');
    const location = { search: '' };
    render(
        <Login history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.SIGN_IN_GOOGLE);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Email Address" button', () => {
    const history = createMemoryHistory('/login');
    const location = { search: '' };
    render(
        <Login history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.EMAIL_ADDRESS);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Password" button', () => {
    const history = createMemoryHistory('/login');
    const location = { search: '' };
    render(
        <Login history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.PASSWORD);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Don\'t have an account ? Sign up" button', () => {
    const history = createMemoryHistory('/login');
    const location = { search: '' };
    render(
        <Login history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.REGISTER_POPUP);
    expect(linkElement).toBeInTheDocument();
});
