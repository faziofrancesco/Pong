#include "../Headers/Sound.h"

Sound::Sound()
{
    al_reserve_samples(4);
    game = al_load_sample("../Sounds/menugame.wav");
    pong = al_load_sample("../Sounds/Pong.wav");
    click=al_load_sample("../Sounds/click.wav");
    change=al_load_sample("../Sounds/change.wav");
}

void Sound::playPong()
{
    al_play_sample(pong, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}

void Sound::startGame()
{
    al_play_sample(game, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
}
void Sound::ChangeGame()
{
    al_play_sample(change, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}

void Sound::SelectGame()
{
    al_play_sample(click, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}


void Sound::stopSounds(){al_stop_samples();}

Sound::~Sound()
{
    al_destroy_sample(game);
    al_destroy_sample(pong);
    al_destroy_sample(click);
    al_destroy_sample(change);
  
}
