#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "game.hpp"

int main(int argc, char **argv)
{
    
    Game game;
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    
    game.background = al_load_bitmap("background.jpg");
    //ground = al_load_bitmap("ground.png");

    game.timer = al_create_timer(1.0 / game.FPS);
    game.window = al_create_display(game.window_width, game.window_hight);
    game.event_queue = al_create_event_queue();
    // EVENTS
    al_register_event_source(game.event_queue, al_get_keyboard_event_source());
    al_register_event_source(game.event_queue, al_get_timer_event_source(game.timer));
    al_register_event_source(game.event_queue, al_get_display_event_source(game.window));
    
    al_start_timer(game.timer);
    
    while (game.running)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(game.event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)                                     // WINDOW CLOSE
            game.running = false;
        
        else if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            al_draw_bitmap(game.background, 0, 0, 0);
        }
        al_flip_display();
        
    }
    
    al_destroy_display(game.window);
    return 0;
}
