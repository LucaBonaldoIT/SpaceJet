#include "Logger.hpp"

void Logger::log(const char* msg)
{
    #ifdef VERBOSE
    SDL_Log(msg);
    #endif
}

void Logger::log(std::string msg)
{
    #ifdef VERBOSE
    SDL_Log(msg.c_str());
    #endif
}