//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// HomeMainRoute
//

import 'package:flutter/material.dart';

import 'package:Area/Pages/AreaCreationPage.dart';
import 'package:Area/Pages/AreaListPage.dart';
import 'package:Area/Pages/SettingsPage.dart';

class HomeMainRoute extends StatefulWidget {
  @override
  HomeMainRouteState createState() => HomeMainRouteState();
}

class HomeMainRouteState extends State<HomeMainRoute> {
  int _selectedIndex = 0;

  @override
  void initState() {
    super.initState();
  }

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  static List<Widget> _widgetOptions = <Widget>[
    AreaListPage(),
    AreaCreationPage(),
    SettingsPage(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        bottomNavigationBar: BottomNavigationBar(
          type: BottomNavigationBarType.fixed,
          items: const <BottomNavigationBarItem>[
            BottomNavigationBarItem(
              icon: Icon(Icons.list),
              label: 'AREAs',
            ),
            BottomNavigationBarItem(
              icon: Icon(
                Icons.add_circle,
              ),
              label: 'Add',
            ),
            BottomNavigationBarItem(
              icon: Icon(Icons.settings),
              label: 'Settings',
            ),
          ],
          currentIndex: _selectedIndex,
          selectedItemColor: Colors.blue,
          onTap: _onItemTapped,
        ),
        body: Center(child: _widgetOptions.elementAt(_selectedIndex)));
  }
}
