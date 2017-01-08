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
        al_clear_to_color(al_map_rgb(97,240,255));
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 100, 80, 0, "BACK");
        al_draw_bitmap(arrow_pointer, 50, 105, 0);
        al_draw_text(font, al_map_rgb(255, 51, 51), 460, 180, 0, "YOUR LAST 15 SCORES : ");
    }
    al_flip_display();
    back = false;
}

