// This is a basic Flutter widget test.
//
// To perform an interaction with a widget in your test, use the WidgetTester
// utility that Flutter provides. For example, you can send tap and scroll
// gestures. You can also use WidgetTester to find child widgets in the widget
// tree, read text, and verify that the values of widget properties are correct.

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';

import 'package:Area/Utils/Globals.dart' as globals;
import 'package:Area/Utils/MySharedPreferences.dart';

void main() {
  Future<void> initialSetup() async {
    globals.accountID = '\0';
    globals.username = '\0';
  }

  test('Get "Enthonne" AccountID', () async {
    await initialSetup();
    await MySharedPreferences().setAccountID("Enthonne");
    globals.accountID = await MySharedPreferences().getAccountID();
    expect(globals.accountID, "Enthonne");
  });

  test('Get "Loulou" AccountID', () async {
    await initialSetup();
    await MySharedPreferences().setAccountID("Loulou");
    globals.accountID = await MySharedPreferences().getAccountID();
    expect(globals.accountID, "Loulou");
  });

  test('Get "Vivio" AccountID after multiple set', () async {
    await initialSetup();
    await MySharedPreferences().setAccountID("Tomo");
    await MySharedPreferences().setAccountID("Loulou");
    await MySharedPreferences().setAccountID("Enthonne");
    await MySharedPreferences().setAccountID("Vivio");
    globals.accountID = await MySharedPreferences().getAccountID();
    expect(globals.accountID, "Vivio");
  });
}
