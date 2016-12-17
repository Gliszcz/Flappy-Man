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
#include "game_object.h"
#include <vector>
#include <stdlib.h>

using namespace std;
struct Game
{
    bool running = true;
    bool running_game = true;
    int FPS = 60,rand_Y;
    const int space_obstacle = 500;
    const int window_width = 1920;
    const int window_hight = 1080;
    vector <Game_Object*> Objects;
    vector <Game_Object*> Obstacles;
    ALLEGRO_DISPLAY *window = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *ground = NULL;
    ALLEGRO_BITMAP *superman = NULL;
    ALLEGRO_BITMAP *obstacle_up = NULL;
    ALLEGRO_BITMAP *obstacle_down = NULL;
    ALLEGRO_BITMAP *score_box = NULL;
    ALLEGRO_EVENT ev;
    Superman *superman_pointer;

    void Init()                                 // INIT
    {
        al_init();
        al_install_keyboard();
        al_init_image_addon();
        al_init_font_addon();
    }
    
    void Load_Files()                           // LOAD FILES
    {
        background = al_load_bitmap("background.jpg");
        ground = al_load_bitmap("ground.jpg");
        superman = al_load_bitmap("superman.png");
        obstacle_up = al_load_bitmap("obstacle_up.png");
        obstacle_down = al_load_bitmap("obstacle_down.png");
        score_box = al_load_bitmap("score_box.png");
        
    }
    void Allegro_Begin_Func()                   // ALLEGRO BEGINNING FUNC
    {
        superman_pointer = new Superman(superman,NULL,400,460,&ev);
        timer = al_create_timer(1.0 / FPS);
        window = al_create_display(window_width, window_hight);
        event_queue = al_create_event_queue();
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_display_event_source(window));
        al_start_timer(timer);
        Objects.push_back(new  Background(background,NULL, 0, 0, &ev));
        Objects.push_back(new Ground(ground,NULL, 0, 1030, &ev));
        Objects.push_back(superman_pointer);
        Objects.push_back(new Score(score_box,NULL,30,30,&ev)); 
        for(int i=0; i<5*space_obstacle; i+=space_obstacle)
        {
            rand_Y = rand()%700-900;
            Obstacles.push_back(new Obstacle(obstacle_up,obstacle_down, 1920+i, rand_Y, &ev));
        }
    
    }
    void Start()                                // START
    {
        while (running)
        {
            GetInput();
            Update();
            Draw();
            Detect_Collision_With_Obstacle();
        }
    }
    
    void CleanUp()
    {
        al_destroy_display(window);
        for(int i=0; i<Objects.size(); i++)
            delete Objects[i];
        for(int i=0; i<Obstacles.size(); i++)
            delete Obstacles[i];
    }
    
    void GetInput()
    {
        al_wait_for_event(event_queue, &ev);
    }
    
    void Update()
    {
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            running = false;
        
        for(int i=0; i<Objects.size(); i++)
            Objects[i]-> Update_Object(ev);
        
        for(int i=0; i<Obstacles.size(); i++)
        {
            Obstacles[i]->Update_Object(ev);
            
        }
        if(superman_pointer->kolizja == true)
        {
            al_show_native_message_box(window, "WARNING", "COLLISION", "COLLISION DETECTED", NULL, ALLEGRO_MESSAGEBOX_WARN);
            running = false;
        }
    }
    
    void Draw()
    {
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            for(int i=0; i<Objects.size(); i++)
                Objects[i]-> Draw_Object();
            for(int i=0; i<Obstacles.size(); i++)
                Obstacles[i]->Draw_Object();

        al_flip_display();
        }
    }
    
    void Detect_Collision_With_Obstacle()
    {
            for(int i=0; i<Obstacles.size(); i++)
                Obstacles[i]->Collision(superman_pointer);
    }
};
#endif /* game_hpp */
