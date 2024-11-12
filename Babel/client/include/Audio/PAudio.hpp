/*
** EPITECH PROJECT, 2020
** PAudio.hppp
** File description:
** babel
*/

#include <unistd.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include "Encoding.hpp"
#include "Audio.hpp"
#include <QObject>
#include <QUdpSocket>

#ifndef PAUDIO_HPP_
#define PAUDIO_HPP_

class my_PAudio : public QObject
{
    Q_OBJECT
public:
    my_PAudio(std::string const&, int const&, std::string );
    ~my_PAudio();
    void StopCall();
    void RecordedSound();
    void playSoundVoice();
    void LaunchVoip();
private:
protected:
     QUdpSocket *socket;
     QUdpSocket *socket1;
    std::string address_other;
    int port_other;
    Encoding _enc;
    float *_data = 0;
    int _err = 0;
    int _rets = 0;
    int _errs = 0;
    int _total = 0;
    unsigned char _temp = {};
    float _tmp = 0;
    int check = 0;
     bool _isCalling = false;
    bool _isHangup = false;
    std::vector<std::thread> _threadList;
    Audio _audio;
    stockdata stockL{};
    stockdata stockR{};
    int _sock;
    struct packet
    {
        int size_struct;
        unsigned char *crypt_data;
    };
};

#endif
