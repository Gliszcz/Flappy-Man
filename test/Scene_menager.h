//
//  Scene_menager.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef Scene_menager_h
#define Scene_menager_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "scene.h"

struct Scene_Menager
{
    Scene *game = nullptr;
    Scene *menu = nullptr;
    Scene *credits = nullptr;
    Scene *current_scene;
    Scene *last_core = nullptr;
    ALLEGRO_SAMPLE *sample1 = nullptr;
    ALLEGRO_DISPLAY *window = nullptr;
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    ALLEGRO_TIMER *timer = nullptr;
    bool running = true;
    const int FPS = 60;
    const int window_width = 1920;
    const int window_hight = 1080;
    enum class state
    {
        Menu,Game,Credits,LastScore
    };
    Scene_Menager();                                    // Starting Scene Menager
    void Start();                                       // Starting Current Scene (game/menu/credits/lastscore)
    void ChangeScene(state s);                          // Changing Scene
    ~Scene_Menager();                                   // Freeing Space After Scene Menager
};
#endif /* Scene_menager_h */
