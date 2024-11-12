const apiUrl = 'https://api.imgur.com/3/'
export const clientId = 'c3f7d507d128bf4'
export const cliendSecret = 'd7a0c90ccbd7b1c42371c39b25b9856951378ef4'

export default {
    get (targetUrl) {
        return fetch(apiUrl + targetUrl, {
            headers: {
                'Authorization': 'Client-ID ' + clientId
            }
        })
        .then((res) => {
            return res.json()
        })
    },
    getViral() {
        return fetch(apiUrl + "gallery/random/random/1", {
            headers: {
                'Authorization': 'Client-ID ' + clientId
            }
        })
        .then((res) => {
            return res.json()
        })
    },
    searchImage(str) {
        return fetch(apiUrl + 'gallery/t/' + str, {
            headers: {
                'Authorization': 'Client-ID ' + clientId
            }
        })
        .then((res) => {
            return res.json()
        })
    },
    postFavorite (imageID) {
          return fetch(`https://api.imgur.com/3/image/${imageID}/favorite`, {
              method: 'POST',
              headers: {
                  'Authorization': 'Bearer ' + token
              }
            })
      },
    getFavorite () {
        return fetch(`https://api.imgur.com/3/account/me/unorganized_favorites?client_id=${clientId}&page=0&sort=newest`)
        .then((res) => {
            return res.json()
        })
    },
    uploadImage (data) {
        var formdata = new FormData();
        formdata.append('image', data.base64);
        formdata.append('type', 'base64');
        formdata.append('name', 'name')
        formdata.append('description', 'desc')
        return fetch(apiUrl + 'upload', {
            method: 'POST',
            headers: {
                'Authorization': 'Client-ID ' + clientId
            },
           'body': formdata
        })
        .then((res) => {
            return res.json()
        })
    },
    getMyImages() {
        return fetch(apiUrl + 'account/me/images', {
            method: 'GET',
            headers: {
                Authorization: 'Bearer ' + token
            }})
            .then((res) => {
                return res.json()
            })
        }
}