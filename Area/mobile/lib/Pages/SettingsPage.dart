//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// SettingsPage
//

import 'package:Area/API/Area.dart';
import 'package:Area/API/Const.dart';
import 'package:flutter/material.dart';
import 'package:Area/AreaApp.dart';
import 'package:Area/Utils/MySharedPreferences.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:Area/Utils/Globals.dart' as globals;

import 'Settings/SettingsElement.dart';
import 'Settings/SettingsList.dart';
import 'Settings/SettingsSection.dart';

class SettingsPage extends StatefulWidget {
  SettingsPage();
  @override
  _SettingsPageState createState() => _SettingsPageState();
}

class _SettingsPageState extends State<SettingsPage> {
  List<dynamic> _list_oauth = null;
  List<SettingsElement> _list = null;

  @override
  void initState() {
    getLinks();
    super.initState();
  }

  _launchURL(String url) async {
    if (await canLaunch(url)) {
      await launch(url);
    } else {
      throw 'Could not launch $url';
    }
  }

  void logout() {
    MySharedPreferences().resetAll();
    Navigator.pushReplacement(
        context, new MaterialPageRoute(builder: (context) => AreaApp()));
  }

  Future<void> getLinks() async {
    _list_oauth = await AreaAPI().getAllLinks();
    List<dynamic> _links_oauth = await AreaAPI().getLinks();
    var _uuid = await MySharedPreferences().getAccountID();
    print(_list_oauth);
    _list = _list_oauth
        .map((service) => new SettingsElement(
            title: _links_oauth
                        .where((element) => element['id'] == service['id'])
                        .length !=
                    0
                ? service['name'] + ' (Linked)'
                : service['name'],
            leading: Icon(Icons.exit_to_app),
            index: 1,
            onTap: (int /*value*/) {
              if (_links_oauth
                      .where((element) => element['id'] == service['id'])
                      .length !=
                  0) {
                _launchURL(APIEndpoint +
                    '/unlink?mobile=true&id=' +
                    service['id'].toString() +
                    '&uuid=' +
                    globals.accountID.toString());
              } else {
                _launchURL(APIEndpoint +
                    service['route'] +
                    '?mobile=true&uuid=' +
                    _uuid);
              }
            }))
        .toList();
    this.setState(() {});
    return (true);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(title: Text('Settings')),
        body: RefreshIndicator(
          onRefresh: getLinks,
          child: SettingsList(
            sections: [
              _list_oauth == null
                  ? null
                  : (SettingsSection(
                      title: 'Services',
                      tiles: _list,
                    )),
              SettingsSection(
                title: 'Account',
                tiles: [
                  SettingsElement(
                      title: 'Sign out',
                      leading: Icon(Icons.exit_to_app),
                      index: 1,
                      onTap: (int /*value*/) {
                        logout();
                      }),
                ],
              ),
            ],
          ),
    ));
  }
}
