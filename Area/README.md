# Area

## Prerequisites

- Docker
- Docker-Compose

## Configuration

### Environment variables

Environment variables can be changed in `docker-compose.yml`.

### Ports

Three ports are used:
- `8080`: this port is used to access the api through https.
- `8081`: this port is used to access the website through http.
- `8181`: this port is used to access phpmyadmin.


## Testing

1. Be sure that you meet the [prerequisites](#prerequisites) and that you have [configured](#configuration) the projet.
2. Run the postman collection from `./api/tests/`, and `npm test` in `/front` to run front tests.
3. The tests should now run.

**If you are planning to submit a pull request, be sure that you have developped the required tests, and that they all pass.**


## Documentation

The documentation of the project can be found in the [Doc] folder of the project.

The documentation includes documentation of the front and the API and explains why we decided to use those technologies for this project.

## Usage

To run the project in **Development mode** follow [this part](###development-mode) and for **Production mode** follow [this part](###production-mode).

### Development mode

When you are developping features on the [Area](#area), you can start the project in development mode. This mode allow you to use the hot reload for the front.

```
cd api/ && npm install && npm start
cd front/ && npm install && npm start
docker-compose up db phpmyadmin
```

Note:
Hot reload is activated on frontand & api.

### Production mode
```
docker-compose up
```

Once the container is started, access it through https://your-ip-address:8080/ or http://your-ip-address:8081/.


## Maintainers

This respository is currently maintained by:
- [Anton Cazalet](mailto:anton.cazalet@epitech.eu)
- [Thomas Senechal](mailto:thomas.senechal@epitech.eu)
- [Louis Deleplace](mailto:louis.deleplace@epitech.eu)
- [Alex Goyer](mailto:alex.goyer@epitech.eu)
- [Vivian Rebollo](mailto:vivian.rebollo@epitech.eu)
- [Mathias Roulleaux](mailto:mathias.roulleaux@epitech.eu)
