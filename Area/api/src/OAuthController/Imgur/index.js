//
// AREA PROJECT, 2020
// AREA
// File description:
// Google
//

import axios from 'axios';

export class Imgur_Service {
    setAccessToken(accessToken) {
        this.accessToken = accessToken;
    }

    async getUserPictures(user) {
        const request = `https://api.imgur.com/3/account/${user}/submissions/0`;
        const res = await axios.get(request, {
            headers: {
                'Authorization': `Bearer ${this.accessToken}`,
            },
            validateStatus: false,
        });

        /* CHECK IF THE USER EXISTS AND HAS PHOTOS */
        if (res.data.data == null) {
            return (null);
        }
        return (res.data.data);
    }

    async postImage(title, description, image) {
        const config = {
            headers: {
                'Authorization': `Bearer ${this.accessToken}`,
            },
            validateStatus: false,
        };

        const body = {
            title: title,
            image: image,
            description: description,
        };

        const response = await axios.post('https://api.imgur.com/3/image', body, config);
        return (response);
    }
};
