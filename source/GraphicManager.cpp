#include"../Headers/GraphicManager.h"
GraphicManager::GraphicManager(float  ww,float wh,ALLEGRO_FONT *f,ALLEGRO_FONT *f2,ALLEGRO_FONT *f3)
{
    windowWidth=ww;
    windowHeight=wh;
    font=f;
    font2=f2;
    font3=f3;
}
void GraphicManager::drawField(bool hockey)
{
    //DISEGNA IL CAMPO DA GIOCO TRAMITE PRIMITIVE
    al_draw_filled_rounded_rectangle(0, 0, windowWidth, windowHeight, 0, 0, al_color_html("ffffff"));
    al_draw_filled_rounded_rectangle(windowWidth/160, windowHeight/160, windowWidth-windowWidth/160, windowHeight-windowHeight/160, 0, 0, al_color_html("003366"));
     if(hockey)
    {
        al_draw_filled_rounded_rectangle(0, windowHeight/3, windowWidth, windowHeight - windowHeight/3, 0, 0, al_color_html("003366"));
        al_draw_filled_circle(windowWidth/2, windowHeight/2, windowHeight/5, al_color_html("afafaf"));
        al_draw_filled_circle(windowWidth/2, windowHeight/2, windowHeight/5.5, al_color_html("003366"));
    }
    al_draw_filled_rounded_rectangle((windowWidth/2)-3, 0, (windowWidth/2)+3, windowHeight, 0, 0, al_color_html("ffffff"));
    al_draw_filled_circle(windowWidth/2, windowHeight/2, windowHeight/50, al_color_html("afafaf"));    
}
void GraphicManager::drawPause()
{
    al_draw_text(font, al_map_rgb(255,255,255), windowWidth/2, windowHeight/2, ALLEGRO_ALIGN_CENTER, "PAUSA");
    al_draw_text(font2, al_map_rgb(255,255,255), windowWidth/2,windowHeight/2+windowHeight/12, ALLEGRO_ALIGN_CENTER, "Premi Enter per tornare al gioco oppure x per il menu");
}
void GraphicManager::drawScore(int &p1score,int &p2score)
{
    al_draw_textf(font3, al_map_rgb(255,255,255), windowWidth/25, windowHeight/20, ALLEGRO_ALIGN_LEFT, "%i", p1score); //PUNTEGGIO P1
    al_draw_textf(font3, al_map_rgb(255,255,255), windowWidth-windowWidth/25, windowHeight/20, ALLEGRO_ALIGN_RIGHT, "%i", p2score); //PUNTEGGIO P2
}
void GraphicManager::drawGameOver(int &p1score,int &p2score)
{
    if (p1score == 5)
    {
        al_draw_text(font, al_map_rgb(255,255,255), windowWidth/2, windowHeight/2, ALLEGRO_ALIGN_CENTER, "P1 HA VINTO!");
    }
    else if (p2score == 5)
    {
        al_draw_text(font, al_map_rgb(255,255,255), windowWidth/2, windowHeight/2, ALLEGRO_ALIGN_CENTER, "P2 HA VINTO!");
    }
}
void GraphicManager::drawObject(bool & obstacle,Ball &b,Player & p,Player1 & p1,Solid & s)
{
    //DISEGNA PALLINA
    // fill
    al_draw_filled_circle(b.GetX(), b.GetY(), b.GetDimW(), al_color_html("6be97d"));
    // shadow
    al_draw_filled_circle(b.GetX()+ b.GetDimW() / 4, b.GetY() + b.GetDimH() / 4, b.GetDimW() / 3 * 2, al_color_html("59ce76"));
    // shine
    al_draw_filled_circle(b.GetX() - b.GetDimW() / 3, b.GetY() - b.GetDimH() / 3, b.GetDimH() / 4, al_color_html("9bffaa"));
    
                
    //DISEGNA GIOCATORE 1
    al_draw_filled_rounded_rectangle(p.GetX(), p.GetY(), p.GetX()+p.GetDimW(), p.GetY()+p.GetDimH(), 3, 3, al_color_html("009933"));

    //DISEGNA GIOCATORE 2
    al_draw_filled_rounded_rectangle(p1.GetX(), p1.GetY(), p1.GetX()+p1.GetDimW(), p1.GetY()+p1.GetDimH(), 3, 3, al_color_html("993300"));


    //DISEGNA IL SOLIDO, SE NECESSARIO
    if(obstacle==true){
       al_draw_filled_rounded_rectangle(s.GetX(), s.GetY(), s.GetX()+s.GetDimW(), s.GetY()+s.GetDimH(), 3, 3, al_color_html("ffffff"));
       al_draw_filled_rounded_rectangle(s.GetX()+10, s.GetY()+10, s.GetX()+s.GetDimW()-10, s.GetY()+s.GetDimH()-10, 3, 3, al_color_html("cc0000"));
    }
}