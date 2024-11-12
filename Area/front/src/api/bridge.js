//
// EPITECH PROJECT, 2020
// AREA
// File description:
// bridge
//

import * as axios from 'axios';

axios.defaults.baseURL = 'https://' + process.env.REACT_APP_API_HOST + ':' + process.env.REACT_APP_API_PORT;

export async function login(email, password) {
    const response = await axios({
        method: 'post',
        url: '/login',
        data: {
            email: email,
            password: password,
        },
    });
    return (response);
}

export async function register(email, password, confirmPassword) {
    const response = await axios({
        method: 'post',
        url: '/register',
        data: {
            email: email,
            password: password,
            passwordConfirmation: confirmPassword,
        },
    });
    return (response);
}

export async function registerWithGoogle(email, id) {
    const response = await axios({
        method: 'post',
        url: '/registerGoogle',
        data: {
            email: email,
            id: id,
        },
    });
    return (response);
}

export async function getTwitterURL() {
    const response = await axios({
        method: 'get',
        url: '/getTwitterURL',
    });
    return (response);
}

export async function googleLogin(code) {
    const response = await axios({
        method: 'post',
        url: '/google',
        data: {
            code: code,
        },
    });
    return (response);
}

export async function getAllServices() {
    const response = await axios({
        method: 'get',
        url: '/services/get',
    });
    return (response);
}

export async function getAllReactions() {
    const response = await axios({
        method: 'get',
        url: '/actions/get',
    });
    return (response);
}

export async function addAREA(data) {
    const response = await axios({
        method: 'post',
        url: '/area',
        data: data,
    });
    return (response);
}

export async function updateWidget(data) {
    const response = await axios({
        method: 'post',
        url: '/update_widget',
        data: data,
    });
    return (response);
}

export async function getUserAreas(uuid) {
    const response = await axios({
        method: 'post',
        url: '/area/list',
        data: {
            user_id: uuid,
        },
    });
    return (response);
}

export async function deleteWidget(globalId) {
    const response = await axios({
        method: 'get',
        url: `/user/widgets/delete/${globalId}`,
    });
    return (response);
}

export async function callCustomRoute(route, globalId) {
    const response = await axios({
        method: 'post',
        url: route,
        data: {
            globalId: globalId,
        },
    });
    return (response);
}

export async function imgurRequest(data) {
    const response = await axios({
        method: 'post',
        url: '/imgur',
        data: data,
    });
    return (response);
}

export async function twitterRequest(data) {
    const response = await axios({
        method: 'post',
        url: '/twitter',
        data: data,
    });
    return (response);
}

export async function spotifyRequest(data) {
    const response = await axios({
        method: 'post',
        url: '/spotify',
        data: data,
    });
    return (response);
}

export async function imgurIsUserLogged(userId) {
    const response = await axios({
        method: 'post',
        url: '/imgur/user',
        data: {
            userId, userId,
        },
    });
    return (response);
}

export async function confirmEmailRequest(code) {
    const response = await axios({
        method: 'post',
        url: '/confirm_email',
        data: {
            code: code,
        },
    });
    return (response);
}

export async function getLinks(user_id) {
    const response = await axios({
        method: 'post',
        url: '/auth/list',
        data: {
            uuid: user_id,
        },
    });
    return (response);
}

export async function getAllOAuthServices() {
    const response = await axios({
        method: 'get',
        url: '/auth/default_list',
    });
    return (response);
}

export async function getTimerUser(user_uuid) {
    const response = await axios({
        method: 'get',
        url: `/user/timer?uuid=${user_uuid}`,
    });
    return (response);
}

export async function setTimerUser(user_uuid, timer) {
    const response = await axios({
        method: 'post',
        url: `/user/timer?uuid=${user_uuid}`,
        data: {
            timer: timer,
        },
    });
    return (response);
}

export async function deleteArea(area_id, user_uuid) {
    const response = await axios({
        method: 'post',
        url: '/area/delete',
        data: {
            area_id: area_id,
            user_id: user_uuid,
        },
    });
    return (response);
}

export async function disableAREA(area_id, user_uuid) {
    const response = await axios({
        method: 'post',
        url: '/area/update_enable',
        data: {
            area_id: area_id,
            user_id: user_uuid,
        },
    });
    return (response);
}
