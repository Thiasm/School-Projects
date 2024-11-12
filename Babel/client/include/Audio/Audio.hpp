/*
** EPITECH PROJECT, 2020
** Audio.hpp
** File description:
** babel
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <portaudio.h>
#include <vector>

#define NUM_CHANNELS (2)

typedef struct
{
    int frameIndex = 0;
    int frameIndex2 = 0;
    int maxFrameIndex = 0;
    float sampleR[16000 * sizeof(float)];
    float sampleL[16000 * sizeof(float)];
} paData;

typedef struct {
    unsigned char data[41000];
    int part[110];
} stockdata;

class Audio
{
public:
    Audio();
    ~Audio();
    paData get();
    void set(paData &data);
    void put(float *data, const int &index);
    void start();
    void Listen();
    void stop();
protected:
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *Stream1;
    PaStream *Stream2;
    paData _paData;
    int totalFrames;
private:
};

#endif 
