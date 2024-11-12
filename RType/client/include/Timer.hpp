/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Timer.hpp
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

class Timer
{
public:
    Timer(int);
    ~Timer();
    bool isTime();
    bool isTimeMicro();
    int64_t getSeconds();
    int64_t getMicro();
    void setTimer(int);
    void reset();
private:
    std::chrono::time_point<std::chrono::system_clock> _start;
    std::chrono::time_point<std::chrono::system_clock> _end;
    int _timer;
};

#endif /* !TIMER_HPP_ */