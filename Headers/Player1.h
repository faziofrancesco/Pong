#ifndef PLAYER1_H
#define PLAYER1_H
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_color.h>
#include<cstring>
#include"Entity.h"

using namespace std; 
class Player1:public Entity{
    private: 
    public:
        Player1();
        Player1(float ,float ,float ,float,float, float);
        Player1(const  Player1 &);
        void MovePC(int x,float sx, float sy,int y,float ww,float wh, bool, int, int);

};

#endif
