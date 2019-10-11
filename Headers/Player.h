#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_color.h>
#include<cstring>
#include"Entity.h"
using namespace std; 
class Player:public Entity{
    private: 
    public:
        Player();
        Player(float ,float ,float ,float,float, float);
        Player(const  Player &);
        









};
#endif