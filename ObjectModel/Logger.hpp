#ifndef LOGGER_H
#define LOGGER_H

#include <SDL2/SDL.h>
#include <string>

#define VERBOSE

class Logger
{
    public:
    static void log(const char* msg);
    static void log(std::string msg);
};

#endif