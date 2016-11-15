//
//  game_object.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 15.11.2016.
//  Copyright © 2016 Adam Gliszczński. All rights reserved.
//

#ifndef game_object_h
#define game_object_h
struct Game_Object
{
    ALLEGRO_BITMAP *image;
    float x;
    float y;
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
    }
};
#endif /* game_object_h */
