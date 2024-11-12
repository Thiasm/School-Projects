import React, { Component } from 'react';
import { StyleSheet, Text, View, Image, FlatList, Dimensions, RefreshControl, TouchableWithoutFeedback } from "react-native"
import MaterialCommunityIcons from 'react-native-vector-icons/MaterialCommunityIcons';
import { Button } from 'react-native-paper';
import API from '../API/api'

// numer pf column in flastlist
const nbColumns = 2;

// Dimensions of the current screen
const { height, width } = Dimensions.get('window'); 

export default class BoxList extends Component {
    constructor(props) {
        super(props);
        this.state = {
            dataList: [],
            refreshing: false,
            selectedImage: "",
            selectedImageId: "",
            selected: false,
        }
    }

    componentDidMount() {
        this.setState({dataList: this.props.list})
    }

    handleRefresh = () => {
        this.props.update();
        this.setState({dataList: this.props.list})
    };

    renderItem = ({item, index}) => {
        if (item.empty)
            return <View style={styles.itemInvisible} />;
        
        const setImage = () => {
            this.setState({ selectedImage: item.images[0].link })
            this.setState({ selectedImageId: item.images[0].id })
            this.setState({ selected: true })
        };

        return (
            <TouchableWithoutFeedback onPress={setImage}>
                <Image style={styles.image} source={{uri: item.images[0].link}} ></Image>
            </TouchableWithoutFeedback>
        )
    }

    goBack = () => {
        this.setState({selected: false})
    }

    addToFavorite = () => {
        API.postFavorite(this.state.selectedImageId);
    }

    render() {
        const renderImage = () => (
            <View style={styles.container}>
                <View style={{
                    flexDirection: 'row',
                    marginLeft: 25,
                    marginTop: 25
                }}>
                    <Button style={styles.button} onPress={this.goBack}> <MaterialCommunityIcons name="keyboard-backspace" color="white" size={40} /> </Button>
                    <Button style={styles.button} onPress={this.addToFavorite}> <MaterialCommunityIcons name="cards-heart" color="white" size={40} /> </Button>
                </View>
                <Image
                    source={{ uri: this.state.selectedImage }}
                    resizeMode='contain'
                    style={{aspectRatio: 1, justifyContent:'center'}}
                />
            </View>
          );
        return (
            <View style={styles.focusView}>
            {
            (this.state.selected === true)
            ?   renderImage() 
            :   <FlatList
                    data = {this.state.dataList}
                    extraData = {this.state.dataList}
                    renderItem = {photo => this.renderItem(photo)}
                    numColumns = {nbColumns}
                    refreshControl = {
                        <RefreshControl
                            refreshing={this.state.refreshing}
                            onRefresh={this.handleRefresh}
                        />
                    }
                />
            }
            </View>
        )
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },
    button: {
        borderRadius: 30,
        backgroundColor: "red",
        width: 100,
        margin: 38,
    },
    image: {
        height: width / nbColumns,
        width: width / nbColumns - (nbColumns * 5 / nbColumns) - 5,
        margin: 5
        
    },
    itemInvisible: {
        backgroundColor: 'transparent',
    },
    focusView: {
    flexDirection: "row",
    justifyContent: "flex-end"
    }
});