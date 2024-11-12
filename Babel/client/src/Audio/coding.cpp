/*
** EPITECH PROJECT, 2020
** coding.cpp
** File description:
** babel
*/

#include <stdio.h>
#include <iostream>
#include "../../include/Audio/Encoding.hpp"

Encoding::Encoding() {   
}

void Encoding::encode_manager(int Fs, int channels, int application, int *err)
{
    encode = opus_encoder_create(Fs, channels, application, err);
    decode = opus_decoder_create(Fs, channels, err);
};
 
int Encoding::encode_float(const float * pcm, int frame_size, unsigned char * data, int max_data_bytes)
{
    return opus_encode_float(encode, pcm, frame_size, data, max_data_bytes);
};

int Encoding::decode_float(const unsigned char *data, int len, float *pcm, int frame_size, int decode_fec)
{
    return opus_decode_float(decode, data, len, pcm, frame_size, decode_fec);
};
