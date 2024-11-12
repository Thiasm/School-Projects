import React, { Component, Object } from 'react';
import { Text, Image, View, StyleSheet } from 'react-native'; 
import API from '../API/api'
import BoxList from '../components/BoxListFavorite'
import Header from '../components/Header'

export default class MyImages extends Component {

	constructor (props) {
		super(props)
		this.state = {
          	apiRes: [],
			loading: true,
        }
    }
	
	componentDidMount() {
		this.updateSearch();
	}

    updateSearch() {
    	this.state.loading = true;
        API.getMyImages().then((res) => {
            this.setState({
                apiRes: res,
                loading: false,
            })
        });
    };

	getFavoriteList() {
        let newList = [];
        if (this.state.loading == false) {
			if (this.state.apiRes.data != undefined) {
            	this.state.apiRes.data.map(element => {
                if (element
                    && (element.type === 'image/jpeg' || element.type === 'image/png')
                    && element.link !== undefined) {
                        
                    newList.push(element);

                }
            });
        }
    }
        return newList;
    }
	

	render () {
		var boxlist = [];
        if (this.state.loading == false) {
            let searchList = this.getFavoriteList();
            if (searchList.empty != true) {
                boxlist = (<BoxList list={searchList} update={() => this.updateSearch()} />);
            }
        }
		return (
			<View style={styles.container}>
				<Header/>
				{boxlist}
			</View>
		);
	}
}

const styles = StyleSheet.create({
    container:{
        flex:1,
        backgroundColor:"#1c2732"
    },
});