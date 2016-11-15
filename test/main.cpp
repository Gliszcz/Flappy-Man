#include "game.hpp"
#include "game_object.h"
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
