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
    void Update_Object()
    {
    }
};

struct Ground : Game_Object
{
    
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
        al_draw_bitmap(image, x+al_get_bitmap_width(image), y, 0);
    }
    void Update_Object()
    {
        x-=0.5;
    }
};
#endif /* game_object_h */
