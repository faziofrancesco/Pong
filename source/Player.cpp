#include"../Headers/Player.h"
Player::Player()
{
    x=0;
    y=0;
    speedx=1;
    speedy=0;
    dimw=4;
    dimh=4;
}
Player::Player(float a,float  b,float sx, float sy, float dw, float dh)
{
    x=a;
    y=b;
    speedx=sx;
    speedy=sy;
    dimw=dw;
    dimh=dh;
}
Player::Player(const Player & b)
{
    x=b.x;
    y=b.y;
    speedx=b.speedx;
    speedy=b.speedy;
    dimw=b.dimw;
    dimh=b.dimh;
}
