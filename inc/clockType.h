/**
 * @file clockType.h
 * @brief Clock Type Class
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#pragma once

#include <stdint.h>

class clockType
{
public:

    clockType(int hours, int minutes, int seconds);
    clockType();

    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherClock) const;

private:
    int hr;
    int min;
    int sec;
};
