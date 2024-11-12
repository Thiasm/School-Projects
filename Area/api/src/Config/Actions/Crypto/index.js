//
// AREA PROJECT, 2020
// AREA
// File description:
// Crypto services file
//

import {ActionInterface} from '../interface';
import axios from 'axios';
import {CRYPTO_ACTION_CONSTANTS} from '../../../constants';

class Crypto {
    static async get_price(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* GET ALL THE PARAMETER FOR THE ACTION */
        const crypto_key = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const target_price = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const more_less = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_3$').value;
        /* MAKE THE API CALL */   

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', crypto_key);
        instance.setVariable('$2$', target_price);
        
        const res = await axios.get(CRYPTO_ACTION_CONSTANTS.CRYPTO_PRICE_URL(crypto_key));

        /*  CHECK IF THERE IS A RESPONSE */
        if (res == null) {
            instance.setState(false);
            return (instance);
        }

        /* CHECK IF THE USER WANT THE ACTION TO BE TRIGGERED WHEN THE PRICE IS UNDER THE TARGET PRICE*/
        if (more_less == '-') {
            if (res.data.EUR <= target_price) {
                instance.setState(true);
                return (instance);
            }
        }
        /* CHECK IF THE USER WANT THE ACTION TO BE TRIGGERED WHEN THE PRICE IS ABOVE THE TARGET PRICE*/
        if (more_less == '+') {
            if (res.data.EUR >= target_price) {
                instance.setState(true);
                return (instance);
            }
        }
        instance.setState(false);
        return (instance);
    }

    static async crypto_error(data) {
        return (true);
    }
}

export {Crypto};
