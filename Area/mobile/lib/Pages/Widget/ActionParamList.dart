//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// ActionParamList
//

import 'dart:convert';
import 'package:flutter/material.dart';

class ActionParamList extends StatefulWidget {
  final dynamic area;
  ActionParamList({Key key, @required this.area}) : super(key: key);
  @override
  _ActionParamList createState() => _ActionParamList(this.area);
}

class _ActionParamList extends State<ActionParamList> {
  final dynamic area;

  _ActionParamList(this.area);

  @override
  Widget build(BuildContext context) {
    final params = json.decode(area['action']['data']);
    return ListView.builder(
        shrinkWrap: true,
        physics: ClampingScrollPhysics(),
        itemCount: params.length,
        itemBuilder: (BuildContext context, int index) {
          return ListTile(
            dense: true,
            title: Text(params[index]['name']),
            subtitle: Text(params[index]['value']),
          );
        });
  }
}
