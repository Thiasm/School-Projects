//
// EPITECH PROJECT, 2020
// AREA
// File description:
// Modal
//

import * as React from 'react';
import { addAREA, getAllServices, getAllReactions } from '../../api/bridge';
import { LANG } from '../../globals/Traductions';
import { STORAGE } from '../../globals/Constants';
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

export class ModalReaction extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            current_service: null,
            current_sub_service: null,
            current_sub_service_parameters: null,
            current_reaction: null,
            current_reaction_parameters: null,
            current_reaction_array: null,
            services: null,
            reactions: this.props.reactions,
            links: this.props.links,
            USER_MAIL: STORAGE.get(STORAGE.MAIL),
            USER_UUID: STORAGE.get(STORAGE.UUID),
        };
        this.renderReactions = this.renderReactions.bind(this);
        this.renderInputs = this.renderInputs.bind(this);
        this.renderInput = this.renderInput.bind(this);
        this.changeReaction = this.changeReaction.bind(this);
    }

    async componentDidMount() {
    }

    renderReactions() {
        const currentWidget = this.state.current_reaction;
        const reactions = this.state.reactions;
        const links = this.state.links;

        return (
            <div>
                <hr />
                <br />
                <DialogContentText>Select a reaction</DialogContentText>
                <Select
                    margin="dense"
                    value={currentWidget == null ? '' : currentWidget}
                    fullWidth
                    onChange={this.changeReaction}
                >
                    <MenuItem value='null'>
                        <em>None</em>
                    </MenuItem>
                    {reactions.map(function(reaction, i) {
                        if (reaction.depends_on != null) {
                            if (!links.find((_link) => _link.id === reaction.depends_on.id)) {
                                return (null);
                            }
                        }
                        return (
                            <MenuItem key={reaction.name} value={reaction.name}>
                                {reaction.name}
                            </MenuItem>
                        );
                    })}
                </Select>
            </div>
        );
    }

    changeReaction(e) {
        if (e.target.value == 'null') {
            this.setState({ current_reaction: 'null', current_reaction_parameters: null });
            return;
        }
        this.setState({
            current_reaction: e.target.value,
            current_reaction_parameters: this.state.reactions.find((action) => action.name === e.target.value).parameters,
            current_reaction_array: this.state.reactions.find((action) => action.name === e.target.value),
        });
    }

    renderInput(parameters) {
        return (
            <div>
                <br />
                <TextField
                    autoFocus
                    id={this.props.key_value.toString() + parameters.name}
                    label={parameters.name}
                    type="text"
                    fullWidth
                />
            </div>
        );
    }

    renderInputs() {
        if (this.state.current_reaction_parameters == null || this.state.current_reaction == 'null') {
            return;
        }

        return (this.state.current_reaction_parameters.map((parameters) =>
            <div key={this.props.key_value.toString() + parameters.name}>{this.renderInput(parameters)}</div>,
        ));
    }

    render() {
        return (
            <React.Fragment>
                {this.renderReactions()}
                {this.renderInputs()}
            </React.Fragment>
        );
    }
}

ModalReaction.propTypes = {
    unShowModal: PropTypes.func,
    reactions: PropTypes.array,
    links: PropTypes.array,
    key_value: PropTypes.any,
};
