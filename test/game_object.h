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
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <cstdlib>

using namespace std;
struct Superman;
struct Score;

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
    
    virtual void Collision(Superman* SuperMan, Score* ScorE)
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
        x-=3.5;
        if(x<-al_get_bitmap_width(image1))
            x=0;
    }
    
    Ground(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
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
    
    Background(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
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
    bool kolizja = false;
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
        if((y >= 1048 - al_get_bitmap_height(image1)) && (y<=1040))
            kolizja = true;
    }

    Superman(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b, ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};

struct Score : Game_Object
{
    ALLEGRO_FONT *font = NULL;
    int score_int = 0;
    int last_score;
    void Draw_Object()
    {
        al_draw_textf(font, al_map_rgb(0, 0, 0), x+100, y, 0, "SCORE : %d", score_int/3);
    }
    void Update_Object()
    {
    }
    Score(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b,  ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        font = al_load_ttf_font("Pixeled.ttf", 40, 0);
    }
};

struct Obstacle : Game_Object
{
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
        al_draw_bitmap(image2, x, y+1400, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        x -= 3.5;
        if(x<-al_get_bitmap_width(image1))
        {
            y = rand()%700-1000;
            x = 2420;
        }
    }
    
    void Collision(Superman* SuperMan,Score* ScorE)
    {
        if((SuperMan->x < x+al_get_bitmap_width(image1)&&
           SuperMan->x+al_get_bitmap_width(SuperMan->image1)-10>x&&
           SuperMan->y+10 < y+al_get_bitmap_height(image1)&&
           SuperMan->y+al_get_bitmap_height(SuperMan->image1)> y) || (SuperMan->x < x+al_get_bitmap_width(image1) &&
                                                                      SuperMan->x+al_get_bitmap_width(SuperMan->image1)-12>x&&
                                                                      SuperMan->y < y+1400+al_get_bitmap_height(image1)&&
                                                                      SuperMan->y+al_get_bitmap_height(SuperMan->image1)-20>y+1400))
            SuperMan->kolizja = true;
        
        if(SuperMan->x >= x+al_get_bitmap_width(image1)&&SuperMan->x<=x+10+al_get_bitmap_width(image1))
            ScorE->score_int += 1;
    }
    
    Obstacle(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b,  ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};
struct Arrow_Pointer :Game_Object
{
    int choice = 0;
    void Draw_Object()
    {
        al_draw_bitmap(image1, x, y, 0);
    }
    
    void Update_Object(ALLEGRO_EVENT event)
    {
        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_DOWN:
                {
                    y+=200;
                    choice++;
                    break;
                }
                case ALLEGRO_KEY_UP:
                {
                    y-=200;
                    choice--;
                    break;
                }
            }
    }
    Arrow_Pointer(ALLEGRO_BITMAP* img1,ALLEGRO_BITMAP* img2, int a, int b,  ALLEGRO_EVENT* ev) : Game_Object(img1,img2,a,b,ev)
    {
        x=a;
        y=b;
        image1 = img1;
        image2 = img2;
        event = ev;
    }
};
#endif /* game_object_h */
