const express = require('express')
const app = express()
var cors = require('cors')
const router = express.Router()
const weather = require('./weather')
const finance = require('./finance')
const spotify = require('./spotify')
const fetch = require("node-fetch");
const port = 8080

app.use(cors());
app.use(router);
app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})

router.get("/weather", async (req, res) => {
  var i = 0
  while (req.rawHeaders[i] != 'city')
    i = i + 1;
  i = i + 1;
  if (req.rawHeaders[i] == '')
    req.rawHeaders[i] = 'ddffg'
  res.json(await weather.getWeather(req.rawHeaders[i],(data) => {
    return data;
  }));
});

router.get("/weatherweek", async (req, res) => {
  var i = 0
  while (req.rawHeaders[i] != 'city')
    i = i + 1;
  i = i + 1;
  if (req.rawHeaders[i] == '')
    req.rawHeaders[i] = 'ddffg'
  res.json(await weather.getWeatherWeek(req.rawHeaders[i], (data) => {
    return data;
  }));
});

router.get("/finance", async (req, res) => {
  var i = 0
  while (req.rawHeaders[i] != 'company')
    i = i + 1;
  i = i + 1;
  if (req.rawHeaders[i] == '' || req.rawHeaders[i] == 'Select a symbol')
    req.rawHeaders[i] = 'ddffg'
  res.json(await finance.getFinance(req.rawHeaders[i],(data) => {
    return data;
  }));
});

router.get("/change", async (req, res) => {
  var one = 0
  var two = 0
  while (req.rawHeaders[one] != 'currency1')
    one = one + 1;
  one = one + 1;
  if (req.rawHeaders[one] == '')
    req.rawHeaders[one] = 'ddffg'

  while (req.rawHeaders[two] != 'currency2')
    two = two + 1;
  two = two + 1;
  if (req.rawHeaders[two] == '')
    req.rawHeaders[two] = 'ddffg'
  
  res.json(await finance.getChange(req.rawHeaders[one], req.rawHeaders[two],(data) => {
    return data;
  }));
});


router.get("/financedemo", async (req, res) => {
  res.json(await finance.getFinance('IBM',(data) => {
    return data;
  }));
});

router.get("/changedemo", async (req, res) => {
  res.json(await finance.getChange('EUR', 'USD',(data) => {
    return data;
  }));
});
  
router.get("/playlist", async (req, res) => {
  var one = 0
  var two = 0
  var arg;

  while (req.rawHeaders[one] != 'playlist')
    one = one + 1;
  one = one + 1;

  while (req.rawHeaders[two] != 'token')
    two = two + 1;
  two = two + 1;

  if (req.rawHeaders[one] == '')
    arg = 'ddffg';
  else if (req.rawHeaders[one] == 'Top 50-France')
    arg = '37i9dQZEVXbIPWwFssbupI';
  else if (req.rawHeaders[one] == 'Top 50-World')
    arg = '37i9dQZEVXbMDoHDwVN2tF';
  else if (req.rawHeaders[one] == 'Top Viral-France')
    arg = '37i9dQZEVXbJmRv5TqJW16';
  else if (req.rawHeaders[one] == 'Top Viral-World')
    arg = '37i9dQZEVXbLiRSasKsNU9';

  res.json(await spotify.getTop50Playlist(arg, req.rawHeaders[two], (data) => {
    return data;
  }));
});

router.get("/artists", async (req, res) => {
  var one = 0
  var two = 0
  var arg;
  console.log(req.rawHeaders);
  while (req.rawHeaders[one] != 'genre')
    one = one + 1;
  one = one + 1;

  while (req.rawHeaders[two] != 'token')
    two = two + 1;
  two = two + 1;
  arg = req.rawHeaders[one];
  if (req.rawHeaders[one] == '')
    arg = 'ddffg';
  res.json(await spotify.getTopArtists(arg, req.rawHeaders[two], (data) => {
    return data;
  }));
});

router.get("/spotifydemo", async (req, res) => {
  res.json(await spotify.getTop50Playlist('37i9dQZEVXbIPWwFssbupI', "BQAI48Xad9lm9QnCjA5-IaqlSiJZjdNXGBtOzgnfoqSYmymWPi0pLkRl6ia0UY9Mok-PUzKivoWEjduuvJb-g4kV9MfIafJmASbw4WwPYuuCvBcbpDquZFW_yCeJ9uzTnuzCmD2WYR0iRWCdat8eNOWs7cTv", (data) => {
    return data;
  }));
});
router.get("/artistdemo", async (req, res) => {
  res.json(await spotify.getTopArtists('House', "BQAI48Xad9lm9QnCjA5-IaqlSiJZjdNXGBtOzgnfoqSYmymWPi0pLkRl6ia0UY9Mok-PUzKivoWEjduuvJb-g4kV9MfIafJmASbw4WwPYuuCvBcbpDquZFW_yCeJ9uzTnuzCmD2WYR0iRWCdat8eNOWs7cTv", (data) => {
    return data;
  }));
});

router.use((req, res) => {
  res.status(404);
  res.json({
    error: "Page not found"
  });
});