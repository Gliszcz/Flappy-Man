//
//  game.hpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 15.11.2016.
//  Copyright © 2016 Adam Gliszczński. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
struct Game
{
    bool running = true;
    int FPS = 60;
    const int window_hight = 1080;
    const int window_width = 1920;
    ALLEGRO_DISPLAY *window = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *ground = NULL;
};
#endif /* game_hpp */
