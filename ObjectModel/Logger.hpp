#ifndef LOGGER_H
#define LOGGER_H

#include <SDL2/SDL.h>

#define VERBOSE

class Logger
{
    public:
    static void log(const char* msg);
};

#endif