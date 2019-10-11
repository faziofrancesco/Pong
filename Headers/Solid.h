#ifndef SOLID_H
#define SOLID_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_color.h>
#include"Entity.h"
#include<iostream>
#include<cstring>
using namespace std;
class Solid:public Entity{
    public:
        Solid();
        Solid(float a,float b,float sx, float sy,float d,float d1);
        Solid(const Solid & s);
};
#endif