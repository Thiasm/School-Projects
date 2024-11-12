//
// AREA PROJECT, 2020
// AREA
// File description:
// SMS actions file
//

import {SMS_OVH_REACTION_CONSTANTS} from '../../../constants';

const ovh = require('ovh')(SMS_OVH_REACTION_CONSTANTS.CONSTRUCTOR);

class SMS {
    static async send(_data) {
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* GET THE RECEIVER NUMBER AND THE MESSAGE TO BE SENT */
        const receiver = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const content = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* POST THE QUERY */
        await ovh.request('POST', SMS_OVH_REACTION_CONSTANTS.POST_QUERY, {
            message: content,
            senderForResponse: true,
            sender: SMS_OVH_REACTION_CONSTANTS.SENDER_NAME,
            receivers: [receiver],
        }, function() {});
        return (true);
    }
}

export {SMS};
