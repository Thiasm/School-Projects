/*
** EPITECH PROJECT, 2020
** Audio.cpp
** File description:
** babel
*/

#include <stdio.h>
#include <iostream>
#include "../../include/Audio/Audio.hpp"
#include <portaudio.h>

Audio::Audio()
{
    PaError err = Pa_Initialize();
    _paData.maxFrameIndex = 8000;
    inputParameters.device = Pa_GetDefaultInputDevice();
    inputParameters.channelCount = 2;                    /* mono input */
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 2;
    outputParameters.sampleFormat =  paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;
}

static int listenCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    paData *data = (paData *)userData;
    float *rptr = &data->sampleL[data->frameIndex2 * NUM_CHANNELS];
    float *wptr = (float *)outputBuffer;
    unsigned int i = 0;
    int finished = 0;
    unsigned int framesLeft = data->maxFrameIndex - data->frameIndex2;
    
    if (framesLeft < framesPerBuffer) {
        for (i = 0; i < framesLeft; i++) {
            *wptr++ = *rptr++;
            if (NUM_CHANNELS == 2)
                *wptr++ = *rptr++;
        }
        for (; i < framesPerBuffer; i++) {
            *wptr++ = 0;
            if (NUM_CHANNELS == 2)
                *wptr++ = 0;
        }
        data->frameIndex2 = 0;
        finished = paContinue;
    } else {
        for (i = 0; i < framesPerBuffer; i++) {
            *wptr++ = *rptr++;
            if (NUM_CHANNELS == 2)
                *wptr++ = *rptr++;
        }
        data->frameIndex2 += framesPerBuffer;
        finished = paContinue;
    }
    return finished;
}

paData Audio::get()
{
    return _paData;
}


void Audio::set(paData &data)
{
    _paData = data;
}

void Audio::put(float *data, const int &index)
{
    for (auto i = 0; i < 16000; i++) {
        _paData.sampleL[i + index] = data[i];
    }
}

void Audio::Listen()
{
    PaError err = paNoError;

    _paData.frameIndex2 = 0;
    err = Pa_OpenStream(&Stream2, NULL, &outputParameters, 8000, 512, paClipOff, listenCallback, &_paData);
    err = Pa_StartStream(Stream2);
}

Audio::~Audio()
{
}
