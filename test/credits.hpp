//
//  credits.hpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 08.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef credits_hpp
#define credits_hpp
#include <stdio.h>
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

struct Credits : Scene
{
    Arrow_Pointer *arrow = nullptr;
    ALLEGRO_FONT *font = nullptr;
    ALLEGRO_FONT *font_small = nullptr;
    ALLEGRO_BITMAP *arrow_pointer = nullptr;
    ALLEGRO_BITMAP *superman = nullptr;
    ALLEGRO_BITMAP *obstacle_up = nullptr;
    ALLEGRO_BITMAP *obstacle_down = nullptr;
    ALLEGRO_BITMAP *background = nullptr;
    ALLEGRO_BITMAP *ground = nullptr;
    ALLEGRO_EVENT ev;
    bool back = false;
    
    Credits()
    {
        font = al_load_ttf_font("Pixeled.ttf", 60, 0);
        font_small = al_load_ttf_font("Pixeled.ttf", 35, 0);
        arrow_pointer = al_load_bitmap("arrow_pointer.png");
        superman = al_load_bitmap("superman.png");
        obstacle_up = al_load_bitmap("obstacle_up.png");
        obstacle_down = al_load_bitmap("obstacle_down.png");
        background = al_load_bitmap("background.jpg");
        ground = al_load_bitmap("ground.jpg");
        arrow =  new Arrow_Pointer(arrow_pointer,nullptr,60,105,&ev,nullptr);
    }
    void GetInput();                                                    // Getting Input
    void Update();                                                      // Updating Credits Status (if back to main menu)
    void Draw();                                                        // Drawing Credits
};
#endif /* credits_hpp */
