#ifndef WAV_SOUND_H
#define WAV_SOUND_H

#include "Common.hpp"

struct WAVSound
{
    static inline std::string DEFAULT_WAVS_PATH = "./soundfx/";
    static inline std::string DEFAULT_WAVS_FILE_EXT = ".wav";

    Mix_Chunk* sound;

    WAVSound(std::string file)
    {
        file = DEFAULT_WAVS_PATH + file + DEFAULT_WAVS_FILE_EXT;
        sound = Mix_LoadWAV(file.c_str());
    }

};

#endif