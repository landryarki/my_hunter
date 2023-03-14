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

int debug_mode_state_bis(sfKeyEvent key, game_params *game)
{
    if (game->debug_state == 1 && key.code == sfKeyNumpad5)
        return (game->debug_state = 0);
    else if (game->debug_state != 0)
        return (game->debug_state = 5);
    if (game->debug_state == 0 && key.code == sfKeyF11)
        return (game->debug_state = 5);
    return 0;
}

int debug_mode_state(sfKeyEvent key, game_params *game)
{
    if (game->debug_state == 5 && key.code == sfKeyF12)
        return (game->debug_state = 4);
    else if (game->debug_state > 4)
        return (game->debug_state = 5);
    if (game->debug_state == 4 && key.code == sfKeyNumpad3)
        return (game->debug_state = 3);
    else if (game->debug_state > 3)
        return (game->debug_state = 5);
    if (game->debug_state == 3 && key.code == sfKeyNumpad1)
        return (game->debug_state = 2);
    else if (game->debug_state > 2)
        return (game->debug_state = 5);
    if (game->debug_state == 2 && key.code == sfKeyNumpad0)
        return (game->debug_state = 1);
    else if (game->debug_state > 1)
        return (game->debug_state = 5);
    debug_mode_state_bis(key, game);
    return 0;
}

void debug_mode_action(sfKeyEvent key, game_params *game)
{
    if (key.code == sfKeyAdd)
        game->hp++;
    if (key.code == sfKeySubtract)
        game->hp--;
    if (key.code == sfKeyMultiply)
        game->score++;
    if (key.code == sfKeyDivide && game->score > 0)
        game->score--;
}
