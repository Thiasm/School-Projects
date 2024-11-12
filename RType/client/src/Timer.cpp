/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Timer.cpp
*/

#include "Timer.hpp"
#include <iostream>

Timer::Timer(int timer) : _timer(timer)
{
    _start = std::chrono::system_clock::now();
}

Timer::~Timer()
{
}

void Timer::reset()
{
    _start = std::chrono::system_clock::now();
}

bool Timer::isTime()
{
	int64_t current = 0;

	_end = std::chrono::system_clock::now();
	current = std::chrono::duration_cast<std::chrono::seconds>(_end - _start).count();
	if (current >= this->_timer)
        return true;
    return false;
}

bool Timer::isTimeMicro()
{
	int64_t current = 0;

	_end = std::chrono::system_clock::now();
	current = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
	if (current >= this->_timer)
        return true;
    return false;
}

void Timer::setTimer(int timer)
{
	this->_timer = timer;
}

int64_t Timer::getSeconds()
{
	int64_t current = 0;

	_end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(_end - _start).count();
}

int64_t Timer::getMicro()
{
	int64_t current = 0;

	_end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
}