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
    ALLEGRO_BITMAP *arrow_pointer = NULL;
    bool game_over = false;
    ALLEGRO_EVENT ev;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *font_small = NULL;
    Arrow_Pointer *arrow = NULL;
    Menu()
    {
        font = al_load_ttf_font("Pixeled.ttf", 60, 0);
        font_small = al_load_ttf_font("Pixeled.ttf", 40, 0);
        arrow_pointer = al_load_bitmap("arrow_pointer.png");
        arrow =  new Arrow_Pointer(arrow_pointer,NULL,600,255,&ev);
    }
    void GetInput();
    void Update();
    void Draw();
};
#endif /* menu_h */