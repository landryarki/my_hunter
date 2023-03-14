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

sfSprite *set_background(void)
{
    sfSprite *background;
    sfTexture *back;
    sfIntRect rect_back = {0, 0, 1920, 1080};

    background = sfSprite_create();
    back = sfTexture_createFromFile("image/background.png",
                                    &rect_back);
    sfSprite_setTexture(background, back, sfTrue);
    return background;
}

sfSprite *set_play_button(void)
{
    sfSprite *play_button;
    sfTexture *play;
    sfIntRect rect_play = {0, 0, 257, 71};
    sfVector2f vec = {(1920 - 257) / 2, (1080 - 71) / 2};

    play_button = sfSprite_create();
    play = sfTexture_createFromFile("image/play_button.png",
                                    &rect_play);
    sfSprite_setTexture(play_button, play, sfTrue);
    sfSprite_setPosition(play_button, vec);
    return play_button;
}

sfSprite *set_second_play_button(void)
{
    sfSprite *play_button;
    sfTexture *play;
    sfIntRect rect_play = {0, 0, 300, 82};
    sfVector2f vec = {(1920 - 300) / 2, (1080 - 82) / 2};

    play_button = sfSprite_create();
    play = sfTexture_createFromFile("image/play_button2_x300.png",
                                    &rect_play);
    sfSprite_setTexture(play_button, play, sfTrue);
    sfSprite_setPosition(play_button, vec);
    return play_button;
}

entity_t *set_jhin(void)
{
    sfClock *clock = sfClock_create();
    entity_t *jhin = malloc(sizeof(entity_t));
    sfTexture *texture;

    jhin->pos = set_position(0, 0);
    jhin->rect = set_rectangle(300, 0, 2048, 2048);
    jhin->sprite = sfSprite_create();
    texture = sfTexture_createFromFile("image/jhin_x2048.png", jhin->rect);
    sfSprite_setTexture(jhin->sprite, texture, sfTrue);
    sfSprite_setTextureRect(jhin->sprite, *jhin->rect);
    sfSprite_setPosition(jhin->sprite, *jhin->pos);
    set_time(clock, jhin);
    sfClock_destroy(clock);
    return jhin;
}
