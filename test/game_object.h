//
//  game_object.h
//  Flappy Man
//
//  Created by Adam Gliszczński on 15.11.2016.
//  Copyright © 2016 Adam Gliszczński. All rights reserved.
//

#ifndef game_object_h
#define game_object_h
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

using namespace std;
struct Game_Object
{
    ALLEGRO_BITMAP *image1;
    ALLEGRO_BITMAP *image2;
    float x;
    float y;
    ALLEGRO_EVENT *event;
    virtual void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
    }
    
    virtual void Update_Object(ALLEGRO_EVENT event)
    {
    }
    
    Game_Object(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};

struct Ground : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
        al_draw_bitmap(image1, x+al_get_bitmap_width(image1), y, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        x-=2.5;
        if(x<-al_get_bitmap_width(image1))
            x=0;
    }
    
    Ground(ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};

struct Background : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
        al_draw_bitmap(image1, x+al_get_bitmap_width(image1), y, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        x-=0.6;
        if(x<-al_get_bitmap_width(image1))
            x=0;
    }
    
    Background(ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};

struct Superman : Game_Object
{
    int V=0;
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        y+=V;
        V+=1;
        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_SPACE:
                    V=-16;
            }
    }
    
    Superman(ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};

struct Obstacle : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
        al_draw_bitmap(image2, x, y+1500, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        x-=2.5;
        if(x<-al_get_bitmap_width(image1))
            x=2420;
        if(x<-al_get_bitmap_width(image2))
            x=2420;
    }
    Obstacle(ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};



#endif /* game_object_h */
