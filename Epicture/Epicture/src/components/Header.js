import React, { Component } from 'react';
import { Text, View, StyleSheet, StatusBar } from 'react-native';

export default class Header extends Component {
    componentDidMount() {
        StatusBar.setHidden(true);
     }
    render() {
        return(
            <Text style={styles.logo}>Epicture.</Text>
        )
    }
}

const styles = StyleSheet.create({
    logo:{
        fontWeight:"bold",
        fontSize:30,
        color:"#fb5b5a",
        marginTop:10,
        marginBottom:10,
        alignSelf:"center",
    }
  })