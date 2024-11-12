import React, { Component } from 'react';
import { StyleSheet, Text, View, Image } from "react-native"
import { Button } from 'react-native-paper';

export default class App extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      signedIn: false,
      name: "",
      token: "",
    }
  }

  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.logo}>Epicture.</Text>
        <Button
          mode='contained'
          style={styles.ImgurButton}
			    onPress={() => this.props.navigation.navigate('ImgurWebView')}>
            Imgur Log In
			  </Button>
      </View>
    )
  }
}

const styles = StyleSheet.create({
  webview_container: {
    flex: 1
  },
  container: {
    flex: 1,
    backgroundColor:"#1c2732",
    alignItems: 'center',
  },
  logo:{
    fontWeight:"bold",
    fontSize:75,
    color:"#fb5b5a",
    marginTop:200,
    marginBottom: 200
  },
  ImgurButton: {
		alignItems: 'center',
		justifyContent: 'center',
		backgroundColor: '#89C623',
    marginTop: 50,
  },
})