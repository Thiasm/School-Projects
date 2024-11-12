//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Modal
//

import * as React from 'react';
import { addAREA, getAllServices, getAllReactions, getLinks } from '../../api/bridge';
import { LANG } from '../../globals/Traductions';
import { STORAGE } from '../../globals/Constants';
import { ModalReaction } from './ModalReaction';
import PropTypes from 'prop-types';
import Button from '@material-ui/core/Button';
import TextField from '@material-ui/core/TextField';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';
import MenuItem from '@material-ui/core/MenuItem';
import Select from '@material-ui/core/Select';
import { Modal, Typography } from '@material-ui/core';

export class ModalComponent extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            current_service: null,
            current_sub_service: null,
            current_sub_service_parameters: null,
            current_reaction: null,
            current_reaction_parameters: null,
            services: null,
            reactions: null,
            links: null,
            open: true,
            reactions_numbers: 0,
            modal_reactions: [],
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
            ref: [],
            errorMessage: null,
        };
        this.handleUnShow = this.handleUnShow.bind(this);
        this.changeService = this.changeService.bind(this);
        this.changeSubService = this.changeSubService.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
        this.renderService = this.renderService.bind(this);
        this.renderModalReaction = this.renderModalReaction.bind(this);
        this.addReaction = this.addReaction.bind(this);
        this.deleteLastReaction = this.deleteLastReaction.bind(this);
        this.renderInput = this.renderInput.bind(this);
        this.renderVariables = this.renderVariables.bind(this);
    }

    updateModal(error) {
        this.setState({ errorMessage: error });
    }

    async componentDidMount() {
        let services = null;
        let reactions = null;
        let links = null;

        try {
            services = await getAllServices();
            reactions = await getAllReactions();
            links = await getLinks(this.state.USER_UUID);
        } finally {
            this.setState({ services: services.data, reactions: reactions.data, links: links.data });
        }
    }

    handleUnShow(e) {
        e.preventDefault();
        this.props.unShowModal();
    }

    async handleSubmit(e) {
        const elements = document.getElementById('myForm').elements;
        const name_area = elements['name'].value;
        const description = elements['description'].value;

        if (!name_area || !description) {
            this.updateModal('Invalid Name or Description');
            return;
        }
        const _service = this.state.services.find(
            (service) => service.name === this.state.current_service,
        );
        if (!_service) {
            this.updateModal('Invalid Service');
            return;
        }
        const _sub_service = _service.triggers.find(
            (sub_service) => sub_service.name === this.state.current_sub_service,
        );
        if (!_sub_service) {
            this.updateModal('Invalid Sub Service');
            return;
        }

        const result = {
            name: name_area,
            description: description,
            service: {
                service: _service,
                sub_service: _sub_service,
                parameters: [],
            },
            reaction: [],
            user_id: this.state.USER_UUID,
        };

        if (this.state.current_sub_service_parameters != null) {
            for (let i = 0; i < this.state.current_sub_service_parameters.length; i++) {
                result.service.parameters.push({
                    name: this.state.current_sub_service_parameters[i].name,
                    value: elements[this.state.current_sub_service_parameters[i].name].value,
                    parameter_name: this.state.current_sub_service_parameters[i].value,
                });
            }
        }
        for (let i = 0; i < this.state.reactions_numbers; i++) {
            const _reaction = this.state.ref[i];
            if (!_reaction.current.state.current_reaction_array) {
                this.updateModal('Invalid ReAction');
                return;
            }
            const _parameters = _reaction.current.state.current_reaction_array.parameters;
            const _final = [];
            for (let j = 0; j < _parameters.length; j++) {
                _final.push({
                    name: _parameters[j].name,
                    value: elements[_reaction.current.props.key_value.toString() + _parameters[j].name].value,
                    parameter_name: _parameters[j].value,
                });
            }
            result.reaction.push({
                reaction: _reaction.current.state.current_reaction_array,
                parameters: _final,
            });
        }
        addAREA(result)
            .then((result) => result)
            .then((responseJson) => {
                if (responseJson.status == 201) {
                    this.updateModal(responseJson.data);
                } else {
                    this.props.unShowModal();
                }
            });
    }

    renderService() {
        const currentService = this.state.current_service;
        const services = this.state.services;
        const links = this.state.links;

        return (
            <div>
                <DialogContentText>
                    {LANG.MODAL_SUBSCRIBE_SERVICE}
                </DialogContentText>
                <DialogContentText>{LANG.MODAL_SELECT_SERVICE}</DialogContentText>
                <Select
                    margin="dense"
                    value={currentService == null ? '' : currentService}
                    fullWidth
                    onChange={this.changeService}
                >
                    <MenuItem value='null'>
                        <em>None</em>
                    </MenuItem>
                    {services.map(function (service, i) {
                        if (service.depends_on != null) {
                            if (!links.find((_link) => _link.id === service.depends_on.id)) {
                                return (null);
                            }
                        }
                        return (
                            <MenuItem key={service.name} value={service.name}>
                                {service.name}
                            </MenuItem>
                        );
                    })};
                </Select>
            </div>);
    }

    changeService(e) {
        this.updateModal(null);
        this.setState({
            current_service: e.target.value,
            current_sub_service: null,
            current_sub_service_parameters: null,
            current_reaction: null,
            current_reaction_parameters: null,
        });
    }

    renderVariables(sub_service) {
        const _service = this.state.services.find(
            (service) => service.name === this.state.current_service,
        );
        if (!_service) {
            return;
        }
        const _sub_service = _service.triggers.find(
            (_sub_service) => _sub_service.name === sub_service,
        );
        if (!_sub_service) {
            return;
        }
        return (_sub_service.variables.map((_element) => {
            return (<div key={_element.value}>Variable: {_element.value} = {_element.name}</div>);
        }));
    }

    renderSubService() {
        if (this.state.current_service == null || this.state.current_service == 'null') {
            return;
        }
        const current_sub_service = this.state.current_sub_service;
        const services = this.state.services.find((service) => service.name === this.state.current_service);
        const sub_services = services.triggers;

        return (
            <div>
                <br />
                <DialogContentText>Select a sub-service</DialogContentText>
                <Select
                    margin="dense"
                    value={current_sub_service == null ? '' : current_sub_service}
                    fullWidth
                    onChange={this.changeSubService}
                >
                    <MenuItem value='null'>
                        <em>None</em>
                    </MenuItem>
                    {sub_services.map(function (sub_service, i) {
                        return (
                            <MenuItem key={sub_service.name} value={sub_service.name}>
                                {sub_service.name}
                            </MenuItem>
                        );
                    })};
                </Select>
                {current_sub_service == null ? '' : this.renderVariables(current_sub_service)}
            </div>
        );
    }

    changeSubService(e) {
        const sub_service = e.target.value;
        const service = this.state.services.find((service) => service.name === this.state.current_service);
        const trigger = service.triggers.find((_trigger) => _trigger.name === sub_service);

        if (!trigger) {
            return;
        }
        this.setState({
            current_sub_service: e.target.value,
            current_sub_service_parameters: trigger.parameters,
        });
        this.updateModal(null);
    }

    renderInput(parameters) {
        return (
            <div>
                <br />
                <TextField
                    autoFocus
                    id={parameters.name}
                    label={parameters.name}
                    helperText={parameters.description}
                    type="text"
                    fullWidth
                />
            </div>
        );
    }

    renderSubServiceInputs() {
        if (this.state.current_sub_service == null || this.state.current_sub_service == 'null') {
            return;
        }

        const parameters = this.state.current_sub_service_parameters;

        if (parameters == null) {
            return (null);
        }
        return (parameters.map((parameter) =>
            <div key={parameter.name}>{this.renderInput(parameter)}</div>,
        ));
    }

    renderModalReaction() {
        return (this.state.modal_reactions.map((reaction) => {
            return (reaction);
        }));
    }

    addReaction() {
        const { modal_reactions, ref } = this.state;

        const new_ref = React.createRef();
        ref.push(new_ref);
        modal_reactions.push(<ModalReaction ref={new_ref} links={this.state.links} reactions={this.state.reactions} key={this.state.reactions_numbers + 1} key_value={this.state.reactions_numbers + 1} />);
        this.setState({
            reactions_numbers: this.state.reactions_numbers + 1,
            modal_reactions: modal_reactions,
            ref: ref,
        });
    }

    deleteLastReaction() {
        const { modal_reactions, ref } = this.state;

        modal_reactions.pop();
        ref.pop();
        this.setState({
            reactions_numbers: this.state.reactions_numbers - 1,
            modal_reactions: modal_reactions,
            ref: ref,
        });
    }

    render() {
        if (this.state.services == null) {
            return null;
        }
        return (
            <Dialog
                open={true}
                onClose={this.handleUnShow}
                aria-labelledby="form-dialog-title"
            >
                <DialogTitle id="form-dialog-title">{LANG.MODAL_ADD_WIDGET}</DialogTitle>
                <DialogContent>
                    <Typography style={{ color: 'red' }}>
                        {this.state.errorMessage == undefined ? null : this.state.errorMessage}
                    </Typography>
                    <form id="myForm" onSubmit={this.handleSubmit}>
                        <DialogContentText>
                            {LANG.ENTER_NAME_DESC}
                        </DialogContentText>
                        <TextField
                            autoFocus
                            id="name"
                            label={LANG.NAME}
                            type="text"
                            fullWidth
                        />
                        <br />
                        <TextField
                            id="description"
                            label={LANG.DESCRIPTION}
                            type="text"
                            fullWidth
                        />
                        <br />
                        <hr />
                        {this.renderService()}
                        {this.renderSubService()}
                        {this.renderSubServiceInputs()}
                        {this.renderModalReaction()}
                    </form>
                </DialogContent>
                <DialogActions>
                    <Button onClick={this.addReaction}>
                        {LANG.ADD_REACTION}
                    </Button>
                    <Button onClick={this.deleteLastReaction}>
                        {LANG.REMOVE_LAST_REACTION}
                    </Button>
                    <Button onClick={this.handleSubmit}>
                        {LANG.MODAL_ADD}
                    </Button>
                    <Button onClick={this.handleUnShow}>
                        {LANG.MODAL_CANCEL}
                    </Button>
                </DialogActions>
            </Dialog>
        );
    }
}

ModalComponent.propTypes = {
    unShowModal: PropTypes.func,
};
