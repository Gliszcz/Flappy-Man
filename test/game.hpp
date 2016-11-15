//
//  game.hpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 15.11.2016.
//  Copyright © 2016 Adam Gliszczński. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
struct Game
{
    bool running = true;
    int FPS = 60;
    const int window_hight = 1080;
    const int window_width = 1920;
    ALLEGRO_DISPLAY *window = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *ground = NULL;
    
    void Init()                                 // INIT
    {
        al_init();
        al_install_keyboard();
        al_init_image_addon();
    }
    void Load_Files()                           // LOAD FILES
    {
        background = al_load_bitmap("background.jpg");
    }
    void Allegro_Begin_Func()                   // ALLEGRO BEGINNING FUNC
    {
        timer = al_create_timer(1.0 / FPS);
        window = al_create_display(window_width, window_hight);
        event_queue = al_create_event_queue();
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_display_event_source(window));
        al_start_timer(timer);
    }
    void Start()                                // START
    {
        while (running)
        {
            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;
            
            else if (ev.type == ALLEGRO_EVENT_TIMER)
            {
                al_draw_bitmap(background, 0, 0, 0);
            }
            al_flip_display();
            
        }
    }
    void CleanUp()
    {
        al_destroy_display(window);

    }
    
};
#endif /* game_hpp */
