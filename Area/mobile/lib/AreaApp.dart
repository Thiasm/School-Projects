//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// AreaApp
//

import 'package:flutter/material.dart';

import 'package:Area/HomeMainRoute.dart';
import 'package:Area/Pages/Welcome/WelcomePage.dart';
import 'package:Area/Utils/Globals.dart' as globals;
import 'package:Area/Utils/MySharedPreferences.dart';

class AreaApp extends StatefulWidget {
  @override
  AreaAppState createState() => AreaAppState();
}

class AreaAppState extends State<AreaApp> {
  bool isLoggedIn = false;
  Future<bool> _loadCredidendials() async {
    var _isLoggedIn = await MySharedPreferences().getAccountID();
    if (_isLoggedIn != null) {
      isLoggedIn = true;
      print("[Debug] User is already logged in");
      globals.username = await MySharedPreferences().getAccountUsername();
      globals.accountID = await MySharedPreferences().getAccountID();
    }
    return (true);
  }

  @override
  void initState() {
    isLoggedIn = false;
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
      future: _loadCredidendials(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.done) {
          return MaterialApp(
              title: 'Area',
              home: (isLoggedIn == true ? HomeMainRoute() : WelcomePage()));
        } else {
          return Center(child: CircularProgressIndicator());
        }
      },
    );
  }
}
