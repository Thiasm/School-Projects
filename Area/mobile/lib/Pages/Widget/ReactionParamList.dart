//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// ReactionParamList
//

import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

class ReactionParamList extends StatefulWidget {
  final dynamic reaction;
  ReactionParamList({Key key, @required this.reaction}) : super(key: key);
  @override
  _ReactionParamList createState() => _ReactionParamList(this.reaction);
}

class _ReactionParamList extends State<ReactionParamList> {
  final dynamic reaction;

  _ReactionParamList(this.reaction);

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
        shrinkWrap: true,
        physics: ClampingScrollPhysics(),
        scrollDirection: Axis.vertical,
        itemCount: reaction.length,
        itemBuilder: (BuildContext context, int _index) {
          return ListTile(
            dense: true,
            visualDensity: VisualDensity.compact,
            title: Text(reaction[_index]['name']),
            subtitle: Text(reaction[_index]['value']),
          );
        });
  }
}
