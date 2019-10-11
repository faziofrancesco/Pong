#include"../Headers/Entity.h"
Entity::Entity()
{
    x=0;
    y=0;
    speedx=0.0;
    speedy=0.0;
    dimw=0;
    dimh=0;
}
Entity::Entity(float a,float b,float sx, float sy,float dw,float dh)
{
    x=a;
    y=b;
    speedx=sx;
    speedy=sy;
    dimw=dw;
    dimh=dh;
}
Entity::Entity(const Entity & e)
{
    x=e.x;
    y=e.y;
    speedx=e.speedx;
    speedy=e.speedy;
    dimw=e.dimw;
    dimh=e.dimh;
}
void Entity::SetX(float a)
{
    x=a;
}
void Entity::SetY(float b)
{
    y=b;
}
void Entity::SetSpeedx(float sx)
{
    speedx=sx;
}
void Entity::SetSpeedy(float sy)
{
    speedy=sy;
}
void Entity::SetDimH(float dh)
{
    dimh=dh;
}
void Entity::SetDimW(float dw)
{
    dimw=dw;
}
float Entity::GetX()
{
    return x;
}
float Entity::GetY()
{
    return y;
}
float Entity::GetSpeedx()
{
    return speedx;
}
float Entity::GetSpeedy()
{
    return speedy;
}
float Entity::GetDimW()
{
    return dimw;
}
float Entity::GetDimH()
{
    return dimh;
}
float Entity::GetEndH()
{
    return y+dimh;
}
float Entity::GetEndW()
{
    return x+dimw;
}