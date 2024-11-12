/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** babelClient
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.hpp"
#include <QCloseEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int const&);
    ~MainWindow();
    const int getAudioVolume();
    const int getMicVolume();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<babelClient> client;
    int audioVolume;
    int micVolume;
    void setBackground();
    void closeEvent(QCloseEvent *);
    
private slots:
    void on_callButton_clicked();
    void on_HangUpButton_clicked();
    void on_updateButton_clicked();
    void on_DisconnectButton_clicked();
    void on_audioSlider_valueChanged(const int&);
    void on_micSlider_valueChanged(const int&);
};
#endif // MAINWINDOW_H