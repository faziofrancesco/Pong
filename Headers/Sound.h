#ifndef SOUND_H
#define SOUND_H
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;

class Sound
{
    private:
        ALLEGRO_SAMPLE* game;
        ALLEGRO_SAMPLE* pong;
        ALLEGRO_SAMPLE * click;
        ALLEGRO_SAMPLE * change;

       
    public:
        Sound();

        void startGame();
        void SelectGame();
        void ChangeGame();
        void playPong();
        void stopSounds();
        ~Sound();

};
#endif