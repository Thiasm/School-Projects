/*
** EPITECH PROJECT, 2020
** Record.cpp
** File description:
** babel
*/

#include <stdio.h>
#include <iostream>
#include "../../include/Audio/Audio.hpp"

static int recordCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags, void *userData )
{
    //paData *data = (paData*)userData;
    paData *data = (paData *)userData;
    float *in = (float *)inputBuffer;
    const float *rptr = (const float*)inputBuffer;
    float *wptr = &data->sampleR[data->frameIndex * NUM_CHANNELS];
    long framesToCalc;
    long i;
    int finished;
    unsigned long framesLeft = data->maxFrameIndex - data->frameIndex;

    if( framesLeft < framesPerBuffer ) {
        framesToCalc = framesLeft;
        finished = paComplete;
    }
    else {
        framesToCalc = framesPerBuffer;
        finished = paContinue;
    }
    if (inputBuffer == NULL ) {
        for( i=0; i<framesToCalc; i++ ) {
            *wptr++ = 0.0f;
            if( NUM_CHANNELS == 2 ) *wptr++ = 0.0f;
        }
    }
    else {
        for( i=0; i<framesToCalc; i++ )
        {
            *wptr++ = *rptr++; 
            if( NUM_CHANNELS == 2 ) *wptr++ = *rptr++;
        }
    }
    data->frameIndex += framesToCalc;
    if (data->frameIndex == data->maxFrameIndex) {
		data->frameIndex = 0;
		finished = paContinue;
    }
   // data->sampleR[0] = '\0';
    return finished;
} 


void Audio::start() {
	PaError err;

	err = Pa_OpenStream(&Stream1, &inputParameters, NULL, 8000, 512, paClipOff, recordCallback, &_paData);
	err = Pa_StartStream(Stream1);
}

void Audio::stop() {
    PaError err;
    err = Pa_CloseStream(Stream1);
    err = Pa_CloseStream(Stream2);
}
