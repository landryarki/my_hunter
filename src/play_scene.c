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

void scene_menu(game_params *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    if (game->on_play_button) {
        sfRenderWindow_drawSprite(game->window, game->play_button2, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, game->play_button, NULL);
    }
    display_text(game->window, "HISTORY", 870, 650);
    sfRenderWindow_drawSprite(game->window, game->jhin->sprite, NULL);
}

void check_pos(entity_t *entity, int *hp, int debug)
{
    if (entity->pos->x > 1920) {
        if (debug != 0)
            *hp -= 1;
        entity->pos = set_position(-130, 100 + rand() % 800);
    }
}

void update_sprite(game_params *game)
{
    for (int i = 0; i < 5; i++) {
        if (get_elapsed_time_since(game->clock,
        game->entity[i]->reftime_mov,0.05)) {
            game->entity[i]->pos =
                    set_position(game->entity[i]->pos->x + 1 + i + game->score,
                                    game->entity[i]->pos->y);
            sfSprite_setPosition(game->entity[i]->sprite,
                                    *game->entity[i]->pos);
        }
        if (get_elapsed_time_since(game->clock,
        game->entity[i]->reftime_anim,0.1)) {
            move_rect(game->entity[i]->rect, 122, 488);
        }
        sfSprite_setTextureRect(game->entity[i]->sprite,
                                *game->entity[i]->rect);
        sfRenderWindow_drawSprite(game->window,
                                    game->entity[i]->sprite, NULL);
        check_pos(game->entity[i], &game->hp, game->debug_state);
    }
}

void loose_game(game_params *game)
{
    game->pseudo = malloc(sizeof(char) * 4);
    for (int i = 0; i < 3; i++)
        game->pseudo[i] = '_';
    game->pseudo[3] = 0;
    game->scene = 2;
    save_score(game->score);
}

void play_game(game_params *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    sfSprite_setPosition(game->crosshair->sprite, *game->crosshair->pos);
    update_sprite(game);
    if (get_elapsed_time_since(game->clock,game->jhin->reftime_mov, 0.01)) {
        game->jhin->pos = set_position(game->jhin->pos->x - 5,
                                        game->jhin->pos->y);
        sfSprite_setPosition(game->jhin->sprite, *game->jhin->pos);
    }
    display_text(game->window, "Score :", 0, 0);
    display_text(game->window, my_put_nbr_to_str(game->score), 200, 0);
    display_text(game->window, "Heal Point :", 1550, 0);
    display_text(game->window, my_put_nbr_to_str(game->hp), 1850, 0);
    sfRenderWindow_drawSprite(game->window, game->jhin->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->crosshair->sprite, NULL);
    if (game->hp <= 0) {
        loose_game(game);
    }
}
