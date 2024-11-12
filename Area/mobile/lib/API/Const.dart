const String DefaultServerIP = 'area.antoncazalet.fr';
const String DefaultApiPort = '8080';

const String APIHost =
    String.fromEnvironment('SERVER_IP', defaultValue: DefaultServerIP);
const String APIPort =
    String.fromEnvironment('API_PORT', defaultValue: DefaultApiPort);

const String APIEndpoint = 'https://' + APIHost + ':' + APIPort;
