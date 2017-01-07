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

void Menu::GetInput()
{
    al_wait_for_event(event_queue, &ev);
}

void Menu::Update()
{
    scene_menager->ChangeScene(Scene_Menager::state::Game);
}
void Menu::Draw()
{
}
