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
    
    virtual void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
    }
    
    virtual void Update_Object()
    {
    }
    
    Game_Object(ALLEGRO_BITMAP* img, int a, int b)
    {
        x=a;
        y=b;
        image = img;
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
        x-=2;
        if(x<-al_get_bitmap_width(image))
            x=0;
    }
    
    Ground(ALLEGRO_BITMAP* img, int a, int b) : Game_Object(img,a,b)
    {
        x=a;
        y=b;
        image = img;
    }
};
struct Background : Game_Object
{
    
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
        al_draw_bitmap(image, x+al_get_bitmap_width(image), y, 0);
    }
    
    void Update_Object()
    {
        x-=0.6;
        if(x<-al_get_bitmap_width(image))
            x=0;
    }
    
    Background(ALLEGRO_BITMAP* img, int a, int b) : Game_Object(img,a,b)
    {
        x=a;
        y=b;
        image = img;
    }
};

#endif /* game_object_h */
