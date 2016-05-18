#include "sound.h"

Sound::Sound()
{

    Mix_OpenAudio(22050 , MIX_DEFAULT_FORMAT, 2, 4096);
    music=Mix_LoadMUS("Sounds/harry_potter.ogg");
    Mix_PlayMusic(music, -1);
}

Sound::~Sound()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

void Sound::play_sound(std::string path)
{
    effect = Mix_LoadWAV(path.c_str());
    Mix_PlayChannel(-1, effect, 0);
}
