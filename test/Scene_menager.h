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
#include "scene.h"

struct Scene_Menager
{
    Scene *game = nullptr;
    Scene *menu = nullptr;
    Scene *credits = nullptr;
    enum class state
    {
        Menu,Game,Credits
    };
    bool running = true;
    ALLEGRO_DISPLAY *window = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    const int FPS = 60;
    const int window_width = 1920;
    const int window_hight = 1080;
    Scene *current_scene;
    Scene_Menager();
    void Start();
    void ChangeScene(state s);
    ~Scene_Menager();
};
#endif /* Scene_menager_h */