#include "../Headers/Sound.h"
#include "../Headers/Menu.h"
#include <allegro5/allegro_primitives.h>

    Menu::Menu() {}

    Menu::Menu(const int &scale_w, const int &scale_h, const int &scale_x, const int &scale_y, ALLEGRO_BITMAP *buffer, ALLEGRO_DISPLAY *display, int windowHeight,int windowWidth)
    {
        this->scale_h = scale_h;
        this->scale_w = scale_w;
        this->scale_x = scale_x;
        this->scale_y = scale_y;
        this->wind_h = windowHeight;
        this->wind_w = windowWidth;
        this->buffer = buffer;
        this->display = display;
        this->font1 = al_load_ttf_font("../font/Caribbean.ttf", 30, 0);
        this->temp = font1;
        if (!font1){ cout<<"menu font1 error"; exit(1);}

    }

    void Menu :: principale()
    {
        al_draw_textf(temp, al_map_rgb(203, 50, 52), 0, 0, 0, "PONG");
        al_draw_textf(temp, al_map_rgb(255, 255, 255), 210, 30, 0, "PONG 1PL");
        al_draw_textf(temp, al_map_rgb(255, 255, 255), 210, 110, 0, "OBSTACLE");
        al_draw_textf(temp, al_map_rgb(255, 255, 255), 210, 180, 0, "PONG 2PL ");
        al_draw_textf(temp, al_map_rgb(255, 255, 255), 210, 247, 0, "HOCKEY 2PL");
    }

    void Menu :: disegnaPrincipale(int stato)
    {
        switch (stato)
        {
            case 0: al_draw_rectangle(210,30,220+200,70,al_map_rgba(120,120,120,120),2); break;

            case 1: al_draw_rectangle(210,110,210+200,110+40,al_map_rgba(120,120,120,120),2); break;
        
            case 2:  al_draw_rectangle(185,175,210+200,175+45,al_map_rgba(120,120,120,120),2); break;

            case 3: al_draw_rectangle(210,245,220+250,245+40,al_map_rgba(120,120,120,120),2); break;
            

            default:
                break;
        }
    }

   



    void Menu :: cambia(int num)
    {
        switch (num)
        {
            case 0: principale(); break;

           
            default:
                break;
        }
    }

    void Menu :: iniziale(int num){
        switch (num)
        {
            case 0: al_draw_rectangle(210,30,210+200,70,al_map_rgba(120,120,120,120),2); break;
        
        default:
            break;
        }
    }

    int Menu::menu(int num, Sound  * audio)
    {
        al_set_target_bitmap(buffer);
        ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
        int stato = 0;
        al_clear_to_color(al_map_rgb(0, 0, 0)); 
        cambia(num);
        iniziale(num);
        al_set_target_bitmap(al_get_backbuffer(display)); // assegnamo alla bitmap i colori del display
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_scaled_bitmap(buffer, 0, 0, 560, 320, scale_x, scale_y, scale_w, scale_h, 0);
        al_flip_display(); // visualizza il cambiamento
        al_set_target_bitmap(buffer);
        al_register_event_source(queue, al_get_mouse_event_source()); // leghiamo il display alla coda di eventi per poi essere gestito, altrimenti non verrebbe visto.
        al_register_event_source(queue, al_get_keyboard_event_source()); // serve per uscire con esc
        ALLEGRO_BITMAP * btp = al_create_bitmap(140, 40);
        
        while(true)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0)); 
            cambia(num);
            ALLEGRO_EVENT ev;
            al_wait_for_event(queue, &ev);

            switch (ev.type)
            {
                case ALLEGRO_EVENT_KEY_UP:
                        audio->ChangeGame();
                        if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE) exit(1); 
                            
                        if(ev.keyboard.keycode==ALLEGRO_KEY_UP and stato!=0) stato--;
                        
                        if(ev.keyboard.keycode==ALLEGRO_KEY_DOWN and stato!=3) stato++;
                        
                        switch (num)
                        {
                            case 0:
                                disegnaPrincipale(stato);
                                if (ev.keyboard.keycode==ALLEGRO_KEY_ENTER and stato==0){
                                    audio->SelectGame();              
                                    return 1;

                                }
                                else if (ev.keyboard.keycode==ALLEGRO_KEY_ENTER and stato==1){   
                                        audio->SelectGame();          
                                    return 2;

                                }
                                else if (ev.keyboard.keycode==ALLEGRO_KEY_ENTER and stato==2){
                                         audio->SelectGame();   
                                    return 3;

                                }
                                else if (ev.keyboard.keycode==ALLEGRO_KEY_ENTER and stato==3){
                                         audio->SelectGame();   
                                    return 4;

                                }
                            break;
                            

                            default:
                                break;
                        }
            }
            al_set_target_bitmap(al_get_backbuffer(display));
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_scaled_bitmap(buffer, 0, 0, 560, 320, scale_x, scale_y, scale_w, scale_h, 0);
            al_flip_display();
            al_set_target_bitmap(buffer);
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_flush_event_queue(queue);
        }
        al_destroy_event_queue(queue);
        return stato;
    }



   