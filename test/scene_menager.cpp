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
#include "credits.hpp"
#include "about_instructions.hpp"
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

Scene_Menager::Scene_Menager()
{
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_acodec_addon();
    al_install_audio();
    sample = al_load_sample("FlipFlap.wav");
    al_reserve_samples(1);
    timer = al_create_timer(1.0 / FPS);
    window = al_create_display(window_width, window_hight);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(window));
    al_start_timer(timer);
    
    game = new Game();
    menu  = new Menu();
    credits = new Credits();
    about = new About();

    current_scene = menu;
    
    game->SetTimer(timer);
    game->SetWindow(window);
    game->SetEventQueue(event_queue);
    game->SetSceneMenager(this);
    
    menu->SetTimer(timer);
    menu->SetWindow(window);
    menu->SetEventQueue(event_queue);
    menu->SetSceneMenager(this);
    
    credits->SetTimer(timer);
    credits->SetWindow(window);
    credits->SetEventQueue(event_queue);
    credits->SetSceneMenager(this);
    
    about->SetTimer(timer);
    about->SetWindow(window);
    about->SetEventQueue(event_queue);
    about->SetSceneMenager(this);
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

void Scene_Menager::MusicMenager(music m)
{
    if(m == music::Play)
        al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, nullptr);
    else if(m == music::Mute)
        al_stop_samples();
}

void Scene_Menager::ChangeScene(state s)
{
    if(s == state::Menu)
        current_scene = menu;
    else if(s == state::Game)
        current_scene = game;
    else if(s == state::Credits)
        current_scene = credits;
    else if (s == state::About)
        current_scene = about;
}

Scene_Menager::~Scene_Menager()
{
    al_destroy_sample(sample);
    al_destroy_display(window);
    delete game;
    delete menu;
    delete credits;
    delete about;
}
