/**
 * @file clockType.cc
 * @brief Clock Type Class
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include <stdio.h>
#include "clockType.h"

bool validate_time(int hours, int minutes, int seconds)
{
    return (hours >= 0) && (hours < 24) && \
        (minutes >= 0) && (minutes < 60) && \
        (seconds >= 0) && (seconds < 60);
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (validate_time(hours, minutes, seconds))
    {
        hr = hours;
        min = minutes;
        sec = seconds;
    }
    else
    {
        hr = 0;
        min = 0;
        sec = 0;
    }
}

clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}

void clockType::setTime(int hours, int minutes, int seconds)
{
    if (validate_time(hours, minutes, seconds))
    {
        hr = hours;
        min = minutes;
        sec = seconds;
    }
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const
{
    // printf just makes more sense for this..
    // std::cout is just messy for formatting...
    printf("%02d:%02d:%02d",hr,min,sec);
}

void clockType::incrementSeconds()
{
    if (++sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    if (++min == 60)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours()
{
    if (++hr == 24)
    {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType& otherClock) const
{
    int hours, minutes, seconds;
    otherClock.getTime(hours, minutes, seconds);

    return (hr == hours) && (min == minutes) && (sec == seconds);
}
