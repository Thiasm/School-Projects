//
// AREA PROJECT, 2020
// AREA
// File description:
// Area
//

import express from 'express';
import {addAction, addReaction, getActionsFromUser, addAREA, getReactionsFromUser, getAREAFromUser, removeAREAFromUser, removeActionFromUser, removeReactionsFromUser, removeReactionStoreFromUser, updateStatusAREAFromUser} from '../../DatabaseController/AREA';
import {Actions as ReactionsList} from '../../Config/Reactions';
import {Services as ActionsList} from '../../Config/Actions';
const router = new express.Router({mergeParams: true});

router.post('/area', async (req, res) => {
    const {name, description, service, reaction, user_id} = req.body;

    if (!service || !reaction[0]) {
        res.status(201).send(JSON.stringify('Request is not complete'));
        return;
    }

    const action_id = await addAction(JSON.stringify(service.parameters), user_id, service.service.id, service.sub_service.id);
    await addAREA(name, description, user_id, action_id);
    for (let i = 0; i != reaction.length; i++) {
        await addReaction(JSON.stringify(reaction[i].parameters), user_id, action_id, reaction[i].reaction.id);
    }
    res.send('OK');
});


router.post('/area/list', async (req, res) => {
    const {user_id} = req.body;

    if (!user_id) {
        res.status(201).send(JSON.stringify('Request is not complete'));
        return;
    }
    const areas = await getAREAFromUser(user_id);
    const actions = await getActionsFromUser(user_id);
    const reactions = await getReactionsFromUser(user_id);

    const response = [];
    areas.forEach((element) => {
        const action_id = element.action_id;
        const _action = actions.find((_tmp) => _tmp.id === action_id);
        const _reactions = reactions.filter((_tmp) => _tmp.link_action_reaction === action_id);
        const _action_info = ActionsList.find((_a) => _a.id === _action.action_id);
        const _reaction_info = [];

        _reactions.forEach((_elem) => {
            _reaction_info.push(ReactionsList.find((_r) => _r.id == _elem.reaction_id));
        });

        response.push({
            name: element.name,
            description: element.description,
            id: element.id,
            enabled: element.enabled,
            action_info: _action_info,
            reaction_info: _reaction_info,
            action: _action,
            reactions: _reactions,
        });
    });
    res.send(response);
});

router.post('/area/delete', async (req, res) => {
    const {area_id, user_id} = req.body;

    if (!user_id || !area_id) {
        res.status(201).send(JSON.stringify('Request is not complete'));
        return;
    }
    const areas = await getAREAFromUser(user_id);
    const actions = await getActionsFromUser(user_id);
    const reactions = await getReactionsFromUser(user_id);

    const _area_to_delete = areas.find((_test) => _test.id === Number(area_id));
    const _action_to_delete = actions.find((_tmp) => _tmp.id === _area_to_delete.action_id);
    const _reactions_to_delete = reactions.filter((_tmp) => _tmp.link_action_reaction === _area_to_delete.action_id);

    if (!_area_to_delete || !_action_to_delete || !_reactions_to_delete) {
        res.send('KO');
        return;
    }
    await removeAREAFromUser(_area_to_delete.id, user_id);
    await removeActionFromUser(_area_to_delete.action_id, user_id);
    await removeReactionsFromUser(_area_to_delete.action_id, user_id);
    await removeReactionStoreFromUser(_area_to_delete.action_id, user_id);
    res.send('OK');
});

router.post('/area/update_enable', async (req, res) => {
    const {area_id, user_id} = req.body;

    if (!user_id || !area_id) {
        res.status(201).send(JSON.stringify('Request is not complete'));
        return;
    }
    const areas = await getAREAFromUser(user_id);

    const area = areas.find((_tmp) => _tmp.id === Number(area_id));

    if (!area) {
        res.send('KO');
        return;
    }
    await updateStatusAREAFromUser(area.id, user_id, !area.enabled);
    res.send('OK');
});

export {router};
