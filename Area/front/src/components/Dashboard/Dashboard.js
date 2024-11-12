//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Dashboard
//

import React from 'react';
import PropTypes from 'prop-types';
import { Link } from 'react-router-dom';

import { MuiThemeProvider, Divider, Fab, Card, CardHeader, ListItem, ListItemText, List, CardContent } from '@material-ui/core';
import AddIcon from '@material-ui/icons/Add';

import { ROUTES, STORAGE } from '../../globals/Constants';
import { LANG } from '../../globals/Traductions';

import { getUserAreas } from '../../api/bridge';

import { Header } from './Header';
import { ModalComponent } from './ModalComponent';
import { Settings } from './Settings';

import { loadDarkTheme, provideTheme, setBackgroundDarkTheme, updateTheme } from '../DarkTheme/DarkTheme';

export class Home extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
            widgets: null,
            showAddWidgetModal: false,
            showSettings: false,
            listArea: [],
            DARK_THEME: null,
            open: false,
            listopen: false,
        };
        if (!this.state.USER_MAIL && !this.state.USER_UUID) {
            this.props.history.push(ROUTES.LOGIN);
        }
        this.showModal = this.showModal.bind(this);
        this.unShowModal = this.unShowModal.bind(this);
        this.updateList = this.updateList.bind(this);
        this.showSettings = this.showSettings.bind(this);
        this.renderList = this.renderList.bind(this);
        this.changeTheme = this.changeTheme.bind(this);
        this.showMain = this.showMain.bind(this);
        this.handleClickOpen = this.handleClickOpen.bind(this);
        this.handleClose = this.handleClose.bind(this);
        this.handleClickList = this.handleClickList.bind(this);
        this.handleCloseList = this.handleCloseList.bind(this);
    }

    async componentDidMount() {
        await this.updateList();
        this.setState(loadDarkTheme());
    }

    componentWillUnmount() {
        this.setState = (state, callback) => {
            return;
        };
    }

    async showModal() {
        this.setState({ showAddWidgetModal: true });
        await this.updateList();
    }

    async unShowModal() {
        this.setState({ showAddWidgetModal: false });
        await this.updateList();
    }

    async updateList() {
        const areas = await getUserAreas(this.state.USER_UUID);
        this.setState({ listArea: areas.data });
    }

    showSettings() {
        if (this.state.showSettings == false) {
            this.setState({ showSettings: true });
        } else {
            this.setState({ showSettings: false });
        }
    }

    showMain() {
        this.setState({ showSettings: false });
        this.props.history.push(ROUTES.REDIRECT_HOME);
    }

    changeTheme() {
        this.setState(updateTheme());
    }


    handleClickOpen() {
        this.setState({
            open: true,
        });
    }

    handleClose() {
        this.setState({
            open: false,
        });
    }

    handleClickList(event, name) {
        this.setState({
            listopen: true,
        });
    }

    handleCloseList() {
        this.setState({
            listopen: false,
        });
    }

    renderList() {
        if (this.state.showSettings == false) {
            return (
                <React.Fragment>
                    {this.state.showAddWidgetModal == true &&
                        <ModalComponent unShowModal={this.unShowModal} updateModal={this.updateModal} />
                    }
                    <Card style={{ height: 'calc(100% - 80px)', margin: 8 }}>
                        <CardHeader title={LANG.LIST_OF_YOUR_AREAS} titleTypographyProps={{ variant: 'h4' }} />
                        <Divider />
                        <CardContent style={{ maxHeight: 'calc(100% - 84px)', overflow: 'auto', padding: 0 }}>
                            <List>
                                {this.state.listArea.map((row, index) => {
                                    return (
                                        <React.Fragment key={row.id}>
                                            {index === 0 ? null : <Divider />}
                                            <ListItem key={row.id} button component={Link} to={'/detail?id=' + row.id} >
                                                <ListItemText primary={row.name} secondary={row.description} primaryTypographyProps={{ style: { whiteSpace: 'normal', fontSize: '1.4em' } }} secondaryTypographyProps={{ style: { fontSize: '1em' } }} />
                                            </ListItem>
                                        </React.Fragment>
                                    );
                                })}
                            </List>
                        </CardContent>
                    </Card>
                    <Fab color='primary' id='addAreaButton' onClick={this.showModal} style={{ margin: 0, top: 'auto', right: 20, bottom: 20, left: 'auto', position: 'fixed' }} aria-label="add">
                        <AddIcon />
                    </Fab>
                </React.Fragment>
            );
        } else {
            return (<Settings darkMode={this.state.DARK_THEME} />);
        }
    }

    render() {
        setBackgroundDarkTheme();
        return (
            <MuiThemeProvider theme={provideTheme()}>
                <Header changeTheme={this.changeTheme} darkMode={this.state.DARK_THEME} showSettings={this.showSettings} showMain={this.showMain} />
                {this.renderList()}
            </MuiThemeProvider>
        );
    }
}

Home.propTypes = {
    location: PropTypes.object,
    history: PropTypes.object,
};
