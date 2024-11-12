import React, { Component } from 'react';
import { StyleSheet, Text, View, Image } from "react-native"
import { WebView } from 'react-native-webview';

const clientId = 'c3f7d507d128bf4';
global.token = "";

export default class ImgurWebView extends React.Component {
    constructor(props) {
        super(props)
      }

    _changeNavigationState = async (webView) => {
        if (this._splitUrl(webView.url) === true) {     
            this.props.navigation.navigate('HomeMenu');
        }
     };
    
    _splitUrl(url) {
         if (url.search("access_token=") > 0) { 
             let array = url.split("=");
             token = array[2].split('&')[0];
             return (true);     
         }        
         return (false);
     }
        
     webviewProps = {
        javaScriptEnabled: true,
        onNavigationStateChange: this._changeNavigationState.bind(this),
        source: {
            uri: 'https://api.imgur.com/oauth2/authorize?client_id=' + clientId + '&response_type=token&state=APPLICATION_STATE',
        }
    }

    render () {
        return (
            <WebView  {...this.webviewProps}/>
        )
    }
}