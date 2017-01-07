//
//  scene_menager.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "Scene_menager.h"
#include "game.hpp"
#include "menu.h"
Scene_Menager::Scene_Menager()
{
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    
    timer = al_create_timer(1.0 / FPS);
    window = al_create_display(window_width, window_hight);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(window));
    al_start_timer(timer);
    
    game = new Game();
    menu  = new Menu();
    
    current_scene = menu;
    next_scene = menu;
    
    game->SetTimer(timer);
    game->SetWindow(window);
    game->SetEventQueue(event_queue);
    game->SetSceneMenager(this);
    
    menu->SetTimer(timer);
    menu->SetWindow(window);
    menu->SetEventQueue(event_queue);
    menu->SetSceneMenager(this);
    
}
void Scene_Menager::Start()
{
    while (running)
    {
        
        current_scene->GetInput();
        current_scene->Update();
        current_scene->Draw();
    }
    
}
void Scene_Menager::ChangeScene(state s)
{
    if(s == state::Menu)
        current_scene = menu;
    else if(s == state::Game)
        current_scene = game;
}

Scene_Menager::~Scene_Menager()
{
    al_destroy_display(window);
    delete game;
    delete menu;
}
