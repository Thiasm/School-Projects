/*
** EPITECH PROJECT, 2020
** Encoding.cpp
** File description:
** babel
*/

#ifndef ENCODING_HPP_
#define ENCODING_HPP_

#include <opus.h>

class Encoding {
public:
    Encoding();
    void encode_manager(int Fs, int channels, int application, int *err);
    int encode_float(const float * pcm, int frame_size, unsigned char * data, int max_data_bytes);
    int decode_float(const unsigned char *data, int len, float *pcm, int frame_size, int decode_fec);
protected:
    OpusEncoder *encode;
    OpusDecoder *decode;
private:
};

#endif
