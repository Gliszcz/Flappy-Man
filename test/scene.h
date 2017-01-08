//
//  scene.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef scene_h
#define scene_h
#include <allegro5/allegro.h>

struct Scene_Menager;

struct Scene
{
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *window = NULL;
    virtual void GetInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    Scene_Menager *scene_menager = NULL;
    void SetEventQueue(ALLEGRO_EVENT_QUEUE *event_queue);
    void SetTimer(ALLEGRO_TIMER *timer);
    void SetWindow(ALLEGRO_DISPLAY *window);
    void SetSceneMenager(Scene_Menager *scene_menager);
};
#endif /* scene_h */
