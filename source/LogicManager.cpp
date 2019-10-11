#include"../Headers/LogicManager.h"
LogicManager::LogicManager(float ww,float wh)
{
windowWidth=ww;
windowHeight=wh;
rx = ww/2;
ry = wh/2;
doexit = false;
redraw = true;
startstate = false;
p1score = 0;
p2score = 0;
gamestate=GAMEPLAY;
}
void LogicManager::restarter(Sound * sound, Sound * sound1, int & tipo, Player1 & p1, Player&p, Ball & b,int scaleH)
{
    startstate=false;
    bouncer_dx = direction_x[rand()%2];
    bouncer_dy = direction_y[rand()%3];
    b.SetX(rx);
    b.SetY(ry);
    b.SetSpeedx(0);
    b.SetSpeedy(0);
    p.SetX(windowWidth/20);
    p.SetY(((scaleH / 2) - (windowHeight/12.50)));
    p1.SetX(float(windowWidth)-windowWidth/20);
    p1.SetY(float((windowHeight/ 2.0) - (b.GetDimH() / 2.0)));
    tipo=0;
    doexit=false;
    sound->stopSounds();
    sound1->stopSounds();
    p1score=0;
    p2score=0;
}
void LogicManager::GameLogic( Sound * sound, Sound * sound1, int & tipo, Player1 & p1, Player&p, Ball & b,Solid & s, bool & obstacle,bool &hockey,bool &Player2,GraphicManager & gm,ALLEGRO_EVENT_QUEUE *event_queue,int &startGame,int scaleH,int scaleW)
{
     bool startstate = true;
     float bouncer_dx{0}, bouncer_dy{0};
     if(startGame==1 && tipo!=0)
        {
            sound->startGame();
            startstate=true;
            al_flush_event_queue(event_queue);
            gamestate = GAMEPLAY;
            while (!doexit)
            {
                ALLEGRO_EVENT ev;                    //creo un evento
                al_wait_for_event(event_queue, &ev); //aspetto l'evento

                //IMPLEMENTAZIONE DEGLI STATI DI GIOCO
                if (gamestate == GAMEPLAY)
                {

                    if(key[SPACE])
                    {
                    gamestate = PAUSA;
                    redraw = true;
                    }

                    if(key[ENTER])
                    {
                        if (startstate == true)
                        {
                            bouncer_dx = direction_x[rand()%2];
                            bouncer_dy = direction_y[rand()%3];
                            startstate = false;
                        }
                    }
                }

                else if (gamestate == PAUSA)
                {
                    if(key[ENTER])
                    {
                    gamestate = GAMEPLAY;
                    key[ENTER] = false;
                    }
                }   

                else if (gamestate == GAMEOVER)
                {
                    if(key[ESCAPE])
                    {
                    gamestate = GAMEPLAY;
                    key[ESCAPE] = false;
                    }
                }

                //GAMEPLAY   
                if (gamestate == GAMEPLAY)
                {      
                    if (ev.type == ALLEGRO_EVENT_TIMER)
                    {
                    //PLAYER 1 UP
                        if (key[UP] && p.GetY() >= 0+windowHeight/37.5 )
                            p.SetY(p.GetY() - 6.0);

                        //PLAYER 1 DOWN
                        if (key[DOWN] && p.GetY() <= scaleH-windowHeight/6.25)
                            p.SetY(p.GetY() + 6.0);
                
                        if(hockey)
                        {   

                        //PLAYER 1 LEFT
                            if (key[LEFT] && (p.GetX() >= windowWidth/40))
                                p.SetX((p.GetX() - 6.0));

                        //PLAYER 1 RIGHT
                        if ((key[RIGHT]) && (p.GetX() <= windowWidth/3.5))
                            p.SetX(p.GetX() + 6.0);
                        }

                        if (Player2)
                        {
                        //PLAYER 2 UP
                            if (key[UP2] && p1.GetY() >= 0+windowHeight/37.5 )
                            {
                                p1.SetY(p1.GetY() - 6.0);
                            }

                        //PLAYER 2 DOWN
                    
                            if (key[DOWN2] && p1.GetY() <= scaleH-windowHeight/6.25)
                            {
                                p1.SetY(p1.GetY() + 6.0);
                                
                            }

                            if (hockey)
                            {
                            //PLAYER 2 LEFT
                                if (key[LEFT2] && (p1.GetX() >= windowWidth/1.5))
                                {
                                    p1.SetX(p1.GetX() - 6.0);
                                }

                                //PLAYER 2 RIGHT
                                if ((key[RIGHT2]) && (p1.GetX() <= windowWidth-(p1.GetDimW()*5)))
                                {
                                    p1.SetX(p1.GetX() + 6.0);
                                }
                            }
                        }

                        //COLLISIONI DELLA PALLINA SUI MURI E PLAYER
        
                        b.Collision(bouncer_dx, bouncer_dy, rx, ry, p,p1, windowWidth, windowHeight, p1score, p2score, startstate, hockey,sound1);
                        //COLLISIONI DELLA PALLINA CON IL SOLIDO
                        if(obstacle==true)
                            b.CollisionSolid(bouncer_dx,bouncer_dy,s,obstacle,sound1);
                        //MOVIMENTI DELL'AVVERSARIO
            
                        if (!(Player2))
                        {
                            p1.MovePC(b.GetX(),b.GetSpeedx(),b.GetSpeedy(), b.GetY(), scaleW, scaleH, hockey, p1score, p2score);
                
                        }
                        redraw = true;
                    }
                }
                if (p1score == 5 || p2score == 5)
                    gamestate = GAMEOVER;

                //CHIUSURA DELL'APPLICAZIONE TRAMITE FINESTRA
                if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                    break;
                }

                //EVENTI ALLA PRESSIONE DEI TASTI
                if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
                {   
                    switch (ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_W:
                            key[UP] = true;
                        break;

                        case ALLEGRO_KEY_S:
                            key[DOWN] = true;
                        break;

                        case ALLEGRO_KEY_ESCAPE: //ESCE DAL GIOCO
                            key[ESCAPE] = true;
                        break;

                        case ALLEGRO_KEY_SPACE: //PAUSA
                            key[SPACE] = true;
                        break;

                        case ALLEGRO_KEY_ENTER: //RIPRENDE DALLA PAUSA - LANCIA LA PALLINA AD INIZIO GIOCO
                            key[ENTER] = true;
                        break;

                        case ALLEGRO_KEY_D: // P1 MUOVE A DESTRA
                            key[RIGHT] = true;
                        break;

                        case ALLEGRO_KEY_A: // P1 MUOVE A SINISTRA
                            key[LEFT] = true;
                        break;

                        case ALLEGRO_KEY_I: // P2 MUOVE IN ALTO
                            key[UP2] = true;
                        break;

                        case ALLEGRO_KEY_K:  // P2 MUOVE IN BASSO
                            key[DOWN2] = true;
                        break;

                        case ALLEGRO_KEY_J: // P2 MUOVE A SINISTRA
                            key[LEFT2] = true;
                        break;

                        case ALLEGRO_KEY_L: // P2 MUOVE A DESTRA
                            key[RIGHT2] = true;
                        break;
                    }
                }

                //EVENTI ESEGUITI AL RILASCIO DEL TASTO
                else if (ev.type == ALLEGRO_EVENT_KEY_UP)
                {
                    switch (ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_W:
                            key[UP] = false;
                        break;

                        case ALLEGRO_KEY_S:
                            key[DOWN] = false;
                        break;
                    
                        case ALLEGRO_KEY_ESCAPE:
                            doexit = true;
                        break;

                        case ALLEGRO_KEY_SPACE:
                            key[SPACE] = false;
                        break;

                        case ALLEGRO_KEY_ENTER:
                            key[ENTER] = false;
                        break;

                        case ALLEGRO_KEY_D:
                            key[RIGHT] = false;
                        break;

                        case ALLEGRO_KEY_A:
                            key[LEFT] = false;
                        break;
                    
                        case ALLEGRO_KEY_I:
                            key[UP2] = false;
                        break;

                        case ALLEGRO_KEY_K:
                            key[DOWN2] = false;
                        break;

                        

                        case ALLEGRO_KEY_P:
                            key[SINGLE] = false;
                        break;

                        case ALLEGRO_KEY_J:
                            key[LEFT2] = false;
                        break;

                        case ALLEGRO_KEY_L:
                            key[RIGHT2] = false;
                        break;
                    }
                }

                //SE LA CODA E' VUOTA E REDRAW E' TRUE, RIDISEGNA
                if (redraw && al_is_event_queue_empty(event_queue))
                {
                    redraw = false;

                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    if (gamestate == PAUSA)
                    //DISEGNA LA SCHERMATA DI PAUSA
                    {
                        gm.drawPause();
                    }   

                    else if (gamestate == GAMEOVER)
                    {
                        gm.drawGameOver(p1score,p2score);
                    }

                    else if (gamestate == GAMEPLAY)
                    {
                       gm.drawField(hockey);
                       gm.drawScore(p1score,p2score);
                       gm.drawObject(obstacle,b,p,p1,s);
                    }

                    //EFFETTUA EFFETTIVAMENTE IL REDRAW
                    al_flip_display();
                }
            }
        }
}
