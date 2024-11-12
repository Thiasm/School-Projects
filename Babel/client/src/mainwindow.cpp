/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** mainwindow
*/

#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../../utilities/include/Message.hpp"
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <vector>


MainWindow::MainWindow(int const& port)
    : ui(new Ui::MainWindow)
    , micVolume(50)
    , audioVolume(50)
{
    client = std::unique_ptr<babelClient> (new babelClient(port));
    client->launch();
    ui->setupUi(this);

    this->setBackground();
}

MainWindow::~MainWindow()
{
    delete ui;
}

const int MainWindow::getAudioVolume()
{
    return this->audioVolume;
}

const int MainWindow::getMicVolume()
{
    return this->micVolume;
}

void MainWindow::setBackground()
{
    QPixmap bkgnd("./../ressource/skype.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::on_callButton_clicked()
{
    if (ui->ListContact->count() == 0)
        return;
    QListWidgetItem *a = ui->ListContact->currentItem();
    if (a == nullptr)
        return;
    QString s = a->text();
    
    client->clientConnect->sendServer(s.toStdString(), RequestType::CALL);
}

void MainWindow::on_HangUpButton_clicked()
{
    client->clientConnect->sendHangUp();
}

void MainWindow::on_DisconnectButton_clicked()
{
    client->clientConnect->sendServer("Disconnect", RequestType::DISCONNECTION);
}

void MainWindow::on_updateButton_clicked()
{
    client->clientConnect->sendServer("Update", RequestType::UPDATE);
    std::vector<std::string> tmp = client->clientConnect->getContactList();

    ui->ListContact->clear();
    for(const std::string & str : tmp)
        ui->ListContact->addItem(str.c_str());
    
}

void MainWindow::on_audioSlider_valueChanged(const int& value)
{
    this->audioVolume = value;
    std::cout << "Audio = " << audioVolume << std::endl;
}

void MainWindow::on_micSlider_valueChanged(const int& value)
{
    this->micVolume = value;
    std::cout << "Mic = " << micVolume << std::endl;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Babel", tr("Are you sure?\n"), QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes)
        event->ignore();
    else
        this->client->clientConnect->launchDisconnection("");    
}