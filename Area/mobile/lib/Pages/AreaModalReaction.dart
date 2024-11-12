//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// ReactionParamList
//

import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

class AreaModalReaction extends StatefulWidget {
  final dynamic reactions;
  AreaModalReaction({Key key, @required this.reactions}) : super(key: key);
  @override
  MyAreaModalReaction createState() => MyAreaModalReaction(this.reactions);
}

class MyAreaModalReaction extends State<AreaModalReaction> {
  final List<dynamic> reactions;
  int reactionId = 0;
  List<TextEditingController> _reactionParamEditors = [];

  MyAreaModalReaction(this.reactions);

  @override
  void initState() {
    super.initState();
    onReactionUpdate();
  }

  dynamic getCurrentReaction() {
    for (int i = 0; i != this.reactions.length; i++) {
      if (this.reactions[i]['id'] == this.reactionId) {
        return this.reactions[i];
      }
    }
    return null;
  }

  void onReactionUpdate() {
    _reactionParamEditors.clear();
    dynamic reactionTrigger = getCurrentReaction();
    if (reactionTrigger == null) return;
    for (int i = 0; i != reactionTrigger['parameters'].length; i++) {
      _reactionParamEditors.add(new TextEditingController());
    }
  }

  dynamic displayReactionParameter(dynamic reactionParameter, int index) {
    switch (reactionParameter['type']) {
      case 'string':
        return ListTile(
          dense: true,
          title: Text(reactionParameter['name']),
          subtitle: TextField(
            controller: _reactionParamEditors[index],
            textAlign: TextAlign.left,
            decoration: InputDecoration(
              hintText: reactionParameter['description'],
              hintStyle: TextStyle(color: Colors.grey, fontSize: 12),
            ),
          ),
        );
        break;
      default:
    }
  }

  dynamic getReactionParameters() {
    List<dynamic> _reaction = [];
    List<dynamic> reactionParams = [];
    for (int i = 0; i != _reactionParamEditors.length; i++) {
      reactionParams.add({
        'value': _reactionParamEditors[i].text,
        'name': getCurrentReaction()['parameters'][i]['name'],
        'parameter_name': getCurrentReaction()['parameters'][i]['value']
      });
    }
    return ({
      'reaction': {'id': this.reactionId},
      'parameters': reactionParams,
    });
  }

  @override
  Widget build(BuildContext context) {
    return ListView(
        shrinkWrap: true,
        physics: ScrollPhysics(),
        scrollDirection: Axis.vertical,
        children: <Widget>[
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
          Padding(
              padding:
                  const EdgeInsets.symmetric(horizontal: 16.0, vertical: 4.0),
              child: DropdownButton<int>(
                isExpanded: true,
                value: this.reactionId,
                items: this.reactions.map((dynamic reaction) {
                  return DropdownMenuItem<int>(
                    child: Text(reaction['name']),
                    value: reaction['id'],
                  );
                }).toList(),
                onChanged: (int value) {
                  setState(() {
                    reactionId = value;
                  });
                  onReactionUpdate();
                },
              )),
          getCurrentReaction() == null
              ? null
              : ListView.builder(
                  shrinkWrap: true,
                  physics: ClampingScrollPhysics(),
                  itemCount: getCurrentReaction()['parameters'].length,
                  itemBuilder: (BuildContext context, int index) {
                    return displayReactionParameter(
                        getCurrentReaction()['parameters'][index], index);
                  }),
        ]);
  }
}
