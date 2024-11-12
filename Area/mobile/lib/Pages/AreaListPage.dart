//
// EPITECH PROJECT, 2020
// B-YEP-500-PAR-5-1-area-anton.cazalet
// File description:
// AreaListPage
//

import 'package:flutter/material.dart';

import 'package:Area/API/Area.dart';
import 'package:Area/Pages/Widget/AreaView.dart';

class AreaListPage extends StatefulWidget {
  AreaListPage();
  @override
  _AreaListPageState createState() => _AreaListPageState();
}

class _AreaListPageState extends State<AreaListPage> {
  final List<dynamic> _list = [];
  final GlobalKey<ScaffoldState> _scaffoldKey = new GlobalKey<ScaffoldState>();
  bool _isLoading = false;

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
    AreaAPI().getAreas().then((result) {
      setState(() {
        _list.clear();
        _list.addAll(result);
        _isLoading = false;
      });
    }).catchError((error) {
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
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        key: _scaffoldKey,
        appBar: AppBar(
          title: Text('List of your AREAs'),
        ),
        body: RefreshIndicator(
          child: _isLoading == true
              ? Center(child: CircularProgressIndicator())
              : _list.length == 0
                  ? ListView(
                      children: <Widget>[
                        Center(
                          child: Text("You currently have no AREA to display."),
                        ),
                        Center(
                          child: IconButton(
                            icon: Icon(Icons.refresh),
                            onPressed: _getData,
                          ),
                        )
                      ],
                    )
                  : ListView.separated(
                      shrinkWrap: true,
                      itemCount: _list.length,
                      itemBuilder: (BuildContext context, int index) {
                        return GestureDetector(
                            onTap: () {
                              Navigator.push(
                                context,
                                MaterialPageRoute(
                                    builder: (context) => AreaView(
                                          area: _list[index],
                                        )),
                              );
                            },
                            child: ListTile(
                                title: Text(_list[index]['name']),
                                subtitle: Text(_list[index]['description'])));
                      },
                      separatorBuilder: (BuildContext context, int index) =>
                          const Divider(),
                    ),
          onRefresh: _getData,
        ));
  }
}
