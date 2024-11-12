//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// AreaCreationPage
//

import 'package:Area/API/Area.dart';
import 'package:Area/Utils/Globals.dart' as globals;
import 'package:Area/Pages/AreaModalReaction.dart';

import 'package:flutter/material.dart';

import '../HomeMainRoute.dart';
import 'AreaListPage.dart';

class AreaCreationPage extends StatefulWidget {
  @override
  _AreaCreationPage createState() => _AreaCreationPage();
}

class _AreaCreationPage extends State<AreaCreationPage> {
  List<dynamic> _actions = [];
  List<dynamic> _reactions = [];
  final GlobalKey<ScaffoldState> _scaffoldKey = new GlobalKey<ScaffoldState>();
  final TextEditingController _titleEditor = new TextEditingController();
  final TextEditingController _descEditor = new TextEditingController();
  List<TextEditingController> _actionParamEditors = [];
  List<TextEditingController> _reactionParamEditors = [];

  List<AreaModalReaction> _listReactions = [];
  List<GlobalKey<MyAreaModalReaction>> _myKey = [];

  List<dynamic> _links_oauth = [];

  bool _isLoading = false;

  int _actionServiceId = 0;
  int _actionTriggerId = 0;
  int _reactionId = 0;

  @override
  void initState() {
    _getData();
    super.initState();
  }

  void showInSnackBar(String value) {
    _scaffoldKey.currentState
        .showSnackBar(new SnackBar(content: new Text(value)));
  }

  Future<void> _getData() async {
    _isLoading = true;
    onActionUpdate();
    onReactionUpdate();
    _links_oauth = await AreaAPI().getLinks();
    print(_links_oauth);
    var result = await AreaAPI().getAllServices().catchError((error) {
      if (error == null) {
        showInSnackBar("Can't connect to server");
        debugPrint("Server error");
      } else {
        showInSnackBar(error.toString());
        debugPrint(error.toString());
      }
    });
    List<dynamic> formatted_actions_oauth = [];
    result.forEach((element) {
      if (element['depends_on'] == null) {
        formatted_actions_oauth.add(element);
      } else if (_links_oauth
              .where(
                  (_element) => _element["id"] == element["depends_on"]["id"])
              .length !=
          0) {
        formatted_actions_oauth.add(element);
      }
    });
    setState(() {
      _actions.clear();
      _actions = formatted_actions_oauth;
    });
    result = await AreaAPI().getAllReactions().catchError((error) {
      if (error == null) {
        showInSnackBar("Can't connect to server");
        debugPrint("Server error");
      } else {
        showInSnackBar(error.toString());
        debugPrint(error.toString());
      }
      setState(() {
        _isLoading = false;
      });
    });
    List<dynamic> formatted_reactions_oauth = [];
    result.forEach((element) {
      if (element['depends_on'] == null) {
        formatted_reactions_oauth.add(element);
      } else if (_links_oauth
              .where(
                  (_element) => _element["id"] == element["depends_on"]["id"])
              .length !=
          0) {
        formatted_reactions_oauth.add(element);
      }
    });
    print(formatted_reactions_oauth);
    setState(() {
      _reactions.clear();
      _reactions = formatted_reactions_oauth;
      _isLoading = false;
      onActionUpdate();
      onReactionUpdate();
    });
  }

  Future<void> _submitArea() async {
    if (_titleEditor.text.length == 0) {
      return showInSnackBar("Area must have a title.");
    }

    List<dynamic> actionParams = [];
    for (int i = 0; i != _actionParamEditors.length; i++) {
      actionParams.add({
        'value': _actionParamEditors[i].text,
        'name': getCurrentActionTrigger()['parameters'][i]['name'],
        'parameter_name': getCurrentActionTrigger()['parameters'][i]['value']
      });
    }

    List<dynamic> reactionParams = [];
    for (var i = 0; i != this._myKey.length; i++) {
      reactionParams.add(this._myKey[i].currentState.getReactionParameters());
    }

    dynamic body = {
      'user_id': globals.accountID,
      'name': _titleEditor.text,
      'description': _descEditor.text,
      'service': {
        'service': {
          'id': _actionServiceId,
        },
        'sub_service': {
          'id': _actionTriggerId,
        },
        'parameters': actionParams
      },
      'reaction': reactionParams,
    };

    AreaAPI().addAREA(body).then((result) {
      Navigator.push(context,
          new MaterialPageRoute(builder: (context) => new HomeMainRoute()));
    }).catchError((error) {
      debugPrint(error.toString());
      showInSnackBar(error.toString());
    });
  }

  dynamic displayActionParameter(dynamic actionParameter, int index) {
    switch (actionParameter['type']) {
      case 'string':
        return ListTile(
          dense: true,
          title: Text(actionParameter['name']),
          subtitle: TextField(
            controller: _actionParamEditors[index],
            textAlign: TextAlign.left,
            decoration: InputDecoration(
              hintText: actionParameter['description'],
              hintStyle: TextStyle(color: Colors.grey, fontSize: 12),
            ),
          ),
        );
        break;
      default:
    }
  }

  dynamic displayReactionParameter(dynamic reactionParameter, int index) {
    //print(reactionParameter);
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

  dynamic getCurrentAction() {
    for (int i = 0; i != _actions.length; i++) {
      if (_actions[i]['id'] == _actionServiceId) {
        return _actions[i];
      }
    }
    return {'name': 'Unknown', 'desc': 'Unknown', 'triggers': []};
  }

  dynamic getCurrentReaction() {
    for (int i = 0; i != _reactions.length; i++) {
      if (_reactions[i]['id'] == _reactionId) {
        return _reactions[i];
      }
    }
    return null;
  }

  dynamic getCurrentActionTriggers() {
    for (int i = 0; i != _actions.length; i++) {
      if (_actions[i]['id'] == _actionServiceId) {
        return _actions[i]['triggers'];
      }
    }
    return [];
  }

  dynamic getCurrentActionTrigger() {
    for (int i = 0; i != _actions.length; i++) {
      if (_actions[i]['id'] == _actionServiceId) {
        for (int j = 0; j != _actions[i]['triggers'].length; j++) {
          if (_actions[i]['triggers'][j]['id'] == _actionTriggerId) {
            return _actions[i]['triggers'][j];
          }
        }
      }
    }
    return null;
  }

  void onActionUpdate() {
    _actionParamEditors.clear();
    dynamic actionTrigger = getCurrentActionTrigger();
    if (actionTrigger == null) return;
    for (int i = 0; i != actionTrigger['parameters'].length; i++) {
      _actionParamEditors.add(new TextEditingController());
    }
  }

  void onReactionUpdate() {
    _reactionParamEditors.clear();
    dynamic reactionTrigger = getCurrentReaction();
    if (reactionTrigger == null) return;
    for (int i = 0; i != reactionTrigger['parameters'].length; i++) {
      _reactionParamEditors.add(new TextEditingController());
    }
  }

  @override
  Widget build(BuildContext context) {
    List<DropdownMenuItem<int>> triggers = [];
    getCurrentActionTriggers().toList().forEach((dynamic trigger) {
      triggers.add(DropdownMenuItem<int>(
        child: Text(trigger['name']),
        value: trigger['id'],
      ));
    });

    void _addReaction() {
      GlobalKey<MyAreaModalReaction> key = GlobalKey();
      this._myKey.add(key);
      this
          ._listReactions
          .add(AreaModalReaction(reactions: this._reactions, key: key));
      this.setState(() {});
    }

    void _removeLastReaction() {
      this._listReactions.removeLast();
      this._myKey.removeLast();
      this.setState(() {});
    }

    return Scaffold(
        key: _scaffoldKey,
        appBar: AppBar(
          title: Text('Create an AREA'),
          actions: <Widget>[
            IconButton(
                icon: Icon(
                  Icons.check,
                  color: Colors.white,
                ),
                onPressed: _submitArea),
            IconButton(
                icon: Icon(
                  Icons.add,
                  color: Colors.white,
                ),
                onPressed: _addReaction),
            IconButton(
                icon: Icon(
                  Icons.remove,
                  color: Colors.white,
                ),
                onPressed: _removeLastReaction),
          ],
        ),
        body: Container(
            child: _isLoading
                ? Center(
                    child: CircularProgressIndicator(),
                  )
                : ListView(
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
                          subtitle: TextField(
                            controller: _titleEditor,
                            textAlign: TextAlign.left,
                            decoration: InputDecoration(
                              hintText: 'Title of the AREA',
                              hintStyle:
                                  TextStyle(color: Colors.grey, fontSize: 12),
                            ),
                          ),
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
                          subtitle: TextField(
                            controller: _descEditor,
                            textAlign: TextAlign.left,
                            decoration: InputDecoration(
                              hintText: 'Description of the AREA',
                              hintStyle:
                                  TextStyle(color: Colors.grey, fontSize: 12),
                            ),
                          ),
                        ),
                        Divider(),
                        Padding(
                          padding: const EdgeInsets.symmetric(
                              horizontal: 16.0, vertical: 4.0),
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
                            padding: const EdgeInsets.symmetric(
                                horizontal: 16.0, vertical: 4.0),
                            child: DropdownButton<int>(
                              isExpanded: true,
                              value: _actionServiceId,
                              items: _actions.map((dynamic action) {
                                return DropdownMenuItem<int>(
                                  child: Text(action['name']),
                                  value: action['id'],
                                );
                              }).toList(),
                              onChanged: (int value) {
                                setState(() {
                                  _actionServiceId = value;
                                  _actionTriggerId =
                                      getCurrentAction()['triggers'][0]['id'];
                                });
                                onActionUpdate();
                              },
                            )),
                        Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 16.0, vertical: 4.0),
                            child: DropdownButton<int>(
                              isExpanded: true,
                              value: _actionTriggerId,
                              items: triggers,
                              onChanged: (int value) {
                                setState(() {
                                  _actionTriggerId = value;
                                });
                                onActionUpdate();
                              },
                            )),
                        Padding(
                          padding: const EdgeInsets.symmetric(
                              horizontal: 16.0, vertical: 4.0),
                          child: Text(
                            "Action parameters",
                            style: TextStyle(
                              fontSize: 14.0,
                              fontWeight: FontWeight.bold,
                              color: Theme.of(context).accentColor,
                            ),
                          ),
                        ),
                        getCurrentActionTrigger() == null
                            ? null
                            : ListView.builder(
                                shrinkWrap: true,
                                physics: ClampingScrollPhysics(),
                                itemCount:
                                    getCurrentActionTrigger()['parameters']
                                        .length,
                                itemBuilder: (BuildContext context, int index) {
                                  return displayActionParameter(
                                      getCurrentActionTrigger()['parameters']
                                          [index],
                                      index);
                                }),
                        Divider(),
                        ListView.builder(
                            shrinkWrap: true,
                            physics: ClampingScrollPhysics(),
                            itemCount: this._listReactions.length,
                            itemBuilder: (BuildContext context, int index) {
                              return (this._listReactions[index]);
                            }),
                      ])));
  }
}
