//
//  about_instructions.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 22.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "about_instructions.hpp"

void About::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void About::Update()
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        switch(ev.keyboard.keycode)
        case ALLEGRO_KEY_ENTER:
    {
        scene_menager->ChangeScene(Scene_Menager::state::Menu);
        back = true;
    }
}

void About::Draw()
{
    if(!back)
    {
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_bitmap(obstacle_up,1700,-800,0);
        al_draw_bitmap(obstacle_down,1700,600,0);
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 100, 80, 0, "BACK");
        al_draw_bitmap(arrow_pointer, 50, 105, 0);
        al_draw_text(font, al_map_rgb(255, 51, 51), 660, 180, 0, "HOW TO PLAY : ");
    }
    al_flip_display();
    back = false;
}
