#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "../Headers/Ball.h"
#include "../Headers/Player.h"
#include "../Headers/Solid.h"
#include "../Headers/Player1.h"
#include "../Headers/Sound.h"
#include"../Headers/Menu.h"
#include"../Headers/GraphicManager.h"
#include"../Headers/LogicManager.h"
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

//DICHIARAZIONE DEGLI STATI DI GIOCO
enum GAME_STATES{PAUSA, GAMEPLAY, GAMEOVER};

//VARIABILI DEI COMANDI
enum MYKEYS{UP, DOWN, LEFT, RIGHT, ESCAPE, ENTER, SPACE, UP2, DOWN2, SINGLE, LEFT2, RIGHT2};
bool key[12] = {false, false, false, false, false, false, false, false, false, false, false, false};

int main()
{
    srand (time(0));
    if (!al_init()) //controlla se si è inizializzato allegro
    {
        cerr << "init_error: failed to initialize Allegro!\n";
        return -1;
    }

   
    //FPS
    ALLEGRO_TIMER *timer{al_create_timer(1.0/60)};
 
    //RISOLUZIONE DINAMICA DISPLAY
    ALLEGRO_DISPLAY       *display = NULL;
    ALLEGRO_DISPLAY_MODE   disp_data;
    al_get_display_mode(0, &disp_data);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(disp_data.width, disp_data.height);  

    if(!display){
        cout << "Fatal error, unable to create a display";
        return -1;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "failed to install keyboard\n");
        return -1;
    }

    if (!timer)
    {
        cerr << "time_error: failed to initialize timer!\n";
        return -1;
    }
    if (!al_init_acodec_addon()){
        return -1;
    }
    if (!al_install_audio()){
        return -1;
    }

    int windowHeight = al_get_display_height(display);
    int windowWidth = al_get_display_width(display);

    //DIMENSIONE PALLINA
    const float dim = windowHeight/30;

    ALLEGRO_BITMAP* buffer=al_create_bitmap(windowWidth,windowHeight);
    if(!buffer) std::cout<<"Errore inizializzazione buffer"; 
    if(!al_install_mouse()){cout << "Fatal error, Allegro 5 failed to start";return -1;}
    float sx = windowWidth / float(windowWidth);
    float sy = windowHeight / float(windowHeight);
    float scale = std::min(sx, sy);
    float scaleW = windowWidth* scale;
    float scaleH = windowHeight * scale;
    float scaleX = (windowWidth - scaleW) / 2;
    float scaleY = (windowHeight - scaleH) / 2;
    float x,y;

    //STATO DI GIOCO INIZIALE
    int gamestate = GAMEPLAY;
    //POSIZIONA PALLA, GIOCATORE 1, GIOCATORE 2 E SOLIDO, SE NECESSARIO
    
    Ball b(windowWidth/2, windowHeight/2, 1, 1, dim); 
    Player p(windowWidth/20, ((scaleH / 2) - (windowHeight/12.50)), 4, 4, windowWidth/50, windowHeight/6.25);
    Player1 p1((scaleW)-(windowWidth/20) , ((scaleH / 2) - (windowHeight/12.50)), 5, 5, windowWidth/50, windowHeight/6.25);
    Solid s((scaleW/2) ,(scaleH/2)-windowHeight/4,0, 0,windowHeight/6.25,windowHeight/6.25);


    al_clear_to_color(al_map_rgb(255, 0, 255));                //modifico i colori
    al_set_target_bitmap(al_get_backbuffer(display));          //prende come bitmap il backbuffer del display
    al_init_primitives_addon();                                //inzializza le primitive
    al_init_font_addon();                                      // INIZIALIZZO I FONT
    al_init_ttf_addon();                                       // INIZIALIZZO I TTF
    ALLEGRO_FONT *font = al_load_font("../font/arial.ttf", windowWidth/20, 0);     //CARICO I FONT
    ALLEGRO_FONT *font2 = al_load_font("../font/arial.ttf", windowWidth/30, 0);     //
    ALLEGRO_FONT *font3 = al_load_font("../font/arial.ttf", windowWidth/15, 0); 
    ALLEGRO_EVENT_QUEUE *event_queue{al_create_event_queue()}; //creo la coda degli eventi
    if (!event_queue)                                          //vedo se la coda e stata creata
    {
        cerr << "evqueue_error: failed to initialize queue!\n";

        al_destroy_display(display); //distruggo il display
        al_destroy_timer(timer);     //distruggo il timer
        return -1;
    }

    //REGISTRO GLI EVENTI NELLA CODA DI EVENTI
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue,al_get_keyboard_event_source());

    //GENERO UNO SCHERMO NERO
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //DISEGNO SU SCHERMO
    al_flip_display();

    //RESETTO IL TIMER
    al_start_timer(timer);
    

    //VARIABILI DI MODALITA'
    bool hockey = false;
    bool obstacle = false;
    bool Player2 = false;
    bool IsMenu=true;
    int p1score=0,p2score=0;
    

     //SOUNDS MANAGER
    al_reserve_samples(2);
    Sound *sound=new Sound();
    Sound * sound1=new Sound();
    Sound *sound2=new Sound();
    //GRAPHIC MANAGER
    GraphicManager gm(windowWidth,windowHeight,font,font2,font3);
    //MENU MANAGER 
    Menu m(scaleW,scaleH,scaleX,scaleY,buffer,display,windowHeight,windowWidth);
    //LOGIC MANAGER
    LogicManager lm(windowWidth,windowHeight);
    int tipo=0;
    int startGame=0;
    al_show_mouse_cursor(display);
    al_set_window_title(display,"Pong Arcade"); 
    while(true)
    {
        bool startstate = false;
        
        tipo = m.menu(0,sound2);
        al_clear_to_color(al_map_rgb(255, 0, 255));               
        al_set_target_bitmap(al_get_backbuffer(display));

        if(tipo==1){
            hockey = false;
            obstacle = false;
            Player2 = false;
            startGame=1;   
        }

        if(tipo==2){
            hockey = false;
            obstacle = true;
            Player2 = false;
            startGame=1;
        }

        if(tipo==3){
            hockey = false;
            obstacle = false;
            Player2 = true;
            startGame=1;
        }
        if(tipo==4){
            hockey = true;
            obstacle = false;
            Player2 = true;
            startGame=1;
        }
        //INIZIO GIOCO
      
            lm.GameLogic(sound,sound2,tipo,p1,p,b,s,obstacle,hockey,Player2,gm,event_queue,startGame,scaleH,scaleW);
        
        lm.restarter(sound,sound2,tipo,p1,p,b,scaleH);
    
    }
    
    //DISTRUZIONE 
    al_destroy_timer(timer);
    al_uninstall_keyboard();
    delete sound ;
    delete sound1;
    delete sound2;
    al_uninstall_audio();
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(buffer);

    return 0;
}