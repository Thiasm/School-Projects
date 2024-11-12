//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// TestPage
//

import 'package:flutter/material.dart';
import 'package:Area/AreaApp.dart';
import 'package:Area/Utils/MySharedPreferences.dart';

class TestPage extends StatefulWidget {
  TestPage();
  @override
  _TestPageState createState() => _TestPageState();
}

class _TestPageState extends State<TestPage> {
  void logout() {
    MySharedPreferences().resetAll();
    Navigator.pushReplacement(
        context, new MaterialPageRoute(builder: (context) => AreaApp()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Container(
          color: Colors.white,
          child: FlatButton(onPressed: logout, child: Text('LOGOUT')),
        ),
      ),
    );
  }
}
