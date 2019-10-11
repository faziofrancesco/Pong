#ifndef BALL_H
#define BALL_H
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_color.h>
#include"Entity.h"
#include"Solid.h"
#include"Player.h"
#include"Player1.h"
#include "Sound.h"
#include<cstring>
using namespace std;
class Ball:public Entity{
    private:
    public:
        Ball();
        Ball(float a,float b,float sx, float sy,float dw);
        Ball(const Ball & b);
    
        void Collision(float &x1,float &y1,float rx,float ry,Player& p,Player1& p2,int,int, int&, int&, bool&, bool&,Sound *s);
        void CollisionSolid(float &x1,float &y1,Solid s,bool c,Sound *so);
    
};
#endif 