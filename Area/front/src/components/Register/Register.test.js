import React from 'react';
import { render, screen } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';

import { Register } from './Register';
import { LANG } from '../../globals/Traductions';
import { createMemoryHistory } from 'history';

/* test('Render "Sign up" button', () => {
    const history = createMemoryHistory('/register');
    const location = {search: ""};
    render(
        <Register history={history} location={location} />
    );
    const linkElement = screen.getByText(LANG.SIGN_UP);
    expect(linkElement).toBeInTheDocument();
});*/

test('Render "Sign up with Google" button', () => {
    const history = createMemoryHistory('/register');
    const location = { search: '' };
    render(
        <Register history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.SIGN_UP_GOOGLE);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Already have an account? Sign in" button', () => {
    const history = createMemoryHistory('/register');
    const location = { search: '' };
    render(
        <Register history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.LOGIN_POPUP);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Email Address"', () => {
    const history = createMemoryHistory('/register');
    const location = { search: '' };
    render(
        <Register history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.EMAIL_ADDRESS);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Password"', () => {
    const history = createMemoryHistory('/register');
    const location = { search: '' };
    render(
        <Register history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.PASSWORD);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Password confirmation"', () => {
    const history = createMemoryHistory('/register');
    const location = { search: '' };
    render(
        <Register history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.PASSWORD_CONFIRMATION);
    expect(linkElement).toBeInTheDocument();
});
