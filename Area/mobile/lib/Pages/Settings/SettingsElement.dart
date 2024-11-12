//
// EPITECH PROJECT, 2020
// Area
// File description:
// Area
//

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';

enum _SettingsElementType { simple, switchTile }

class SettingsElement extends StatelessWidget {
  final String title;
  final String subtitle;
  final Widget leading;
  final Widget trailing;
  final ValueChanged<int> onTap;
  final int index;
  final Function(bool value) onToggle;
  final bool switchValue;
  final bool enabled;
  final TextStyle titleTextStyle;
  final TextStyle subtitleTextStyle;
  final Color switchActiveColor;
  final _SettingsElementType _tileType;

  const SettingsElement({
    Key key,
    @required this.title,
    this.subtitle,
    this.leading,
    this.trailing,
    this.onTap,
    this.index,
    this.titleTextStyle,
    this.subtitleTextStyle,
    this.enabled = true,
    this.switchActiveColor,
  })  : _tileType = _SettingsElementType.simple,
        onToggle = null,
        switchValue = null,
        super(key: key);

  const SettingsElement.switchTile({
    Key key,
    @required this.title,
    this.subtitle,
    this.leading,
    this.enabled = true,
    this.trailing,
    @required this.onToggle,
    @required this.switchValue,
    this.titleTextStyle,
    this.subtitleTextStyle,
    this.switchActiveColor,
    this.index,
  })  : _tileType = _SettingsElementType.switchTile,
        onTap = null,
        super(key: key);

  @override
  Widget build(BuildContext context) {
    if (_tileType == _SettingsElementType.switchTile) {
      return SwitchListTile(
        secondary: leading,
        value: switchValue,
        activeColor: switchActiveColor,
        onChanged: enabled ? onToggle : null,
        title: Text(title, style: titleTextStyle),
        subtitle:
            subtitle != null ? Text(subtitle, style: subtitleTextStyle) : null,
      );
    } else {
      return ListTile(
        title: Text(title, style: titleTextStyle),
        subtitle:
            subtitle != null ? Text(subtitle, style: subtitleTextStyle) : null,
        leading: leading,
        enabled: enabled,
        trailing: trailing,
        onTap: () {
          if (this.index != null) this.onTap(this.index);
        },
      );
    }
  }
}
