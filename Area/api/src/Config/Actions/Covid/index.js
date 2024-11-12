//
// AREA PROJECT, 2020
// AREA
// File description:
// Covid services file
//

import axios from 'axios';
import {ActionInterface} from '../interface';
import {COVID_ACTION_CONSTANTS} from '../../../constants';

class Covid {
    static async getCasesCount(countryName) {
        var checkError = false;

        /* API CALL TO GET NUMBER OF CASES IN THE COUNTRY SINCE THE BEGINNING OF THE PANDEMIC */
        const countryStats = await axios.get(COVID_ACTION_CONSTANTS.COVID_COUNTRY_URL(countryName)).catch(
            function (error) {
                checkError = true;
            }
        );
        if (checkError)
            return (0);
        const casesCount = countryStats.data[countryStats.data.length - 1].Cases;
        return (casesCount);
    }

    static async checkNbCases(_data) {
        const instance = new ActionInterface();
        const { data } = _data;
        const formatted_data = JSON.parse(data);
        const countryName = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const casesCount = await Covid.getCasesCount(countryName);
        const nbParamStr = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;
        const nbParam = parseInt(nbParamStr);

        /* SET OF INSTANCE VARIABLES */
        instance.setVariable('$1$', countryName);
        instance.setVariable('$2$', casesCount);

        /* COMPARISON BETWEEN CURRENT NUMBER OF CASES AND THE TRIGGER */
        if (casesCount > nbParam)
            instance.setState(true);
        else
            instance.setState(false);
        return (instance);
    }

    static async nbCasesError(data) {
        return (true);
    }
}

export {Covid};
