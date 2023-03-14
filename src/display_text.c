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

void display_text(sfRenderWindow *window, char *str, int x, int y)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("image/04B_19__.TTF");
    sfVector2f vec = {x, y};
    text = sfText_create();
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, vec);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}
