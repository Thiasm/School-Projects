//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// AreaView
//

import 'dart:convert';
import 'package:flutter/material.dart';

import 'package:Area/API/Area.dart';
import 'package:Area/Pages/Widget/ActionParamList.dart';
import 'package:Area/Pages/Widget/ReactionParamList.dart';

class AreaView extends StatefulWidget {
  final dynamic area;
  AreaView({Key key, @required this.area}) : super(key: key);
  @override
  _AreaView createState() => _AreaView(this.area);
}

class _AreaView extends State<AreaView> {
  final dynamic area;

  _AreaView(this.area);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(area['name']),
        actions: <Widget>[
          IconButton(
              icon: Icon(
                Icons.delete,
                color: Colors.white,
              ),
              onPressed: () {
                AreaAPI().deleteArea(area['id']);
                Navigator.pop(context);
              })
        ],
      ),
      body: Container(
        child: ListView(
            shrinkWrap: true,
            physics: ScrollPhysics(),
            scrollDirection: Axis.vertical,
            children: <Widget>[
              ListTile(
                dense: true,
                visualDensity: VisualDensity.compact,
                title: Text("Title",
                    style: TextStyle(
                      fontSize: 16.0,
                      fontWeight: FontWeight.bold,
                      color: Theme.of(context).accentColor,
                    )),
                subtitle: Text(area['name'],
                    style: TextStyle(fontSize: 13.0, color: Colors.black87)),
              ),
              ListTile(
                dense: true,
                visualDensity: VisualDensity.compact,
                title: Text("Description",
                    style: TextStyle(
                      fontSize: 16.0,
                      fontWeight: FontWeight.bold,
                      color: Theme.of(context).accentColor,
                    )),
                subtitle: Text(area['description'],
                    style: TextStyle(fontSize: 13.0, color: Colors.black87)),
              ),
              Divider(),
              Padding(
                padding:
                    const EdgeInsets.symmetric(horizontal: 16.0, vertical: 4.0),
                child: Text(
                  "Action",
                  style: TextStyle(
                    fontSize: 16.0,
                    fontWeight: FontWeight.bold,
                    color: Theme.of(context).accentColor,
                  ),
                ),
              ),
              Padding(
                padding:
                    const EdgeInsets.symmetric(horizontal: 16.0, vertical: 4.0),
                child: Text(
                  area['action_info']['name'],
                  style: TextStyle(
                    fontSize: 15.0,
                    fontWeight: FontWeight.bold,
                    color: Theme.of(context).accentColor,
                  ),
                ),
              ),
              Padding(
                padding:
                    const EdgeInsets.symmetric(horizontal: 16.0, vertical: 4.0),
                child: Text(
                  "Action parameters",
                  style: TextStyle(
                    fontSize: 14.0,
                    fontWeight: FontWeight.bold,
                    color: Theme.of(context).accentColor,
                  ),
                ),
              ),
              ActionParamList(area: area),
              Divider(),
              Padding(
                padding:
                    const EdgeInsets.symmetric(horizontal: 16.0, vertical: 4.0),
                child: Text(
                  "Reactions",
                  style: TextStyle(
                    fontSize: 16.0,
                    color: Theme.of(context).accentColor,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              ListView.separated(
                shrinkWrap: true,
                physics: ScrollPhysics(),
                scrollDirection: Axis.vertical,
                itemCount: area['reactions'].length,
                itemBuilder: (BuildContext context, int index) {
                  final reactionsParams =
                      json.decode(area['reactions'][index]['data']);
                  return ListView(
                    shrinkWrap: true,
                    physics: ClampingScrollPhysics(),
                    children: <Widget>[
                      Padding(
                        padding: const EdgeInsets.symmetric(
                            horizontal: 16.0, vertical: 4.0),
                        child: Text(
                          area['reaction_info'][index]['name'],
                          style: TextStyle(
                            fontSize: 15.0,
                            fontWeight: FontWeight.bold,
                            color: Theme.of(context).accentColor,
                          ),
                        ),
                      ),
                      Padding(
                        padding: const EdgeInsets.symmetric(
                            horizontal: 16.0, vertical: 4.0),
                        child: Text(
                          "Reaction parameters",
                          style: TextStyle(
                            fontSize: 14.0,
                            fontWeight: FontWeight.bold,
                            color: Theme.of(context).accentColor,
                          ),
                        ),
                      ),
                      ReactionParamList(
                        reaction: reactionsParams,
                      ),
                    ],
                  );
                },
                separatorBuilder: (BuildContext context, int index) =>
                    const Divider(),
              ),
            ]),
      ),
    );
  }
}
