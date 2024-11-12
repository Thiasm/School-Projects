//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Dashboard
//

import React from 'react';
import { MuiThemeProvider, Grid, Card, CardContent, CardHeader, Divider, Typography, IconButton, List, ListItem, Menu, MenuItem, CircularProgress, Container, ListItemText, ListSubheader } from '@material-ui/core';
import MoreVertIcon from '@material-ui/icons/MoreVert';
import { loadDarkTheme, provideTheme, setBackgroundDarkTheme, updateTheme } from '../DarkTheme/DarkTheme';
import { Header } from './Header';
import { STORAGE, ROUTES } from '../../globals/Constants';
import { LANG } from '../../globals/Traductions';
import queryString from 'query-string';
import PropTypes from 'prop-types';
import { getUserAreas, deleteArea, disableAREA } from '../../api/bridge';
import { Settings } from './Settings';

export class Detail extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            currentID: '',
            DARK_THEME: null,
            USER_UUID: STORAGE.get(STORAGE.UUID),
            showSettings: false,
            data: null,
            dropdown_menu: false,
            dropdown_anchorEl: null,
        };
        this.changeTheme = this.changeTheme.bind(this);
        this.showSettings = this.showSettings.bind(this);
        this.showMain = this.showMain.bind(this);
        this.getArea = this.getArea.bind(this);
        this.deleteAREA = this.deleteAREA.bind(this);
        this.toggleDropDownMenu = this.toggleDropDownMenu.bind(this);
        this.closeDropDownMenu = this.closeDropDownMenu.bind(this);
        this.disableAREA = this.disableAREA.bind(this);
    }

    async componentDidMount() {
        const values = queryString.parse(this.props.location.search);
        this.setState({ currentID: values.id });
        this.setState(loadDarkTheme());
        await this.getArea();
    }

    async getArea() {
        const areas = await getUserAreas(this.state.USER_UUID).then((areas) => {
            areas.data.map((row) => {
                if (row.id == this.state.currentID) {
                    this.setState({ data: row });
                    return;
                }
            });
        });
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

    async deleteAREA() {
        this.closeDropDownMenu();
        const { currentID, USER_UUID } = this.state;

        await deleteArea(currentID, USER_UUID);
        this.props.history.push(ROUTES.REDIRECT_HOME);
    }

    toggleDropDownMenu(e) {
        this.setState({ dropdown_anchorEl: e.currentTarget });
    }

    closeDropDownMenu() {
        this.setState({ dropdown_anchorEl: null });
    }

    async disableAREA() {
        this.closeDropDownMenu();
        const { currentID, USER_UUID } = this.state;

        await disableAREA(currentID, USER_UUID);
        const areas = await getUserAreas(this.state.USER_UUID).then((areas) => {
            areas.data.map((row) => {
                if (row.id == this.state.currentID) {
                    this.setState({ data: row });
                    return;
                }
            });
        });
    }

    renderEnabled(enabled) {
        if (enabled == true) {
            return (
                <Typography style={{ marginLeft: '15px', color: 'green' }}>True</Typography>
            );
        } else {
            return (
                <Typography style={{ marginLeft: '15px', color: 'red' }}>False</Typography>
            );
        }
    }

    renderInformation() {
        return (
            <Grid item xs={12} sm={12} md={6}>
                <Card style={{ height: '400px', overflow: 'auto', overflowWrap: 'break-word' }}>
                    <CardHeader title={LANG.AREA_INFORMATIONS} action={
                        <IconButton onClick={this.toggleDropDownMenu}>
                            <MoreVertIcon />
                        </IconButton>
                    }
                    />
                    <Menu
                        id="simple-menu"
                        anchorEl={this.state.dropdown_anchorEl}
                        open={Boolean(this.state.dropdown_anchorEl)}
                        onClose={this.closeDropDownMenu}
                    >
                        <MenuItem onClick={async () => await this.disableAREA()}>{this.state.data.enabled ? 'Disable' : 'Enable'} AREA</MenuItem>
                        <MenuItem onClick={async () => await this.deleteAREA()}>Delete AREA</MenuItem>
                    </Menu>
                    <Divider />
                    <CardContent style={{ overflow: 'auto', padding: 0 }}>
                        <List>
                            <ListItem>
                                <ListItemText
                                    primary={LANG.NAME}
                                    secondary={this.state.data.name}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                            <Divider />
                            <ListItem>
                                <ListItemText
                                    primary={'Enable'}
                                    secondary={this.renderEnabled(this.state.data.enabled)}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                            <Divider />
                            <ListItem>
                                <ListItemText
                                    primary={LANG.DESCRIPTION}
                                    secondary={this.state.data.description}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                        </List>
                    </CardContent>
                </Card>
            </Grid>
        );
    }

    renderAction() {
        const actionData = JSON.parse(this.state.data.action.data);
        return (
            <Grid item xs={12} sm={12} md={6}>
                <Card style={{ height: '400px', overflow: 'auto', overflowWrap: 'break-word' }}>
                    <CardHeader title={LANG.ACTION} />
                    <Divider />
                    <CardContent style={{ overflow: 'auto', padding: 0 }}>
                        <List subheader={<ListSubheader>{LANG.ACTION_INFORMATION}</ListSubheader>}>
                            <ListItem dense>
                                <ListItemText
                                    primary={LANG.SERVICE}
                                    secondary={this.state.data.action_info.name}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                            <ListItem dense>
                                <ListItemText
                                    primary={'Service Action'}
                                    secondary={this.state.data.action_info.triggers[this.state.data.action.sub_action_id].name}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                            <Divider />
                            <ListSubheader>{LANG.ACTION_PARAMETERS}</ListSubheader>
                            {actionData.map((option, index) => (
                                <React.Fragment key={index}>
                                    <ListItem dense>
                                        <ListItemText
                                            primary={option.name}
                                            secondary={option.value}
                                            primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                        />
                                    </ListItem>
                                </React.Fragment>
                            ))}
                        </List>
                    </CardContent>
                </Card>
            </Grid>
        );
    }

    renderReaction(reaction, key) {
        const reactionData = JSON.parse(reaction.data);
        return (
            <Grid key={key} item xs={12} sm={12} md={6}>
                <Card style={{ height: '400px', overflow: 'auto', overflowWrap: 'break-word' }}>
                    <CardHeader title={`${LANG.REACTION} ${this.state.data.reaction_info[key].name}`} />
                    <Divider />
                    <CardContent style={{ overflow: 'auto', padding: 0 }}>
                        <List subheader={<ListSubheader>{LANG.REACTION_INFORMATION}</ListSubheader>}>
                            <ListItem dense>
                                <ListItemText
                                    primary={LANG.SERVICE}
                                    secondary={this.state.data.reaction_info[key].name}
                                    primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                />
                            </ListItem>
                            <Divider />
                            <ListSubheader>{LANG.REACTION_PARAMETERS}</ListSubheader>
                            {reactionData.map((option, index) => (
                                <React.Fragment key={index}>
                                    <ListItem dense>
                                        <ListItemText
                                            primary={option.name}
                                            secondary={option.value}
                                            primaryTypographyProps={{ style: { fontWeight: 'bold' } }}
                                        />
                                    </ListItem>
                                </React.Fragment>
                            ))}
                        </List>
                    </CardContent>
                </Card>
            </Grid>
        );
    }

    renderStat() {
        return (
            <Grid item xs={12} sm={12} md={6}>
                <Card style={{ height: '400px' }}>
                    <CardHeader title={LANG.STATS} />
                    <Divider />
                </Card>
            </Grid>
        );
    }

    renderDetail() {
        if (this.state.showSettings == false) {
            return (
                <Grid container spacing={1} style={{ width: '100%', padding: '12px', margin: 0 }}>
                    {this.renderInformation()}
                    {this.renderAction()}
                    {this.state.data.reactions.map((row, key) => {
                        return this.renderReaction(row, key);
                    })}
                    {/* this.renderStat() */}
                </Grid>
            );
        } else {
            return (<Settings darkMode={this.state.DARK_THEME} />);
        }
    }

    render() {
        setBackgroundDarkTheme();
        if (this.state.data == null) {
            return (
                <Container style={{ textAlign: 'center', marginTop: '50%' }}>
                    <CircularProgress size={64} />
                </Container>
            );
        } else {
            return (
                <MuiThemeProvider theme={provideTheme()}>
                    <Header changeTheme={this.changeTheme} darkMode={this.state.DARK_THEME} showSettings={this.showSettings} showMain={this.showMain} />
                    {this.renderDetail()}
                </MuiThemeProvider>
            );
        }
    }
}

Detail.propTypes = {
    location: PropTypes.object,
    history: PropTypes.object,
};
