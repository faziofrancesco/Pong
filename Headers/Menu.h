#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Sound.h"
#include <iostream>
using namespace std;
#ifndef MENU_H
#define MENU_H
class Menu
{
    private:
        int scale_w;      
        int scale_h;
        int scale_x;
        int scale_y;
        int wind_h,wind_w;
       
        ALLEGRO_DISPLAY * display;
        ALLEGRO_BITMAP * buffer;
        ALLEGRO_FONT * font1;
        ALLEGRO_FONT * temp;

    public:
        ALLEGRO_DISPLAY* getDisplay(){return display;}
        Menu();
        Menu(const int&, const int& ,const int&, const int&, ALLEGRO_BITMAP *, ALLEGRO_DISPLAY *,int,int);
        ~Menu() {}  
        int menu(int,Sound *);
        void cambia(int);
        void iniziale(int);
        void principale(); void disegnaPrincipale(int);
};
#endif