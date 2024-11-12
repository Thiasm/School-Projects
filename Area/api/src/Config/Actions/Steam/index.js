//
// AREA PROJECT, 2020
// AREA
// File description:
// Steam services file
//

import axios from 'axios';
import {ActionInterface} from '../interface';
import {STEAM_ACTION_CONSTANTS} from '../../../constants';

class Steam {
    static async getPlayerCount(gameName) {
        /* STEAM API CALL TO GET ALL GAMES */
        const allGamesRes = await axios.get(STEAM_ACTION_CONSTANTS.ALL_GAMES_URL());
        const allGames = allGamesRes.data.applist.apps;

        /* FILTER GAMES TO FIND THE ONE SPECIFIED IN THE ACTION */
        const game = allGames.filter((item) => {
            return (item.name === gameName);
        });
        if (game.length == 0) {
            return (0);
        }

        /* STEAM API CALL TO GET NUMBER OF PLAYERS */
        const res = await axios.get(STEAM_ACTION_CONSTANTS.NB_PLAYERS_GAME_URL(game[0].appid));
        const nb = res.data.response.player_count;
        return (nb);
    }

    static async checkMorePlayer(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);
        const gameName = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const playerCount = await Steam.getPlayerCount(gameName);
        const nbParamStr = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const nbParam = parseInt(nbParamStr);

        /* SET OF INSTANCE VARIABLES */
        instance.setVariable('$1$', gameName);
        instance.setVariable('$2$', playerCount.toString());

        /* COMPARISON BETWEEN CURRENT NUMBER OF PLAYERS AND THE TRIGGER */
        if (playerCount >= nbParam) {
            instance.setState(true);
        } else {
            instance.setState(false);
        }
        return (instance);
    }

    static async checkLessPlayer(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);
        const gameName = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const playerCount = await Steam.getPlayerCount(gameName);
        const nbParamStr = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const nbParam = parseInt(nbParamStr);

        /* SET OF INSTANCE VARIABLES */
        instance.setVariable('$1$', gameName);
        instance.setVariable('$2$', playerCount.toString());

        /* COMPARISON BETWEEN CURRENT NUMBER OF PLAYERS AND THE TRIGGER */
        if (playerCount <= nbParam) {
            instance.setState(true);
        } else {
            instance.setState(false);
        }
        return (instance);
    }

    static async nbPlayerError(data) {
        return (true);
    }
}

export {Steam};
