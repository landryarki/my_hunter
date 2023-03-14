/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-landry.gigant
** File description:
** No file there , just an epitech header example .
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/my_hunter.h"
#include <time.h>

void loop(game_params *game)
{
    srand(time(0));
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->scene == 0)
        scene_menu(game);
    if (game->scene == 1)
        play_game(game);
    if (game->scene == 2)
        gameover(game);
    if (game->scene == 3)
        history(game);
    analyse_events(game);
    srand(sfClock_getElapsedTime(game->clock).microseconds);
    sfRenderWindow_display(game->window);
}

void write_h(void)
{
    write(1, "USAGE\n    ./my_hunter\nDESCRIPTION\n"
            "    Game 'Duck Hunt' like where you have to "
            "aim at the ennemies moving on the screen,"
            " thanks to your cursor.\n"
            "    The goal is to make the highest score possible.\n"
            "HOW TO PLAY\n    Left click on play and then"
            " left click to shoot on the ennemies.\n"
            "    Gameover happen when you loose all of your healpoint,"
            " by letting an ennemy cross the screen.\n", 374);
}

int main(int argc, char **argv)
{
    game_params *game = malloc(sizeof(game_params));

    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'h' &&
    argv[1][2] == 0) {
        write_h();
        return 0;
    } else if (argc != 1) {
        return 84;
    }
    set_game(game);
    for (;sfRenderWindow_isOpen(game->window) &&
    sfRenderWindow_hasFocus(game->window);)
        loop(game);
    destroy_game(game);
    return 0;
}
