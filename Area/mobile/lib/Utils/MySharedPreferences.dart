//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// MySharedPreferences
//

import 'package:shared_preferences/shared_preferences.dart';
import 'Globals.dart' as globals;

class MySharedPreferences {
  Future<void> setAccountUsername(var value) async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    await prefs.setString('ACCOUNT_USERNAME', value);
  }

  Future<String> getAccountUsername() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    return prefs.getString('ACCOUNT_USERNAME');
  }

  Future<void> setAccountID(var value) async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    await prefs.setString('ACCOUNT_ID', value);
  }

  Future<String> getAccountID() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    return prefs.getString('ACCOUNT_ID');
  }

  Future<void> resetAll() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    globals.username = null;
    globals.accountID = null;
    await prefs.clear();
  }
}
