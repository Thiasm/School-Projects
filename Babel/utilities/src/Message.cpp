/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-mathias.roulleaux
** File description:
** Message
*/

#include "Message.hpp"
#include <iostream>
#include <unistd.h> 
#include <cstdlib>

Message::Message()
{
}

Message::~Message()
{
}

void Message::encode(char *data, const char *content, RequestType type)
{
    int contentSize = strlen(content) + 1;
    
    gate_t *struct_data = (gate *)std::malloc(sizeof(gate_t) + contentSize);
    uint32_t *q = (uint32_t *)data;
    uint32_t *temp1 = q;
    char *temp;

    struct_data->size = contentSize;
    struct_data->type = type;
    strcpy(struct_data->content, content);
    *q = struct_data->size;
    q++;
    *q = (uint32_t)struct_data->type;
    q = temp1;
    char *p = (char *)q;
    temp = p;
    p += 8;
    for (int i = 0; i <= strlen(struct_data->content); p++)
        *p = struct_data->content[i++];
    p = temp;
    memcpy(data, p, sizeof(gate_t) + contentSize);
    std::free(struct_data);
}

gate_t *Message::decode(char *code, uint32_t size)
{
    gate_t *result = (gate_t*)std::malloc(sizeof(gate_t) + size);
    uint32_t *q = (uint32_t *)code;
    int i = 0;
    
    result->size = size;
    result->type = (RequestType)*q;
    q++;
    char *p = (char *)q;
    for (; *p != '\0'; p++)
        result->content[i++] = (char)*p;
    result->content[i] = '\0';
    return result;
}

RequestType Message::getType() const
{
    return _packet.type;
}

std::string Message::getMessage() const
{
    return std::string(_packet.content);
}

uint32_t Message::getSize(char *str_size)
{
    uint32_t *size = (uint32_t*)str_size;
    
    return *size;
}