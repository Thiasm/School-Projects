//
// EPITECH PROJECT, 2020
// Area
// File description:
// Area
//

import 'SettingsSection.dart';
import 'package:flutter/material.dart';

class SettingsList extends StatelessWidget {
  final List<SettingsSection> sections;

  const SettingsList({
    Key key,
    this.sections,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.white,
      child: ListView.builder(
        itemCount: sections.length,
        itemBuilder: (context, index) {
          SettingsSection current = sections[index];
          return (current);
        },
      ),
    );
  }
}
