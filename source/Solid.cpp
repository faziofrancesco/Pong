#include"../Headers/Solid.h"
Solid::Solid(){
    x=0.0;
    y=0.0;
    dimw=0;
    dimh=0;
    speedx=0.0;
    speedy=0.0;
}
Solid::Solid(float a,float b,float sx, float sy, float d,float d1){
    x=a;
    y=b;
    speedx=sx;
    speedy=sy;
    dimw=d;
    dimh=d1;
}
Solid::Solid(const Solid & s){
    x=s.x;
    y=s.y;
    speedx=s.speedx;
    speedy=s.speedy;
    dimw=s.dimw;
    dimh=s.dimh;
}
