#ifndef ENTITY_H
#define ENTITY_H
#include<cstring>
#include<iostream>

using namespace std;
class Entity{
    protected:
        float x;
        float y;
        float speedx;
        float speedy;
        float dimw;
        float dimh;

    public:
        Entity();
        Entity(float, float, float, float, float, float);
        Entity(const Entity & e);
        void SetX(float x);
        void SetY(float y);
        void SetSpeedx(float sx);
        void SetSpeedy(float sy);
        void SetDimW(float dw);
        void SetDimH(float dh);
        float GetX();
        float GetY();
        float GetSpeedx();
        float GetSpeedy();
        float GetDimW();
        float GetDimH();
        float GetEndH();
        float GetEndW();
};
#endif