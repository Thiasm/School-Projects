/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** MessageComp
*/

#include "MessageComp.hpp"
#include <unistd.h>

MessageComp::MessageComp()
{
}

MessageComp::~MessageComp()
{
}

void MessageComp::fulfillStruct(gate_t *src, gate_t *dest)
{
    dest->type = src->type; 
    dest->size = src->size;
    dest->size_1 = src->size_1;
    dest->size_2 = src->size_2;
    dest->size_3 = src->size_3;
    for (int i = 0; i < (src->size_1 + src->size_2 + src->size_3) / 4; i++)
        dest->content[i] = src->content[i];
}

char *MessageComp::encode(char *data, gate_t &content)
{
    char *stock = data;

    data = encodeFourBytes<RequestType>(data, content.type);
    data = encodeFourBytes<unsigned int>(data, content.size);
    data = encodeFourBytes<unsigned int>(data, content.size_1);
    data = encodeFourBytes<unsigned int>(data, content.size_2);
    data = encodeFourBytes<unsigned int>(data, content.size_3);
    data = encodeContent<int>(data, (content.size_1 + content.size_2 + content.size_3), content.content);
    data = stock;
    return data;
}

gate_t *MessageComp::decode(char *code, uint32_t &size)
{
    gate_t *content = (gate_t*)std::malloc(size + 8);
    char *stock = code;
    content->type = RequestType::GAME_UPDATE;
    content->size = size;
    code = decodeFourBytes<unsigned int>(code, content->size_1);
    code = decodeFourBytes<unsigned int>(code, content->size_2);
    code = decodeFourBytes<unsigned int>(code, content->size_3);
    code = decodeContent<int>(code, (content->size_1 + content->size_2 + content->size_3), content->content);
    code = stock;
    return content;
}

uint32_t MessageComp::getSize(char *str_size)
{
    uint32_t *size = (uint32_t*)str_size;
    
    return *size;
}