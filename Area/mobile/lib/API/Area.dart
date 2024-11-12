import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:Area/Utils/Globals.dart' as globals;
import 'package:Area/API/Const.dart';

class AreaAPI {
  Future<List<dynamic>> getAreas() async {
    final route = APIEndpoint + "/area/list";
    var response = await http
        .post(Uri.encodeFull(route), body: {"user_id": globals.accountID});
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      print("getAreas");
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  Future<List<dynamic>> getAllServices() async {
    final route = APIEndpoint + "/services/get";
    var response = await http.get(Uri.encodeFull(route));
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      print("getAllServices");
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  Future<List<dynamic>> getAllReactions() async {
    final route = APIEndpoint + "/actions/get";
    var response = await http.get(Uri.encodeFull(route));
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      print("getAllReactions");
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  Future<String> addAREA(dynamic data) async {
    String encoded = json.encode(data);
    final route = APIEndpoint + "/area";
    var response =
        await http.post(Uri.encodeFull(route), body: encoded, headers: {
      'Content-Type': 'application/json',
    });
    if (response.statusCode == 200) {
      return (response.body);
    } else {
      throw (response.body);
    }
  }

  Future<String> deleteArea(int areaId) async {
    print(areaId);
    String encoded =
        json.encode({"user_id": globals.accountID, "area_id": areaId});
    final route = APIEndpoint + "/area/delete";
    var response =
        await http.post(Uri.encodeFull(route), body: encoded, headers: {
      'Content-Type': 'application/json',
    });
    if (response.statusCode == 200) {
      return ("Ok");
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  Future<List<dynamic>> getAllLinks() async {
    final route = APIEndpoint + "/auth/default_list";
    var response = await http.get(Uri.encodeFull(route));
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }

  Future<List<dynamic>> getLinks() async {
    final route = APIEndpoint + "/auth/list";
    var response = await http
        .post(Uri.encodeFull(route), body: {"uuid": globals.accountID});
    if (response.statusCode == 200) {
      var body = json.decode(response.body);
      return (body);
    } else {
      throw json.decode(response.body)["error"];
    }
  }
}
