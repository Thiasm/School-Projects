//
// AREA PROJECT, 2020
// AREA
// File description:
// Timer services file
//

import {ActionInterface} from '../interface';

class Timer {
    static async time(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET TIME */
        const target_hour = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* SPLIT THE TARGET TIME WITH HOURS AND MINUTES */
        const time = target_hour.split(':');

        /* FIND THE DIFFERENCE BETWEEN NOW AND THE TARGET HOUR */
        const now = new Date();
        const formatted_date = new Date(now.getFullYear(), now.getMonth(), now.getDate(), time[0], time[1], 0, 0);

        /* SET THE VARIABLES FOR THE REACTION */
        instance.setVariable('$1$', `${now.getHours()}h${now.getMinutes()}`);

        /* IF ACTUAL'S TIME IS EQUAL OR SUPERIOR THAN THE TARGET TIME THEN RETURN OK */
        if (now.getTime() >= formatted_date.getTime()) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static async date(_data) {
        const instance = new ActionInterface();
        const {data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET TIME */
        const target_day = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;

        /* SPLIT THE TARGET TIME WITH HOURS AND MINUTES */
        const time = target_day.split('/');

        /* FIND THE DIFFERENCE BETWEEN NOW AND THE TARGET DAY */
        const date = new Date();
        const formatted_date = new Date(time[2], time[1] - 1, time[0], 0, 0, 0, 0);

        /* SET THE VARIABLES FOR THE REACTION */
        instance.setVariable('$1$', `${date.getDate()}/${date.getMonth() + 1}/${date.getFullYear()}`);

        /* IF ACTUAL'S DAY IS EQUAL OR SUPERIOR THAN THE TARGET TIME THEN RETURN OK */
        if (date.getTime() >= formatted_date.getTime()) {
            instance.setState(true);
            return (instance);
        }
        instance.setState(false);
        return (instance);
    }

    static Date_Error(value) {
        const re = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/;

        return (re.test(value));
    }

    static Time_Error(value) {
        const re = /^([0-1]?[0-9]|2[0-3]):[0-5][0-9]$/;

        return (re.test(value));
    }
}

export {Timer};
