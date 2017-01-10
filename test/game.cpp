//
//  game.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "game.hpp"
#include "Scene_menager.h"

Game::Game()
{
    Load_Files();
    superman_pointer = new Superman(superman,nullptr,400,60,&ev);
    score_pointer = new Score(nullptr,nullptr,30,30,&ev);
    Objects.push_back(new  Background(background,nullptr, 0, 0, &ev));
    Objects.push_back(new Ground(ground,nullptr, 0, 1030, &ev));
    Objects.push_back(superman_pointer);
    Objects.push_back(score_pointer);
    int j=0;
    for(int i=0; i<5; i++,j+=space_obstacle)
    {
        rand_Y = rand()%700-900;
        Obstacles.push_back(new Obstacle(obstacle_up,obstacle_down, 1920+j, rand_Y, &ev));
    }
    Reset();
}

void Game::Load_Files()
{
    background = al_load_bitmap("background.jpg");
    ground = al_load_bitmap("ground.jpg");
    superman = al_load_bitmap("superman.png");
    obstacle_up = al_load_bitmap("obstacle_up.png");
    obstacle_down = al_load_bitmap("obstacle_down.png");

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
    Detect_Collision_With_Obstacle_And_Points();
    
    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        running = false;
    
    for(int i=0; i<Objects.size(); i++)
        Objects[i]-> Update_Object(ev);
    
    for(int i=0; i<Obstacles.size(); i++)
        Obstacles[i]->Update_Object(ev);
    
    if(superman_pointer->kolizja == true)
    {
        scene_menager->ChangeScene(Scene_Menager::state::Menu);
        Reset();
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

void Game::Reset()
{
    for(int i=0; i<Obstacles.size(); i++)
    {
        rand_Y = rand()%700-900;
        Obstacles[i]->x = 1920+i*space_obstacle;
    }
    superman_pointer->x = 400;
    superman_pointer->y = 60;
    superman_pointer->kolizja = false;
    superman_pointer->V = 0;
    score_pointer->last_score = score_pointer->score_int/3;
    score_pointer->score_int = 0;
    
    
}

int Game::GetScore()
{
    return score_pointer->last_score;
}
