const clientID = 'c8eaed406b1e4d7a8991f9d0998d0d72';
const clientSecret = 'fbbb47bf1f3a402db19fa78f16cbc0f4';
const fetch = require("node-fetch");

module.exports = {
  getTop50Playlist: async (playlistID, token) => {
    const playlist = await fetch(
      `https://api.spotify.com/v1/playlists/${playlistID}`, { headers: { "Authorization": `Bearer ${token}` } }
    );
    let data = await playlist.json();
    var response = {};
    var tracks = [];
    var track;
    var error = false;
    if (data.error)
      error = true;
    else {
      for (var i = 0; i < 3; i = i + 1) {
        track = data.tracks.items[i].track.name + ' - ' + data.tracks.items[i].track.artists[0].name
        tracks.push(track);
      }
    }
    response = {
      error: error,
      tracks: tracks
    }
    console.log(response);
    return response;
  },
  getTopArtists: async (genre, token) => {
    console.log(genre);
    const playlist = await fetch(
      `https://api.spotify.com/v1/search?q=%20genre:${genre}&type=artist`, { headers: { "Authorization": `Bearer ${token}`} }
    );
    let data = await playlist.json();
    var response = {};
    var tracks = [];
    var track;
    var error = false;
    if (data.error)
      error = true;
    else {
      if (data.artists.total > 5)
        for (var i = 0; i < 5; i = i + 1) {
          track = data.artists.items[i].name
          tracks.push(track);
        }
      else
        error = true;
    }
    response = {
      error: error,
      artists: tracks
    }
    console.log(response);
    return response;
  }
}