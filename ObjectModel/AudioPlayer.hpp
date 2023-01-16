#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include "Common.hpp"
#include "WAVSound.hpp"
#include <map>
#include <filesystem>

class AudioPlayer
{
private:
    SDL_AudioDeviceID _deviceId;

    std::map<std::string, WAVSound *> _wavs;

    static AudioPlayer *_instance;

    AudioPlayer()
    {

        int audio_rate = 22050;
        Uint16 audio_format = AUDIO_S16SYS;
        int audio_channels = 2;
        int audio_buffers = 4096;

        if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
        {
            fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
            exit(1);
        }

        for (const auto &entry : std::filesystem::directory_iterator(WAVSound::DEFAULT_WAVS_PATH))
        {
            auto file = entry.path().filename().replace_extension(); // replace_extension removes extension
            _wavs[file] = new WAVSound(file);
        }
    }

public:
    static AudioPlayer *getInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new AudioPlayer();
        }

        return _instance;
    }

    void play(std::string sound)
    {

        // auto audio = _wavs[sound];
        // Mix_PlayChannel(-1, audio->sound, 0);

        Mix_Chunk *sdsad = Mix_LoadWAV("soundfx/click.wav");
        Mix_PlayChannel(-1, sdsad, 0);
    }
};

#endif