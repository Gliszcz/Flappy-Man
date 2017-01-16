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
    Scene_Menager *scene_menager = nullptr;
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    ALLEGRO_TIMER *timer = nullptr;
    ALLEGRO_DISPLAY *window = nullptr;
    
    
    virtual void GetInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    void SetEventQueue(ALLEGRO_EVENT_QUEUE *event_queue);           // Setting Event Queue
    void SetTimer(ALLEGRO_TIMER *timer);                            // Setting Timer
    void SetWindow(ALLEGRO_DISPLAY *window);                        // Setting Window
    void SetSceneMenager(Scene_Menager *scene_menager);             // Setting SceneMenager => to menage wchich scene should be shown
};
#endif /* scene_h */
