#include "Logger.hpp"

void Logger::log(const char* msg)
{
    #ifdef VERBOSE
    SDL_Log(msg);
    #endif
}