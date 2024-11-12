import React from 'react';
import { render, screen } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';
import { Settings } from './Settings';
import { LANG } from '../../globals/Traductions';
import { createMemoryHistory } from 'history';

test('Render "Mail" output', () => {
    const darkMode = true;
    render(
        <Settings darkMode={darkMode} />,
    );
    const linkElement = screen.getByText(LANG.YOUR_EMAIL_ADDRESS);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Logout" Button', () => {
    const darkMode = true;
    render(
        <Settings darkMode={darkMode} />,
    );
    const linkElement = screen.getByText(LANG.LOGOUT);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Account informations" Button', () => {
    const darkMode = true;
    render(
        <Settings darkMode={darkMode} />,
    );
    const linkElement = screen.getByText(LANG.ACCOUNT_INFORMATION);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Account links" Button', () => {
    const darkMode = true;
    render(
        <Settings darkMode={darkMode} />,
    );
    const linkElement = screen.getByText(LANG.ACCOUNT_LINKS);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Account parameters" Button', () => {
    const darkMode = true;
    render(
        <Settings darkMode={darkMode} />,
    );
    const linkElement = screen.getByText(LANG.ACCOUNT_PARAMETERS);
    expect(linkElement).toBeInTheDocument();
});
