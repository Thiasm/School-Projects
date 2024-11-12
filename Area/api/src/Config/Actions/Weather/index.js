//
// AREA PROJECT, 2020
// AREA
// File description:
// Weather services file
//

import axios from 'axios';
import {ActionInterface} from '../interface';
import {WEATHER_ACTION_CONSTANTS} from '../../../constants';

class Weather {
    static async weather(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE USER TO LISTEN FOR HIS TWEET */
        const weahter_state = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const city = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* GET THE WEATHER RESPONSE */
        const response = await axios.get(WEATHER_ACTION_CONSTANTS.WEATHER_CITY_URL(city), {validateStatus: false});

        /* CHECK IF THE WEATHER REPONSE IS OK OTHERWISE CITY DOENST EXISTS OR API IS DOWN */
        if (!response.data.weather) {
            instance.setState(false);
            return (instance);
        }
        /* VARIABLES FROM WEATHER */
        const weather_state = response.data.weather[0].main;

        /* CHECK IF WEATHER EXISTS */
        if (!weather_state) {
            instance.setState(false);
            return (instance);
        }

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', weather_state);
        instance.setVariable('$2$', city);

        /* IF THE WEATHER STATE IS THE SAME AS USER ENTERED THEN RETURN OK */
        if (weather_state == weahter_state) {
            instance.setState(true);
            return (instance);
        } else {
            instance.setState(false);
            return (instance);
        }
    }

    static async weather_error(Value) {
        return (true);
    }

    static async temperature(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE USER TO LISTEN FOR HIS TWEET */
        const m_temperature = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const comparaison = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const city = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_3$').value;

        /* GET THE WEATHER RESPONSE */
        const response = await axios.get(WEATHER_ACTION_CONSTANTS.WEATHER_CITY_URL(city), {validateStatus: false});

        /* CHECK IF THE WEATHER REPONSE IS OK OTHERWISE CITY DOENST EXISTS OR API IS DOWN */
        if (!response.data.weather) {
            instance.setState(false);
            return (instance);
        }

        /* VARIABLES FROM WEATHER */
        const temperature = response.data.main.temp;

        /* CHECK IF TEMPERATURE EXISTS */
        if (!temperature) {
            instance.setState(false);
            return (instance);
        }

        /* SET THE VARIABLES NAME FOR THE REACTION */
        instance.setVariable('$1$', temperature);
        instance.setVariable('$2$', city);

        if (comparaison == '-') {
            if (temperature <= m_temperature) {
                instance.setState(true);
                return (instance);
            }
        } else if (comparaison == '+') {
            if (response.data.main.temp >= m_temperature) {
                instance.setState(true);
                return (instance);
            }
        }
        instance.setState(false);
        return (instance);
    }

    static async temperature_error(Value) {
        return (true);
    }
}

export {Weather};
