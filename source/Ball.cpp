#include "../Headers/Ball.h"

Ball::Ball()
{
    x = 0;
    y = 0;
    speedx = 4;
    speedy = 4;
    dimw = 10;
}
Ball::Ball(float a, float b, float sx, float sy, float radius)
{
    x = a;
    y = b;
    speedx = sx;
    speedy = sy;
    dimw = radius;
}
Ball::Ball(const Ball &b)
{
    x = b.x;
    y = b.y;
    speedx = b.speedx;
    speedy = b.speedy;
    dimw = b.dimw;
}

//COLLISIONE CHE TIENE CONTO DI: POSIZIONE X, POSIZIONE Y, SCALA X, SCALA Y, POSIZIONE DEFAULT X, POSIZIONE DEFAULT Y, P1, P2, 
void Ball::Collision(float &x1, float &y1, float rx, float ry, Player &p,Player1 &p2,int ww,int wh, int &score1, int &score2, bool &startstate, bool &hockey,Sound *s)
{
  bool chk=false;
  //COLLISIONE MURO SUPERIORE
  if (this->GetY()+this->GetSpeedy() <= this->GetDimW()+wh/160)
  {
    if (this->GetSpeedy() <= 15)
      this->SetSpeedy(GetSpeedy()+1.5);
    y1 = speedy;
    chk=true;
  }
  //COLLISIONE MURO INFERIORE
  else if (this->GetY()+this->GetSpeedy() >= wh-wh/160-this->GetDimW())
  {
    if (this->GetSpeedy() <= 15)
      this->SetSpeedy(GetSpeedy()+1.5);
    y1 = speedy*-1;
    chk=true;
  }

  //COLLISIONE GIOCATORE 1 FRONT
  else if ((this->GetX()-this->GetDimW()-this->GetSpeedx() <= p.GetEndW() && (this->GetX()-this->GetDimW()-this->GetSpeedx() >= p.GetX()) && (this->GetY()+this->GetDimW() >= p.GetY() && this->GetY() <= p.GetEndH()+this->GetDimW())))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx;
    chk=true;
  }

  //COLLISIONE GIOCATORE 1 BACK
  else if ((this->GetX()+this->GetDimW()+this->GetSpeedx() >= p.GetX() && this->GetX()+this->GetDimW()+this->GetSpeedx() <= p.GetEndW() && (this->GetY()+this->GetDimW() >= p.GetY() && this->GetY() <= p.GetEndH()+this->GetDimW())))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx * -1;
    chk=true;
  }

  // STESSO MOVIMENTO

  //COLLISIONE MURO SINISTRO
  else if (this->GetX()+this->GetSpeedx() <= this->GetDimW()+ww/160 && ((this->GetY()+this->GetSpeedy() < wh/3) || (this->GetY()+this->GetSpeedy() > wh-wh/3)) && hockey)
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx;
    chk=true;
  }
  //PUNTO P2 HOCKEY
  else if (this->GetX()+this->GetSpeedx() <= this->GetDimW()+ww/160 && !((this->GetY()+this->GetSpeedy() < wh/3) || (this->GetY()+this->GetSpeedy() > wh-wh/3)) && hockey)
  {
    this->SetX(rx);
    this->SetY(ry);
    speedx = 0;
    speedy = 0;
    x1 = 0;
    y1 = 0;
    score2++;

    //RESET POSIZIONI
    startstate = true;
    p.SetX(20);
    p.SetY(float((wh / 2.0) - (dimh / 2.0)));
    p2.SetX(float(ww)-ww/20);
    p2.SetY(float((wh/ 2.0) - (dimh / 2.0)));
    }

  //COLLISIONE MURO DESTRO
  else if (this->GetX()+this->GetSpeedx() >= ww - ww/160-this->GetDimW() && ((this->GetY()+this->GetSpeedy() < wh/3) || (this->GetY()+this->GetSpeedy() > wh-wh/3)) && hockey)
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx * -1;
    chk=true;
  }
  //PUNTO P1 HOCKEY
  else if (this->GetX()+this->GetSpeedx() >= ww - ww/160-this->GetDimW() && !((this->GetY()+this->GetSpeedy() < wh/3) || (this->GetY()+this->GetSpeedy() > wh-wh/3)) && hockey)
  {
    this->SetX(rx);
    this->SetY(ry);
    speedx = 0;
    speedy = 0;
    x1 = 0;
    y1 = 0;
    score1++;

    //RESET POSIZIONI
    startstate = true;
    p.SetX(20);
    p.SetY(float((wh / 2.0) - (dimh / 2.0)));
    p2.SetX(float(ww)-ww/20);
    p2.SetY(float((wh/ 2.0) - (dimh / 2.0)));
  }

  //PUNTO P1 PONG
  else if (this->GetX() > p2.GetX() && !hockey)
  {
    this->SetX(rx);
    this->SetY(ry);
    speedx = 0;
    speedy = 0;
    x1=0;
    y1=0;
    score1++;

    //RESET POSIZIONI
    startstate = true;
    p.SetX(20);
    p.SetY(float((wh / 2.0) - (dimh / 2.0)));
    p2.SetX(float(ww)-ww/20);
    p2.SetY(float((wh/ 2.0) - (dimh / 2.0)));
  }

  //COLLISIONE GIOCATORE 2 FRONT
  else if ((this->GetX()+this->GetDimW()+this->GetSpeedx() >= p2.GetX() && this->GetX()+this->GetDimW()+this->GetSpeedx() <= p2.GetEndW()) && (this->GetY()+this->GetDimW() >= p2.GetY() && this->GetY() <= p2.GetEndH()+this->GetDimW()))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx * -1;
    chk=true;
  }

  //COLLISIONE GIOCATORE 2 BACK
  else if ((this->GetX()-this->GetDimW()-this->GetSpeedx() <= p2.GetEndW() && this->GetX()-this->GetDimW()-this->GetSpeedx() >= p2.GetX()) && (this->GetY()+this->GetDimW() >= p2.GetY() && this->GetY() <= p2.GetEndH()+this->GetDimW()))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx;
    chk=true;
  }

  //PUNTO P2 PONG
  else if (this->GetX() < p.GetEndW() && !hockey)
  {
    this->SetX(rx);
    this->SetY(ry);
    speedx = 0;
    speedy = 0;
    x1 = 0;
    y1 = 0;
    score2++;

    //RESET POSIZIONI
    startstate = true;
    p.SetX(20);
    p.SetY(float((wh / 2.0) - (dimh / 2.0)));
    p2.SetX(float(ww)-ww/20);
    p2.SetY(float((wh/ 2.0) - (dimh / 2.0)));
  }
  this->SetY(y+y1);
  this->SetX(x+x1);
  if(chk==true)
    s->playPong();
}

void Ball::CollisionSolid(float &x1, float& y1, Solid s, bool b,Sound *so)
{

  //COLLISIONE SOLIDO UP
  bool chk=false;
  if ((this->GetY()+this->GetSpeedy()+this->GetDimW() <= s.GetEndH() && this->GetY()+this->GetSpeedy()+this->GetDimW() >= s.GetY()) && (this->GetX()+this->GetSpeedx() >= s.GetX() && this->GetX()+this->GetSpeedx() <= s.GetEndW()))
  {
      if (this->GetSpeedy() <= 15)
        this->SetSpeedy(GetSpeedy()+1.5);
      y1 = speedy * -1;
      chk=true;
  }
  //COLLISIONE SOLIDO DOWN
  else if ((this->GetY()+this->GetSpeedy()-this->GetDimW() <= s.GetEndH() && this->GetY()+this->GetSpeedy()+this->GetDimW() >= s.GetY()) && (this->GetX()+this->GetSpeedx() >= s.GetX() && this->GetX()+this->GetSpeedx() <= s.GetEndW()))
  {
    if (this->GetSpeedy() <= 15)
      this->SetSpeedy(GetSpeedy()+1.5);
    y1 = speedy;
    chk=true;
  }

  //COLLISIONE SOLIDO DX
  else if ((this->GetX()-this->GetDimW()-this->GetSpeedx() <= s.GetEndW() && (this->GetX()-this->GetDimW()-this->GetSpeedx() >= s.GetX()+s.GetDimH()/2) && (this->GetY()+this->GetDimW() >= s.GetY() && this->GetY() <= s.GetEndH()+this->GetDimW())))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx;
    chk=true;
  }

  //COLLISIONE SOLIDO SX
  else if ((this->GetX()+this->GetDimW()+this->GetSpeedx() >= s.GetX() && (this->GetX()+this->GetDimW()+this->GetSpeedx() <= s.GetEndW()-s.GetDimW()/2) && (this->GetY()+this->GetDimW() >= s.GetY() && this->GetY() <= s.GetEndH()+this->GetDimW())))
  {
    if (this->GetSpeedx() <= 15)
      this->SetSpeedx(GetSpeedx()+1.5);
    x1 = speedx *-1;
    chk=true;
  } 
  if(chk==true)
  so->playPong();
}