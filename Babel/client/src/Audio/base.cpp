/*
** EPITECH PROJECT, 2020
** base.cpp
** File description:
** babel
*/

#include <stdio.h>
#include <opus/opus.h>
#include <portaudio.h>

#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include "../../include/Audio/PAudio.hpp"

#include <iostream>
#include <sstream>

my_PAudio::my_PAudio(std::string const &actual_address, int const &actual_port, std::string other)
{
    _enc.encode_manager(8000, 2, OPUS_APPLICATION_VOIP, &_err);
    this->_rets = 0;
    this->_errs = 0;
    this->_total = 0;
    int i = 0;
    std::string save;

    port_other = std::stoi(other);
    address_other = "127.0.0.1";
    std::cout << "actual: " << actual_address << ":" << actual_port << std::endl;
    std::cout << "other: " <<  address_other <<":" << port_other << std::endl;
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress(actual_address.c_str()), (quint16)actual_port);
    socket1 = new QUdpSocket(this);
    socket1->bind(QHostAddress(actual_address.c_str()), (quint16)actual_port);
}

my_PAudio::~my_PAudio()
{
}

void my_PAudio::StopCall()
{
    if (_isCalling > 0) {
        std::mutex mtx;
        mtx.lock();
        this->_isCalling = false;
        mtx.unlock();
        _audio.stop();
        for (auto& t: this->_threadList)
            t.join();
    }
}

void my_PAudio::RecordedSound()
{
    _audio.start();
    while (_isCalling == true) {
        unsigned char temp[200];
        this->_total = 0;
        int size;
        packet crypt_packet;
        this->_data = _audio.get().sampleR;
        crypt_packet.size_struct = 0;
        for (auto i = 0; i < 100; i++)
        {
            stockR.part[i] = this->_total;
            size = _enc.encode_float(_data + (80 * i), 80, temp, 200);
            crypt_packet.size_struct += size;
            for (auto j = 0; j < size; j++, this->_total++)
            {
                stockR.data[this->_total] = temp[j];
            }
        }
        check = 1;
        stockR.part[100] = this->_total;
        crypt_packet.crypt_data = stockR.data;
        crypt_packet.size_struct *= 3;
        crypt_packet.size_struct += sizeof(int);
        QByteArray Data;
        Data = QByteArray::fromRawData((const char *)stockR.data, crypt_packet.size_struct);
        socket->writeDatagram(Data, QHostAddress(this->address_other.c_str()), (quint16)port_other);
        QByteArray Data1;
        Data1 = QByteArray::fromRawData((const char *)stockR.part, 100);
        socket1->writeDatagram(Data1, QHostAddress(this->address_other.c_str()), (quint16)port_other);
        stockR.part[0] = '\0';
        stockR.data[0] = '\0';
    }
}

void my_PAudio::playSoundVoice()
{
    _audio.Listen();
    while (_isCalling == true) {
        if (check == 1) {
            float tmp[160];
            while (socket->hasPendingDatagrams()) {
                QByteArray buffer;
                buffer.resize(socket->pendingDatagramSize());
                QHostAddress sender;
                quint16 senderPort;
                socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
                unsigned char *datas = reinterpret_cast<unsigned char *>(buffer.data());
                while (socket1->hasPendingDatagrams())
                {
                    QByteArray buffer1;
                    buffer1.resize(socket1->pendingDatagramSize());
                    QHostAddress sender1;
                    quint16 senderPort1;
                    socket1->readDatagram(buffer1.data(), buffer1.size(), &sender1, &senderPort1);
                    unsigned char *datas1 = reinterpret_cast<unsigned char *>(buffer1.data());
                    for (auto i = 0; i < 100; i++)
                    {
                        this->_enc.decode_float(datas + datas1[i], datas1[i + 1] - datas1[i], tmp, 80, 0);
                        for (auto j = 0; j < 80 * 2; j++)
                        {
                            this->_data[j + i * 80] = tmp[j];
                        }
                    }
                }
                _audio.put(this->_data, 0);
            }
        }
    }
}

void my_PAudio::LaunchVoip()
{
    _isCalling = true;
    this->_threadList.push_back(std::thread(&my_PAudio::RecordedSound, this));
    this->_threadList.push_back(std::thread(&my_PAudio::playSoundVoice, this));
}
