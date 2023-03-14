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

void key_pressed(sfKeyEvent key, game_params *game)
{
    if (game->scene == 1) {
        if (game->debug_state == 0)
            debug_mode_action(key, game);
        debug_mode_state(key, game);
    }
    if (game->scene == 2) {
        write_pseudo(key, game);
        if (key.code == sfKeyEnter && game->pseudo[2] != '_') {
            save_pseudo(game);
            reset_game(game);
        }
    }
}

void analyse_events(game_params *game)
{
    sfEvent event;
    for (;sfRenderWindow_pollEvent(game->window, &event);) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton, game);
        if (event.type == sfEvtMouseMoved)
            mouse_mouvement(event.mouseMove, game);
        if (event.type == sfEvtKeyPressed)
            key_pressed(event.key, game);
    }
}

void manage_killing_entity(sfMouseButtonEvent event, game_params *game)
{
    for (int i = 0; i < 5 && game->scene == 1; i++) {
        if (event.x > game->entity[i]->pos->x &&
            event.y > game->entity[i]->pos->y &&
            event.x < game->entity[i]->pos->x + game->entity[i]->rect->width &&
            event.y < game->entity[i]->pos->y + game->entity[i]->rect->height) {
            game->score += 1;
            game->entity[i]->pos = set_position(-130, 100 + rand() % 800);
            sfSprite_setPosition(game->entity[i]->sprite,
                                    *game->entity[i]->pos);
            sfRenderWindow_drawSprite(game->window,
                                        game->entity[i]->sprite,
                                        NULL);
        }
    }
}

void manage_mouse_click(sfMouseButtonEvent event, game_params *game)
{
    if (event.x > 870 && event.x < 1060 && event.y > 650 &&
    event.y < 700 && game->scene == 0) {
        game->scene = 3;
        return;
    }
    if (event.x > (1920 - 257) / 2 && event.x < (1920 + 257) / 2 &&
    event.y > (1080 - 71) / 2 && event.y < (1080 + 71) / 2 && game->scene == 0)
        game->scene = 1;
    manage_killing_entity(event, game);
    if (game->scene == 2 && game->pseudo[2] != '_') {
        save_pseudo(game);
        reset_game(game);
    }
    if (game->scene == 3)
        reset_game(game);
}

void mouse_mouvement(sfMouseMoveEvent event, game_params *game)
{
    if (game->scene == 1) {
        game->crosshair->pos = set_position(event.x - 26, event.y - 25);
    }
    if (event.x > (1920 - 257) / 2 && event.x < (1920 + 257) / 2 &&
    event.y > (1080 - 71) / 2 && event.y < (1080 + 71) / 2 && game->scene == 0)
        game->on_play_button = true;
    else
        game->on_play_button = false;
}
