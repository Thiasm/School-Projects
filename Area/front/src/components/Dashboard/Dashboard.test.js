import React from 'react';
import { render, screen, queryByAttribute } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';
import { Home } from './Dashboard';
import { LANG } from '../../globals/Traductions';
import { createMemoryHistory } from 'history';

test('Render "List of your Areas" Title', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    render(
        <Home history={history} location={location} />,
    );
    const linkElement = screen.getByText(LANG.LIST_OF_YOUR_AREAS);
    expect(linkElement).toBeInTheDocument();
});

test('Render "Add Area" Button', () => {
    const history = createMemoryHistory('/home');
    const location = { search: '' };
    const getById = queryByAttribute.bind(null, 'id');
    const dom = render(
        <Home history={history} location={location} />,
    );
    const linkElement = getById(dom.container, 'addAreaButton');
    expect(linkElement).toBeInTheDocument();
});
