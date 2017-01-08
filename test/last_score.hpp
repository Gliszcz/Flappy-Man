//
//  last_score.hpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 08.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef last_score_hpp
#define last_score_hpp
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
struct LastScore : Scene
{
    ALLEGRO_BITMAP *arrow_pointer = nullptr;
    ALLEGRO_EVENT ev;
    ALLEGRO_FONT *font = nullptr;
    ALLEGRO_FONT *font_small = nullptr;
    Arrow_Pointer *arrow = nullptr;
    bool back = false;
    LastScore()
    {
        font = al_load_ttf_font("Pixeled.ttf", 60, 0);
        font_small = al_load_ttf_font("Pixeled.ttf", 40, 0);
        arrow_pointer = al_load_bitmap("arrow_pointer.png");
        arrow =  new Arrow_Pointer(arrow_pointer,NULL,60,105,&ev);
    }
    void GetInput();
    void Update();
    void Draw();
};
#endif /* credits_hpp */
