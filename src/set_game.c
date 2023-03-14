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

void set_all_entity(entity_t **entity, sfClock *clock)
{
    for (int i = 0; i < 5; i++) {
        entity[i] = malloc(sizeof(entity_t));
        entity[i]->pos = set_position(-130, 100 + rand() % 700);
        entity[i]->rect = set_rectangle(122 * (i % 4), 0,
                                        122, 93);
        entity[i]->sprite = set_sprite("image/frame_sheet_veigar.png",
                                        entity[i]->rect, 4);
        set_time(clock, entity[i]);
        sfSprite_setPosition(entity[i]->sprite, *entity[i]->pos);
    }
}

void reset_game(game_params *game)
{
    game->debug_state = 5;
    game->score = 0;
    game->hp = 3;
    game->jhin->pos = set_position(0, 0);
    for (int i = 0; i < 5; i++) {
        game->entity[i]->pos = set_position(-130, (i * 200) + (rand() % 200));
    }
    sfSprite_setPosition(game->jhin->sprite, *game->jhin->pos);
    game->scene = 0;
}

void set_game(game_params *game)
{
    srand(time(0));
    game->debug_state = 5;
    sfVideoMode mode = {1920, 1080, 32};
    game->scene = 0;
    game->score = 0;
    game->hp = 3;
    game->entity = malloc(sizeof(entity_t*) * 5);
    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(mode, "My Hunter",
                                        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    set_all_entity(game->entity, game->clock);
    game->background = set_background();
    game->jhin = set_jhin();
    game->play_button = set_play_button();
    game->play_button2 = set_second_play_button();
    game->crosshair = set_crosshair();
}

entity_t *set_crosshair(void)
{
    entity_t *crosshair = malloc(sizeof(entity_t));
    sfTexture *texture;

    crosshair->pos = set_position(0, 0);
    crosshair->rect = set_rectangle(0, 0, 52, 50);
    crosshair->sprite = sfSprite_create();
    texture = sfTexture_createFromFile("image/crosshair.png", crosshair->rect);
    sfSprite_setTexture(crosshair->sprite, texture, sfTrue);
    sfSprite_setTextureRect(crosshair->sprite, *crosshair->rect);
    crosshair->reftime_anim = malloc(sizeof(sfTime));
    crosshair->reftime_mov = malloc(sizeof(sfTime));
    return crosshair;
}
