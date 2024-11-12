//
// EPITECH PROJECT, 2020
// Area
// File description:
// Area
//

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'SettingsElement.dart';

class SettingsSection extends StatelessWidget {
  final List<SettingsElement> tiles;
  final TextStyle titleTextStyle;
  final String title;

  SettingsSection({
    Key key,
    this.title,
    this.tiles,
    this.titleTextStyle,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
      Padding(
        padding: const EdgeInsets.all(16),
        child: Text(
          title,
          style: titleTextStyle ??
              TextStyle(
                color: Theme.of(context).accentColor,
                fontWeight: FontWeight.bold,
              ),
        ),
      ),
      ListView.separated(
        physics: NeverScrollableScrollPhysics(),
        shrinkWrap: true,
        itemCount: tiles.length,
        separatorBuilder: (BuildContext context, int index) =>
            Divider(height: 1),
        itemBuilder: (BuildContext context, int index) {
          return tiles[index];
        },
      ),
    ]);
  }
}
