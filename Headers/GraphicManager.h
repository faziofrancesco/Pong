#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H
#include"Ball.h"
#include "Player.h"
#include "Solid.h"
#include "Player1.h"
#include "Sound.h"
#include"Menu.h"
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;
class GraphicManager
{
    private:
        float windowWidth;
        float windowHeight;
        ALLEGRO_FONT *font;
        ALLEGRO_FONT *font2;
        ALLEGRO_FONT *font3;
    public:
        GraphicManager(float windowWidth,float windowHeight,ALLEGRO_FONT * f,ALLEGRO_FONT * f2,ALLEGRO_FONT * f3);
        void drawField(bool hockey);
        void drawObject(bool & obstacle,Ball &b,Player & p,Player1 & p1,Solid & s);
        void drawScore(int &p1Score,int &p2Score);
        void drawPause();
        void drawGameOver(int& p1Score,int &P2score );

};
#endif