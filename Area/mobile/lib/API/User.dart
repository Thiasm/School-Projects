import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:Area/Utils/Globals.dart' as globals;
import 'package:Area/API/Const.dart';

class UserAPI {
  login(String email, String password) async {
    final route = APIEndpoint + "/login";
    var response = await http.post(Uri.encodeFull(route), body: {
      "email": email,
      "password": password,
    });
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  register(String email, String password, String passwordConfirmation) async {
    final route = APIEndpoint + "/register";
    var response = await http.post(Uri.encodeFull(route), body: {
      "email": email,
      "password": password,
      "passwordConfirmation": passwordConfirmation
    });
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }
}
