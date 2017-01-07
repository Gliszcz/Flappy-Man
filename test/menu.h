//
//  menu.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 07.01.2017.
//  Copyright © 2017 Adam Gliszczński. All rights reserved.
//

#ifndef menu_h
#define menu_h
#include "scene.h"
struct Menu : Scene
{
    ALLEGRO_EVENT ev;
    Menu()
    {
    }
    
    void GetInput();
    void Update();
    void Draw();
};
#endif /* menu_h */
