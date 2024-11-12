/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** MessageComp
*/

#ifndef MESSAGECOMP_HPP_
#define MESSAGECOMP_HPP_

#include <string>
#include <string.h>
#include <iostream>
#include <vector>

#include <unistd.h>
enum RequestType {
    CONNECTION,
    OK,
    KO,
    JOIN_ROOM,
    PLAYER1,
    PLAYER2,
    LAUNCH_GAME,
    GAME_UPDATE,
    DISCONNECTION,
    UNKNOWN
};

enum EventType {
    SHOT,
    DEATH,
    ENEMY_DEATH
};

typedef struct gate {
    RequestType type; /* First header */
    unsigned int size;

    unsigned int size_1; /* First part | Player Position */
    unsigned int size_2; /* Second part | Enemies Position */
    unsigned int size_3; /* Third part | Projectile Position */
    int content[0];
} gate_t;

class MessageComp {
    public:
        MessageComp();
        ~MessageComp();

        void fulfillStruct(gate_t *src, gate_t *dest);
        template <typename T>
        char * encodeFourBytes(char *buff, const T content)
        {
            memcpy(buff, &content, 4);
            return buff + 4;
        }

        template <typename T>
        char * encodeContent(char *buff, unsigned int size, const T *content)
        {
            buff = encodeFourBytes<unsigned int>(buff, size);
            for (int i = 0; i < (size / 4); i++)
                buff = encodeFourBytes<T>(buff, content[i]);
            return buff;
        }

        template <typename T>
        char *decodeFourBytes(char *buff, T &content)
        {
            memcpy(&content, buff, 4);
            return buff + 4;
        }

        template <typename T>
        char  *decodeContent(char *buff, unsigned int size, T *content)
        {
            buff = decodeFourBytes<unsigned int>(buff, size);
            for (int i = 0; i < (size / 4); i++)
                buff = decodeFourBytes<T>(buff, content[i]);
            return buff;
        }

        char *encode(char *, gate_t &content);
        gate_t *decode(char *code, uint32_t &);
        uint32_t getSize(char *str_size);

    protected:
    private:
};

#endif /* !MESSAGECOMP_HPP_ */
