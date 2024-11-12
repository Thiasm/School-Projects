const weatherKey = '08a4019285f1a847da0e8962b7b995b3'
const fetch = require("node-fetch");

module.exports = {
  getWeather: async (city) => {
    const weather = await fetch(
        `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${weatherKey}&units=metric`
    );
    let data = await weather.json();

    if (data.cod === "404") {
      var error = {
        temperature: 0,
        city: 'city not found',
        sky: 'cloud'
      }
      return error;
    }

    var dataSky;
    if (data.weather[0].main === 'Clear')
      dataSky = 'sun';
    else
      dataSky = 'cloud'
    var response = {
      city: data.name,
      temperature: data.main.temp,
      sky: dataSky
    }
    console.log(response);
    return response;
  },

  getWeatherWeek: async (city) => {
    const cnt = '100';
    const weather = await fetch(
        `https://api.openweathermap.org/data/2.5/forecast?q=${city}&cnt=${cnt}&appid=${weatherKey}&units=metric`
    );
    let data = await weather.json();
    if (data.cod === "404") {
      var error = {
        city: 'city not found',
      }
      return error;
    }
    var weatherArr = [];
    var dataSky;
    var weatherElem;
    var count = 0;


    if (data.list[0].weather[0].main === 'Clear')
      dataSky = 'sun';
    else
      dataSky = 'cloud'
    weatherElem = {
      temperature: data.list[0].main.temp,
      sky: dataSky,
      date: data.list[0].dt_txt
    }
    weatherArr.push(weatherElem);


    for (var i = 0; i < 40; i = i + 1) {
      if (count == 8) {
        count = 0;
        if (data.list[i].weather[0].main === 'Clear')
          dataSky = 'sun';
        else
          dataSky = 'cloud'
        weatherElem = {
          temperature: data.list[i].main.temp,
          sky: dataSky,
          date: data.list[i].dt_txt
        }
        weatherArr.push(weatherElem);
      }
      count = count + 1;
    }


    if (data.list[39].weather[0].main === 'Clear')
      dataSky = 'sun';
    else
      dataSky = 'cloud'
    weatherElem = {
      temperature: data.list[39].main.temp,
      sky: dataSky,
      date: data.list[39].dt_txt
    }
    weatherArr.push(weatherElem);
    
    
    var response = {
      city: data.name,
      weather: weatherArr
    }
    console.log(response);
    return response;
  }
}