//
// AREA PROJECT, 2020
// AREA
// File description:
// Calendar actions file
//

import {getOAuthDataByUUID} from '../../../DatabaseController/OAuth';
import {Outlook_Service} from '../../../OAuthController/Outlook';
import {findOAuthService} from '../../OAuth';

class CalendarOffice {
    static async setEvent(_data) {
        const {user_id, data} = _data;
        const formatted_data = JSON.parse(data);

        /* FIND THE TARGET TITLE AND DATE TO BE SET */
        const title = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_1$').value;
        const dueDate = formatted_data.find((_tmp) => _tmp.parameter_name === '$PARAM_2$').value;

        /* GET THE OAUTH DATA */
        const oauth_data = await getOAuthDataByUUID(user_id, findOAuthService('Office 365').id);

        if (oauth_data == null) {
            return (false);
        }

        const formatted_oauth_data = JSON.parse(oauth_data.data);
        const {access_token} = formatted_oauth_data;

        /* INIT OUTLOOK SERVICE */
        const api = new Outlook_Service();

        /* DEFINE THE START DATE AND THE END DATE */
        const startDate = '20' + dueDate.split('/')[2] + '-' + dueDate.split('/')[1] + '-' + dueDate.split('/')[0] + 'T08:00:00';
        const endDate = '20' + dueDate.split('/')[2] + '-' + dueDate.split('/')[1] + '-' + dueDate.split('/')[0] + 'T18:00:00';

        /* SET THE TOKEN AND SET EVENT */
        api.setAccessToken(access_token);
        api.setEvent(title, startDate, endDate);
        return (true);
    }
}

export {CalendarOffice};
