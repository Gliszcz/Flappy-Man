//
//  credits.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 08.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include "credits.hpp"

void Credits::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void Credits::Update()
{
    
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        switch(ev.keyboard.keycode)
        case ALLEGRO_KEY_ENTER:
        {
            switch(arrow->choice)
            {
                case 0:
                {
                    scene_menager->ChangeScene(Scene_Menager::state::Menu);
                    back = true;
                }
            }
        }
    arrow->Update_Object(ev);
}
void Credits::Draw()
{
    if(!back)
    {
        al_clear_to_color(al_map_rgb(97,240,255));
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 100, 80, 0, "BACK <-");
        al_draw_text(font, al_map_rgb(255, 51, 51), 660, 180, 0, "SPECIAL THANKS TO : ");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 330, 0, "-Hubet Jasudowicz");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 530, 0, "-Stack Overflow");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 730, 0, "-Google");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 930, 0, "-RedBull");
        arrow->Draw_Object();
    }
    al_flip_display();
}

