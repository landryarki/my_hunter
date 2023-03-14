/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-landry.gigant
** File description:
** No file there , just an epitech header example .
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include "../include/my_hunter.h"
#include <time.h>


void print_history(sfRenderWindow *window)
{
    int fd = open("save.txt", O_RDONLY);
    int score = 0;
    char *buffer = malloc(1000);
    char *pseudo = malloc(4);
    int size = 0;
    int count = 0;
    size = read(fd, buffer, 1000);
    buffer[size] = 0;
    pseudo[3] = 0;
    for (int i = 0; (i < size) && (count < 8); i++, count++) {
        for (int j = 0; buffer[i] != ';'; i++, j++)
            pseudo[j] = buffer[i];
        for (i += 1; buffer[i] != '\n'; i++)
            score = add_value(buffer[i], score);
        display_text(window, my_put_nbr_to_str(score),
                        1250 + 120, 360 + (60 * count));
        display_text(window, pseudo, 1250 + 20, 360 + (60 * count));
        score = 0;
    }
    close(fd);
}

char *my_pseudodup(char *str)
{
    char *tmp = malloc(4);
    for (int i = 0; i < 4; i++) {
        tmp[i] = str[i];
    }
    return tmp;
}

char *get_leadername(int best_score)
{
    int score = 0;
    int fd = open("save.txt", O_RDONLY);
    char *pseudo = malloc(4);
    char *best_pseudo = malloc(4);
    char *buffer = malloc(1000);
    int size = read(fd, buffer, 1000);
    if (size == 0)
        return "";
    for (int i = 0; i < size; i++) {
        for (int j = 0; buffer[i] != ';'; i++, j++)
            pseudo[j] = buffer[i];
        for (i += 1; buffer[i] != '\n'; i++)
            score = add_value(buffer[i], score);
        if (score == best_score)
            best_pseudo = my_pseudodup(pseudo);
        score = 0;
    }
    best_pseudo[3] = 0;
    close(fd);
    return best_pseudo;
}

void history(game_params *game)
{
    int best_score = get_leaderscore();
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    display_text(game->window, "HIGHSCORE", 380, 300);
    display_text(game->window, my_put_nbr_to_str(best_score),
                    380 + 120, 360);
    display_text(game->window, get_leadername(best_score), 380 + 20, 360);
    display_text(game->window, "HISTORY", 1250, 300);
    print_history(game->window);
}
