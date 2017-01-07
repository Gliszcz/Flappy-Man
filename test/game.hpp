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
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "game_object.h"
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "scene.h"

using namespace std;
struct Game : public Scene
{
    bool running = true;
    bool running_game = false;
    int rand_Y;
    int state = 0;                 // 0 - main_menu_start 1 - main_menu_exit 2 - game 3 - game_over_new_game  4 - game_over_main_menu
    const int space_obstacle = 500;

    vector <Game_Object*> Objects;
    vector <Game_Object*> Obstacles;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *ground = NULL;
    ALLEGRO_BITMAP *superman = NULL;
    ALLEGRO_BITMAP *obstacle_up = NULL;
    ALLEGRO_BITMAP *obstacle_down = NULL;
    ALLEGRO_BITMAP *main_menu_exit = NULL;
    ALLEGRO_BITMAP *main_menu_new_game = NULL;
    ALLEGRO_BITMAP *game_over_new_game = NULL;
    ALLEGRO_BITMAP *game_over_go_to_menu = NULL;
    ALLEGRO_EVENT ev;
    Superman *superman_pointer;
    Score *score_pointer;

    Game();
    
    void Load_Files();
    void CleanUp();
    void GetInput();
    void Update();
    void Draw();
    void Detect_Collision_With_Obstacle_And_Points();
};
#endif /* game_hpp */
