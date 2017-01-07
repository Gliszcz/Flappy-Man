//
//  game.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "game.hpp"

Game::Game()                                 // INIT
{
    Load_Files();
    superman_pointer = new Superman(superman,NULL,400,60,&ev);
    score_pointer = new Score(NULL,NULL,30,30,&ev);
    Objects.push_back(new  Background(background,NULL, 0, 0, &ev));
    Objects.push_back(new Ground(ground,NULL, 0, 1030, &ev));
    Objects.push_back(superman_pointer);
    Objects.push_back(score_pointer);
    for(int i=0; i<5*space_obstacle; i+=space_obstacle)
    {
        rand_Y = rand()%700-900;
        Obstacles.push_back(new Obstacle(obstacle_up,obstacle_down, 1920+i, rand_Y, &ev));
    }
}

void Game::Load_Files()                           // LOAD FILES
{
    background = al_load_bitmap("background.jpg");
    ground = al_load_bitmap("ground.jpg");
    superman = al_load_bitmap("superman.png");
    obstacle_up = al_load_bitmap("obstacle_up.png");
    obstacle_down = al_load_bitmap("obstacle_down.png");
    main_menu_exit = al_load_bitmap("exit.png");
    main_menu_new_game = al_load_bitmap("new_game.png");
    game_over_new_game = al_load_bitmap("game_over_new_game.png");
    game_over_go_to_menu = al_load_bitmap("game_over_go_to_menu.png");
    
}

void Game::CleanUp()
{
    for(int i=0; i<Objects.size(); i++)
        delete Objects[i];
    for(int i=0; i<Obstacles.size(); i++)
        delete Obstacles[i];
}

void Game::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void Game::Update()
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
        stringstream strs;
        strs << score_pointer->score_int/3;
        string tmp = strs.str();
        const char* score_char = (char*)tmp.c_str();
        al_show_native_message_box(window, "GAME OVER! YOUR SCORE : ", "GAME OVER !",  score_char, NULL, ALLEGRO_MESSAGEBOX_WARN);
        running = false;
    }
}

void Game::Draw()
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

void Game::Detect_Collision_With_Obstacle_And_Points()
{
    for(int i=0; i<Obstacles.size(); i++)
        Obstacles[i]->Collision(superman_pointer,score_pointer);
}
