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
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "game_object.h"
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "scene.h"

struct Game : public Scene
{
    Superman *superman_pointer;
    Score *score_pointer;
    ALLEGRO_BITMAP *background = nullptr;
    ALLEGRO_BITMAP *ground = nullptr;
    ALLEGRO_BITMAP *superman = nullptr;
    ALLEGRO_BITMAP *obstacle_up = nullptr;
    ALLEGRO_BITMAP *obstacle_down = nullptr;
    ALLEGRO_EVENT ev;
    std::vector <Game_Object*> Objects;
    std::vector <Game_Object*> Obstacles;
    bool running = true;
    int rand_Y;
    const int space_obstacle = 500;
    
    Game();
    void Load_Files();                                      // Loading Bitmaps
    void CleanUp();                                         // Freeing memory
    void GetInput();                                        // Getting Input From Keyboard
    void Update();                                          // Updating Objects Atributes
    void Draw();                                            // Drawing Objects
    void Detect_Collision_With_Obstacle_And_Points();       // Detecting Collisions & Counting Points
    void Reset();                                           // Game Reset (score, posiotion, status)
    int GetScore();
};
#endif /* game_hpp */
