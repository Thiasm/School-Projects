/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/mainwindow.h"
#include <QApplication>
#include "../include/errorClient.hpp"

/**
 * Here a snapshot of UML diagram:
 * @mainpage \image html Babel_Diagram.png
 */

int main(int argc, char **argv)
{
    errorClient error(argc, argv);
    
    if (error.getIsError() == true)
        return (84);
    QApplication clientApp(argc, argv);
    MainWindow mainWindow(atoi(argv[1]));
    
    mainWindow.show();
    return clientApp.exec();
}
