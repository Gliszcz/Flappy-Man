//
//  scene.cpp
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#include <stdio.h>
#include "scene.h"

void Scene::SetEventQueue(ALLEGRO_EVENT_QUEUE *event_queue)
{
    this->event_queue = event_queue;
}
void Scene::SetTimer(ALLEGRO_TIMER *timer)
{
    this->timer = timer;
}
void Scene::SetWindow(ALLEGRO_DISPLAY *window)
{
    this->window = window;
}
void Scene::SetSceneMenager(Scene_Menager *scene_menager)
{
    this->scene_menager = scene_menager;
}
