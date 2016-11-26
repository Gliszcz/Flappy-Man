//
//  game_object.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 15.11.2016.
//  Copyright © 2016 Adam Gliszczński. All rights reserved.
//

#ifndef game_object_h
#define game_object_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

struct Game_Object
{
    ALLEGRO_BITMAP *image;
    float x;
    float y;
    ALLEGRO_EVENT *event;
    virtual void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
    }
    
    virtual void Update_Object()
    {
    }
    
    Game_Object(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
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
        x-=2.5;
        if(x<-al_get_bitmap_width(image))
            x=0;
    }
    
    Ground(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img,a,b,ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
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
    
    Background(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img,a,b,ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
    }
};

struct Superman : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
    }
    
    void Update_Object()
    {
        if(event->type == ALLEGRO_KEY_DOWN)
            switch(event->keyboard.keycode)
            case ALLEGRO_KEY_SPACE:
                y++;
    }
    
    Superman(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img,a,b,ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
    }
};

struct Obstacle_Up : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
        al_draw_bitmap(image, x+350, y, 0);
        al_draw_bitmap(image, x+700, y, 0);
        al_draw_bitmap(image, x+1050, y, 0);
    }
    
    void Update_Object()
    {
        x-=2.5;

    }
    Obstacle_Up(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img,a,b,ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
    }
};

struct Obstacle_Down : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image, x, y, 0);
        al_draw_bitmap(image, x+350, y, 0);
        al_draw_bitmap(image, x+700, y, 0);
        al_draw_bitmap(image, x+1050, y, 0);
    }
 
    void Update_Object()
    {
        x-=2.5;
    }
    Obstacle_Down(ALLEGRO_BITMAP* img, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img,a,b,ev)
    {
        x=a;
        y=b;
        image = img;
        event = ev;
    }
 };

#endif /* game_object_h */
