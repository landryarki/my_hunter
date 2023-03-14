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

void destroy_all_entity(entity_t **entity)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(entity[i]->sprite);
        free(entity[i]->rect);
        free(entity[i]->pos);
        free(entity[i]->reftime_mov);
        free(entity[i]->reftime_anim);
        free(entity[i]);
    }
    free(entity);
}

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    free(entity->rect);
    free(entity->pos);
    free(entity->reftime_mov);
    free(entity->reftime_anim);
    free(entity);
}

void destroy_game(game_params *game)
{
    sfTexture *texture = sfTexture_create(1, 1);
    sfTexture_destroy(texture);
    free(game->pseudo);
    sfRenderWindow_destroy(game->window);
    sfSprite_destroy(game->background);
    sfSprite_destroy(game->play_button);
    sfSprite_destroy(game->play_button2);
    sfClock_destroy(game->clock);
    destroy_all_entity(game->entity);
    destroy_entity(game->jhin);
    destroy_entity(game->crosshair);
    free(game);
}
