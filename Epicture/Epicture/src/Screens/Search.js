import React, { Component } from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { SearchBar } from 'react-native-elements';
import API from '../API/api'
import BoxList from '../components/BoxList'
import Header from './../components/Header'

export default class Details extends Component {
    constructor (props) {
		super(props)
		this.state = {
            search: '',
			apiRes: [],
			loading: true,
        }
    }
    
     updateSearch = (search) => {
        this.setState({ search });
        this.state.loading = true;
        console.log(search);
        API.searchImage(search).then((res) => {
            this.setState({
                apiRes: res,
                loading: false,
            })
        });
      };

    getSearchList() {
        let newList = [];
        if (this.state.loading == false) {
        if (this.state.apiRes.data != undefined
            && this.state.apiRes.data.items != undefined) {
            this.state.apiRes.data.items.map(element => {
                if (element.images
                    && (element.images[0].type === 'image/jpeg' || element.images[0].type === 'image/png')
                    && element.images[0].link !== undefined) {
                        
                    newList.push(element);

                }
            });
        }
    }
        return newList;
    }

    render() {
        const { search } = this.state;
        var boxlist = [];
      /*  if (this.state.search.length == 0) {
            boxlist = (<Text style={styles.message}>Type{'\n'}Something  </Text>)
            console.log("empty")
        }*/
        if (this.state.loading == false) {
            let searchList = this.getSearchList();
            if (searchList.empty != true) {
                boxlist = (<BoxList list={searchList} update={() => this.updateSearch()} />);
            }
        }
        return (
            <View style={styles.container}>
                <Header />
                <SearchBar
                    placeholder="Type Here..."
                    onChangeText={this.updateSearch}
                    value={search}
                    round={true}
                />
                {boxlist}
            </View>
        )
    }
}

const styles = StyleSheet.create({
    container:{
        flex:1,
        backgroundColor:"#1c2732",
    },
    message: {
        fontWeight:"bold",
        fontSize:40,
        color:"#fb5b5a",
        alignSelf:"center",
        marginTop: 200
    }
});