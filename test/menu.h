//
//  menu.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef menu_h
#define menu_h
#include "scene.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "game_object.h"
#include "Scene_menager.h"
#include "game.hpp"

struct Menu : Scene
{
    Arrow_Pointer *arrow = nullptr;
    ALLEGRO_FONT *font = nullptr;
    ALLEGRO_FONT *font_small = nullptr;
    ALLEGRO_FONT *font_very_small = nullptr;
    ALLEGRO_BITMAP *arrow_pointer = nullptr;
    ALLEGRO_BITMAP *superman = nullptr;
    ALLEGRO_BITMAP *obstacle_up = nullptr;
    ALLEGRO_BITMAP *obstacle_down = nullptr;
    ALLEGRO_BITMAP *background = nullptr;
    ALLEGRO_BITMAP *ground = nullptr;
    ALLEGRO_EVENT ev;
    bool game_over = false;
    bool mute;

    Menu()
    {
        font = al_load_ttf_font("Pixeled.ttf", 60, 0);
        font_small = al_load_ttf_font("Pixeled.ttf", 40, 0);
        font_very_small = al_load_font("Pixeled.ttf", 20, 0);
        arrow_pointer = al_load_bitmap("arrow_pointer.png");
        superman = al_load_bitmap("superman.png");
        obstacle_up =al_load_bitmap("obstacle_up.png");
        obstacle_down =al_load_bitmap("obstacle_down.png");
        background = al_load_bitmap("background.jpg");
        ground = al_load_bitmap("ground.jpg");
        arrow =  new Arrow_Pointer(arrow_pointer,nullptr,600,255,&ev,nullptr);
    }
    void GetInput();                                                        // Getting Input
    void Update();                                                          // Updating Menu Status
    void Draw();                                                            // Drawing Menu
};
#endif /* menu_h */
