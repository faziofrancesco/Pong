#include"../Headers/Player1.h"
Player1::Player1()
{
    x=0;
    y=0;
    speedx=1;
    speedy=1;
    dimw=4;
    dimh=4;
}
Player1::Player1(float a,float  b,float sx, float sy,float d,float d1)
{
    x=a;
    y=b;
    speedx=sx;
    speedy=sy;
    dimw=d;
    dimh=d1;
}
Player1::Player1(const Player1 & b)
{
    x=b.x;
    y=b.y;
    speedx=b.speedx;
    speedy=b.speedy;
    dimw=b.dimw;
    dimh=b.dimh;
}
void Player1::MovePC(int x,float sx, float sy,int y,float ww,float wh, bool hockey, int p1s, int p2s)
{
    //IL GIOCATORE INIZIA A MUOVERSI NON APPENA LA PALLA SUPERA LA META' DEL CAMPO
    if(x>ww/2)
    {
        if(y>=this->GetY()+(this->GetDimW()/2)) 
        {
            if(this->GetY()+this->GetSpeedy()<=wh-wh/6.25)
                this->SetY(this->GetY()+8);
        }
        else
        {
            if(this->GetY()-this->GetSpeedy()> 0)
                this->SetY(this->GetY()-8);
        }
    }
   
}