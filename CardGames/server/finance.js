const fetch = require("node-fetch");

const financeKey = 'JOW9TR44FIJIGGMQ';


module.exports = {
  getFinance: async (company) => {
    const finance = await fetch(
        `https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=${company}&apikey=${financeKey}`
    );
    let data = await finance.json();
    console.log(data);
    var response = {
      price: data['Global Quote']['05. price'],
      change: data['Global Quote']['10. change percent']
    }
    console.log(response);
    return response;
  },
  getChange: async (currency1, currency2) => {
    const finance = await fetch(
        `https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE&from_currency=${currency1}&to_currency=${currency2}&apikey=${financeKey}`
    );
    let data = await finance.json();
    console.log(data);
    if (data['Error Message']) {
      return null;
    }
    var response = {
      rate: data['Realtime Currency Exchange Rate']['5. Exchange Rate'],
    }
    console.log(response);
    return response;
  }
}