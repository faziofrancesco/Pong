#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Ball.h"
#include "Player.h"
#include "Solid.h"
#include "Player1.h"
#include "Sound.h"
#include"GraphicManager.h"
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;
class LogicManager
{
    private:
        float windowWidth;
        float windowHeight;
        //STATO INIZIALE, REDRAW DI DEFAUtrLT, ARRAY DIREZIONI, DOEXIT
        bool startstate;
        bool redraw;
        bool doexit;
        float rx;
        float ry;
        float direction_x[2] = {4, -4};
        float direction_y[13] = { 1, -1, 1.5, -1.5, 2, -2, 2.5, -2.5, 3, -3, 3.5, -3.5};
        //DICHIARAZIONE DEGLI STATI DI GIOCO
        enum GAME_STATES{PAUSA, GAMEPLAY, GAMEOVER};
        //VARIABILI DEI COMANDI
        enum MYKEYS{UP, DOWN, LEFT, RIGHT, ESCAPE, ENTER, SPACE, UP2, DOWN2, SINGLE, LEFT2, RIGHT2};
        bool key[12] = {false, false, false, false, false, false, false, false, false, false, false, false};
        float bouncer_dx{0};
        float bouncer_dy{0};
        int p1score;
        int p2score;
        int gamestate;

    public:
        LogicManager(float ww,float wh);
        void restarter( Sound * sound, Sound * sound2, int & tipo, Player1 & p2, Player&p1, Ball & b,int scaleH);
        void GameLogic( Sound * sound, Sound * sound2, int & tipo, Player1 & p2, Player&p1, Ball & b,Solid & s,bool & obstacle,bool &hockey,bool &Player2,GraphicManager& gm,ALLEGRO_EVENT_QUEUE *event_queue,int &startGame,int ScaleH,int scaleW);
};
#endif
