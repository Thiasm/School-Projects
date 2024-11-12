//
// AREA PROJECT, 2020
// AREA
// File description:
// Discord actions file
//

import axios from 'axios';
import {checkIfURLCorrect} from '../../../utils';
import {DISCORD_REACTION_CONSTANTS} from '../../../constants';
import * as querystring from 'querystring';

class Discord {
    static async webhook_send(_data) {
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET WEBHOOK AND MESSAGE TO BE POSTED */
        const webhook = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const message = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* CHECK IF THE WEBHOOK URL IS CORRECT */
        const is_ok = checkIfURLCorrect(webhook);

        if (is_ok == false) {
            return (false);
        }

        /* CREATE THE QUERY */
        const params = {
            content: message,
            username: DISCORD_REACTION_CONSTANTS.WEBHOOK_NAME,
            avatar_url: DISCORD_REACTION_CONSTANTS.WEBHOOK_PIC,
        };

        /* POST THE QUERY */
        await axios.post(webhook, querystring.stringify(params), {validateStatus: false});

        return (true);
    }
}

export {Discord};
