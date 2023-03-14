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

sfSprite *set_sprite(char *filepath, sfIntRect *rect, int nb_sprite)
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect size = {0, 0, rect->width * nb_sprite, rect->height};

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(filepath, &size);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, *rect);
    return sprite;
}

sfVector2f *set_position(float x, float y)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f));
    pos->x = x;
    pos->y = y;
    return pos;
}
