//
//  last_score.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 08.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "last_score.hpp"

void LastScore::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void LastScore::Update()
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        switch(ev.keyboard.keycode)
        case ALLEGRO_KEY_ENTER:
        {
            scene_menager->ChangeScene(Scene_Menager::state::Menu);
            back = true;
        }
}

void LastScore::Draw()
{
    if(!back)
    {
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_bitmap(ground, 0, 1030, 0);
        al_draw_bitmap(obstacle_up,1600,-800,0);
        al_draw_bitmap(obstacle_down,1600,600,0);
        al_draw_bitmap(superman, 80, 400, 0);
        al_draw_bitmap(table, 0, 0, 0);
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 100, 80, 0, "BACK");
        al_draw_bitmap(arrow_pointer, 50, 105, 0);
        al_draw_text(font, al_map_rgb(255, 51, 51), 460, 180, 0, "YOUR LAST 5 SCORES : ");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 760, 530, 0, " COMMING SOON !");
    }
    al_flip_display();
    back = false;
}

