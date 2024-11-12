/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <string>
#include <string.h>
#include <iostream>

enum RequestType {
    CONNECTION,
    DISCONNECTION,
    CALL,
    HANG_UP,
    UNKNOWN,
    UPDATE,
    RECEIVE_CALL,
};

typedef struct __attribute__((packed))gate {
    uint32_t size;
    RequestType type;
    char content[0];
} gate_t;

class Message {
    public:
        Message();
        ~Message();
        void encode(char[], const char *, RequestType);
        gate_t *decode(char *code, uint32_t);
        uint32_t getSize(char *);
        RequestType getType() const;
        std::string getMessage() const;
        gate_t _packet;
    protected:
    private:
};

#endif /* !MESSAGE_HPP_ */
