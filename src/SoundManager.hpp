#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class SoundManager{

    public:
        SoundManager();
        ~SoundManager();

        void addSound(std::string name, const char* path);

        void playSound(const std::string which);

    private:
        std::map<std::string, Mix_Chunk*> soundBank;

        int audio_rate;
        Uint16 audio_format;
        int audio_channels;
        int audio_buffers;

        int isAudioOpen;

};

