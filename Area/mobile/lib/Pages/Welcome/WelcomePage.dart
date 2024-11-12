//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// WelcomePage
//

import 'dart:async';

import 'package:Area/Utils/MySharedPreferences.dart';
import 'package:flutter/material.dart';
import 'package:Area/Pages/Welcome/LoginPage.dart';
import 'package:Area/Pages/Welcome/RegisterPage.dart';
import 'package:Area/API/Const.dart';
import 'package:flutter/services.dart';
import 'package:uni_links/uni_links.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:Area/Utils/Globals.dart' as globals;

import '../../AreaApp.dart';

class WelcomePage extends StatefulWidget {
  WelcomePage();
  @override
  _WelcomePageState createState() => _WelcomePageState();
}

class _WelcomePageState extends State<WelcomePage> {
  TextStyle style = TextStyle(fontFamily: 'Arial', fontSize: 20.0);
  StreamSubscription _sub;

  var oauth = null;
  var email = null;
  var uuid = null;

  @override
  void initState() {
    this.initUniLinks();
    super.initState();
  }

  void goToSignUp() {
    Navigator.push(
      context,
      new MaterialPageRoute(builder: (context) => new RegisterPage()),
    );
  }

  void goToLogin() {
    Navigator.push(
      context,
      new MaterialPageRoute(builder: (context) => new LoginPage()),
    );
  }

  _launchURL(String url) async {
    if (await canLaunch(url)) {
      await launch(url);
    } else {
      throw 'Could not launch $url';
    }
  }

  Future<Null> initUniLinks() async {
    _sub = getUriLinksStream().listen((Uri url) {
      url.queryParameters.forEach((k, v) => {
            if (k == "oauth" && v == "google") {oauth = v},
            if (k == "email") {email = v},
            if (k == "uuid") {uuid = v},
          });
      if (oauth != null && email != null && uuid != null) {
        MySharedPreferences().setAccountUsername(email);
        MySharedPreferences().setAccountID(uuid);
        globals.username = email;
        globals.accountID = uuid;
        Navigator.pushReplacement(
            context, new MaterialPageRoute(builder: (context) => AreaApp()));
      }
    }, onError: (err) {
      print(err);
    });
  }

  @override
  void dispose() {
    _sub.cancel();
    super.dispose();
  }

  void goToGoogle() {
    _launchURL('https://area.antoncazalet.fr:8080/auth/google?mobile=true');
  }

  @override
  Widget build(BuildContext context) {
    return new Scaffold(
        resizeToAvoidBottomPadding: false,
        body: Container(
          height: MediaQuery.of(context).size.height,
          decoration: BoxDecoration(
            color: Colors.blueAccent,
            image: DecorationImage(
              colorFilter: new ColorFilter.mode(
                  Colors.black.withOpacity(0.2), BlendMode.dstATop),
              image: AssetImage('assets/wood-background.jpg'),
              fit: BoxFit.cover,
            ),
          ),
          child: new Column(
            children: <Widget>[
              Container(
                padding: EdgeInsets.only(top: 200.0),
                child: Center(
                  child: Icon(
                    Icons.link,
                    color: Colors.white,
                    size: 100.0,
                  ),
                ),
              ),
              Container(
                padding: EdgeInsets.only(top: 10.0),
                child: new Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  crossAxisAlignment: CrossAxisAlignment.end,
                  children: <Widget>[
                    Text(
                      "AREA",
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 30.0,
                          fontWeight: FontWeight.bold),
                    ),
                    Text(
                      APIEndpoint,
                      style: TextStyle(
                        color: Colors.white70,
                        fontSize: 20.0,
                      ),
                    ),
                  ],
                ),
              ),
              Container(
                padding: EdgeInsets.only(top: 20.0),
                child: new Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  crossAxisAlignment: CrossAxisAlignment.end,
                  children: <Widget>[
                    Text("Automation platform of your digital life.",
                        style: TextStyle(color: Colors.white70, fontSize: 20.0),
                        overflow: TextOverflow.ellipsis),
                  ],
                ),
              ),
              new Container(
                width: MediaQuery.of(context).size.width,
                margin:
                    const EdgeInsets.only(left: 30.0, right: 30.0, top: 125.0),
                alignment: Alignment.center,
                child: new Row(
                  children: <Widget>[
                    new Expanded(
                      child: new OutlineButton(
                        shape: new RoundedRectangleBorder(
                            borderRadius: new BorderRadius.circular(30.0)),
                        color: Colors.white,
                        borderSide: BorderSide(color: Colors.white),
                        highlightedBorderColor: Colors.white,
                        onPressed: goToSignUp,
                        child: new Container(
                          padding: const EdgeInsets.symmetric(
                            vertical: 20.0,
                            horizontal: 20.0,
                          ),
                          child: new Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: <Widget>[
                              new Expanded(
                                child: Text(
                                  "SIGN UP",
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      color: Colors.white,
                                      fontWeight: FontWeight.bold),
                                ),
                              ),
                            ],
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              new Container(
                width: MediaQuery.of(context).size.width,
                margin:
                    const EdgeInsets.only(left: 30.0, right: 30.0, top: 30.0),
                alignment: Alignment.center,
                child: new Row(
                  children: <Widget>[
                    new Expanded(
                      child: new FlatButton(
                        shape: new RoundedRectangleBorder(
                            borderRadius: new BorderRadius.circular(30.0)),
                        color: Colors.white,
                        onPressed: goToLogin,
                        child: new Container(
                          padding: const EdgeInsets.symmetric(
                            vertical: 20.0,
                            horizontal: 20.0,
                          ),
                          child: new Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: <Widget>[
                              new Expanded(
                                child: Text(
                                  "LOGIN",
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      color: Colors.blueAccent,
                                      fontWeight: FontWeight.bold),
                                ),
                              ),
                            ],
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              new Container(
                width: MediaQuery.of(context).size.width,
                margin:
                    const EdgeInsets.only(left: 30.0, right: 30.0, top: 30.0),
                alignment: Alignment.center,
                child: new Row(
                  children: <Widget>[
                    new Expanded(
                      child: new FlatButton(
                        shape: new RoundedRectangleBorder(
                            borderRadius: new BorderRadius.circular(30.0)),
                        color: Colors.white,
                        onPressed: goToGoogle,
                        child: new Container(
                          padding: const EdgeInsets.symmetric(
                            vertical: 20.0,
                            horizontal: 20.0,
                          ),
                          child: new Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: <Widget>[
                              new Expanded(
                                child: Text(
                                  "GOOGLE LOGIN",
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      color: Colors.blueAccent,
                                      fontWeight: FontWeight.bold),
                                ),
                              ),
                            ],
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ));
  }
}
