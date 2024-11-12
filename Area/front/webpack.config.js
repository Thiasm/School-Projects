const HtmlWebpackPlugin = require('html-webpack-plugin');
const path = require('path');
const Dotenv = require('dotenv-webpack');

module.exports = {
    entry: ['./src/index.js'],
    devtool: 'inline-source-map',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'index_bundle.js',
        publicPath: '/',
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                use: [{ loader: 'babel-loader', options: { presets: ['@babel/preset-env', '@babel/react'] } }],
                exclude: /node_modules/,
            },
        ],
    },
    devServer: {
        historyApiFallback: true,
        disableHostCheck: true,
    },
    plugins: [
        new Dotenv(),
        new HtmlWebpackPlugin({ title: 'Dashboard', template: './public/index.html', favicon: './public/favicon.ico' }),
    ],
};
