import React, { Component } from 'react';
import { createMaterialBottomTabNavigator } from '@react-navigation/material-bottom-tabs';
import MaterialCommunityIcons from 'react-native-vector-icons/MaterialCommunityIcons';
import Home from './../Screens/Home'
import Search from './../Screens/Search'
import Favorite from './../Screens/Favorite'
import Upload from './../Screens/Upload'
import MyImages from './../Screens/MyImages'

const Tab = createMaterialBottomTabNavigator();

export default class BottomMenu extends Component {
    render () {
        return (
            <Tab.Navigator
                activeColor="#f0edf6"
                inactiveColor='black'
                barStyle={{ backgroundColor: '#fb5b5a' }}>
                <Tab.Screen
                    name="Home"
                    component={Home} 
                    options={{
                        tabBarLabel: 'Home',
                        tabBarIcon: ({ color }) => (
                            <MaterialCommunityIcons name="home" color={color} size={23} />
                        ),
                  }}/>
                <Tab.Screen 
                    name="Search"
                    component={Search}
                    options={{
                        tabBarLabel: 'Search',
                        tabBarIcon: ({ color }) => (
                            <MaterialCommunityIcons name="image-search" color={color} size={23} />
                        ),
                    }}
                />
                <Tab.Screen 
                    name="Upload"
                    component={Upload}
                    options={{
                        tabBarLabel: 'Upload',
                        tabBarIcon: ({ color }) => (
                            <MaterialCommunityIcons name="progress-upload" color={'grey'} size={26} />
                            ),
                    }}
                />
                <Tab.Screen 
                    name="Favorite"
                    component={Favorite}
                    options={{
                        tabBarLabel: 'Favorite',
                        tabBarIcon: ({ color }) => (
                            <MaterialCommunityIcons name="heart" color={color} size={23} />
                        ),
                  }}/>
                <Tab.Screen 
                    name="MyImages"
                    component={MyImages}
                    options={{
                        tabBarLabel: 'My Images',
                        tabBarIcon: ({ color }) => (
                            <MaterialCommunityIcons name="account-box-outline" color={color} size={23} />
                        ),
                    }}
                />
            </Tab.Navigator>
        );
    }
}
