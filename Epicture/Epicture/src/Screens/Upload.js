import React, { Component } from 'react';
import { Text, View, StyleSheet, Image, Button, Dimensions } from 'react-native';
import * as ImagePicker from 'expo-image-picker';
import API from '../API/api'

export default class Details extends Component {
    constructor (props) {
		super(props)
		this.state = {
			selectedImage: null,
            isSelected: false,
            posted: false,
            visible: false,
        }
    }
    upload () {
       API.uploadImage(this.state.selectedImage).then((res) => {
            if (res == undefined)
                return
            this.setState({
                posted: true
            })
            alert("Posted !")
        });
    }
    async pickPhotoCamera() {
        await ImagePicker.launchCameraAsync({
            base64: true,
            title: null,
            mediaType: 'photo',
        }).then((res) => {
            this.setState({
                isSelected: true,
                selectedImage: res,
            })
        })
    }
    async pickPhotoGallery() {
        await ImagePicker.launchImageLibraryAsync({
            mediaTypes: ImagePicker.MediaTypeOptions.pickPhotoGallery,
            base64: true,
            allowsEditing: false,
            quality: 1,
        }).then((res) => {
            this.setState({
                isSelected: true,
                selectedImage: res,
            })
        })
    }
    render() {
        var image = [];
        var upload = [];
        var center = [];
        var bottom = (<View style={styles.bottom}/>);
        var posted = [];
        if (this.state.isSelected == true) {
            image = (<Image source={{ uri: this.state.selectedImage.uri }} resizeMode='contain'style={{width: 350, height: 350}}></Image>);
            upload = (<Button style={{height: 40, marginLeft: 10 }}
                        onPress={() => this.upload()}
                        mode='outlined' color='#f55d7e' title="Upload.">
                    </Button>)
            center = (
                <View style={styles.center}>
                    {image}
                    {upload}
                </View>)
            bottom = [];
        }
        if (this.state.posted == true)
            posted = (
                <View style={styles.center}>
                    <Text style={styles.posted}>Image posted</Text>
                </View>)
        return (
            <View style={styles.container}>
                <View style={styles.top}>
                    <Text style={styles.title}>Upload.</Text>
                </View>
                {center}
                <View style={styles.down}>
                    <Button style={{height: 40, width: this.buttonSize
                                    }}
                        onPress={() => this.pickPhotoCamera()}
                        mode='outlined' color='#ed6683' title="Camera">
                    </Button>
                    <Button style={{height: 40, width: this.buttonSize
                                    }}
                        onPress={() => this.pickPhotoGallery()}
                        mode='outlined' color='#fb5b5a' title="Gallery">
                    </Button>
                </View>
                {bottom}
            </View>
        )
    }
}

const styles = StyleSheet.create({
    container:{
        flex:1,
        backgroundColor:"#1c2732",
        alignItems: 'center',
        justifyContent: 'center'
    },
    top:{
        flex:1,
        backgroundColor:"#1c2732",
        alignItems: 'center',
        justifyContent: 'flex-start'
    },
    center:{
        flex:3,
        backgroundColor:"#1c2732",
        alignItems: 'center',
        justifyContent: 'flex-start'
    },
    posted:{
        fontWeight:"bold",
        fontSize:30,
        color:"#faebee",
        marginTop:50,
        marginBottom:10,
        alignSelf:"center",
    },
    down:{
        flex:1,
        backgroundColor:"#1c2732",
        alignItems: 'stretch',
        justifyContent: 'space-evenly'
    },
    bottom:{
        flex:1,
        backgroundColor:"#1c2732",
        alignItems: 'stretch',
        justifyContent: 'space-evenly'
    },
    title:{
        fontWeight:"bold",
        fontSize:50,
        color:"#faebee",
        marginTop:50,
        marginBottom:10
    },
});