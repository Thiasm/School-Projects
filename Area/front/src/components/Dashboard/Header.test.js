import React from 'react';
import { render, screen, queryByAttribute } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';

import { Header } from './Header';
import { LANG } from '../../globals/Traductions';
import { createMemoryHistory } from 'history';

test('Render "AREA"', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    render(
        <Header history={history} location={location} />,
    );
    const linkElement = screen.getByText(/^AREA$/i);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Hello"', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    render(
        <Header history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.HELLO_NOSPACE);
    expect(linkElement).toBeInTheDocument();
});

test('Render Theme button', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    const getById = queryByAttribute.bind(null, 'id');
    const dom = render(
        <Header history={history} location={location} />,
    );
    const linkElement = getById(dom.container, 'theme');
    expect(linkElement).toBeInTheDocument();
});

test('Render Setting button', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    const getById = queryByAttribute.bind(null, 'id');
    const dom = render(
        <Header history={history} location={location} />,
    );
    const linkElement = getById(dom.container, 'setting');
    expect(linkElement).toBeInTheDocument();
});
