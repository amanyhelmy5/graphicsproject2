#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Sound
{
    Mix_Music* music;

    Mix_Chunk* effect;

public:
    Sound();
    ~Sound();

    void play_sound(std::string path);
};

#endif // SOUND_H
