//
//  menu.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include <stdio.h>
#include "menu.h"
#include "Scene_menager.h"
#include "game.hpp"

void Menu::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void Menu::Update()
{
    
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        switch(ev.keyboard.keycode)
        case ALLEGRO_KEY_ENTER:
        {
            switch(arrow->choice)
            {
                case 0:
                {
                    scene_menager->ChangeScene(Scene_Menager::state::Game);
                    game_over = true;
                }
                break;
                case 1:
                {
                    scene_menager->ChangeScene(Scene_Menager::state::LastScore);
                }
                break;
                case 2:
                {
                    scene_menager->ChangeScene(Scene_Menager::state::Credits);
                }
                break;
                case 3:
                {
                    scene_menager->running = false;
                }
            }
        }
    arrow->Update_Object(ev);
}
void Menu::Draw()
{
    int score;
    if(game_over)
    {
        score = ((Game*)(scene_menager->game))->GetScore();
        al_clear_to_color(al_map_rgb(97,240,255));
        al_draw_text(font, al_map_rgb(255, 51, 51), 660, 80, 0, "GAME OVER !");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 230, 0, "NEW GAME");
        al_draw_textf(font_small, al_map_rgb(255, 51, 51), 1200, 230, 0, "YOUR SCORE : %d",score);
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 430, 0, "SCORE");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 630, 0, "CREDITS");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 830, 0, "EXIT");
        arrow->Draw_Object();

    }
    else
    {
        al_clear_to_color(al_map_rgb(97,240,255));
        al_draw_text(font, al_map_rgb(255, 51, 51), 660, 80, 0, "FLAPPY MAN");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 230, 0, "NEW GAME");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 430, 0, "SCORE");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 630, 0, "CREDITS");
        al_draw_text(font_small, al_map_rgb(255, 51, 51), 660, 830, 0, "EXIT");
        arrow->Draw_Object();

    }

    al_flip_display();
}
