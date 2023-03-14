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

void gameover(game_params *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    display_text(game->window, "GAMEOVER", 960 - 120, 250);
    display_text(game->window, "Your score :", 960 - 190, 350);
    display_text(game->window, my_put_nbr_to_str(game->score), 960 + 150, 350);
    display_text(game->window, "High score :", 960 - 190, 420);
    display_text(game->window, my_put_nbr_to_str(get_highscore()),
                    960 + 150, 420);
    display_text(game->window, "Enter Your Pseudo :", 960 - 240, 490);
    display_text(game->window, game->pseudo, 100, 100);
}
