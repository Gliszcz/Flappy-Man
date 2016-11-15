#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "game.hpp"

int main(int argc, char **argv)
{
    Game game;
    
    game.Init();
    game.Load_Files();
    game.Allegro_Begin_Func();
    game.Start();
    game.CleanUp();
    
    return 0;
}
