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
#include <stdio.h>
#include <fcntl.h>

void write_pseudo(sfKeyEvent key, game_params *game)
{
    int i = 0;
    if (key.code >= 0 && key.code < 26) {
        for (; game->pseudo[i] != '_' && game->pseudo[i] != 0; i++);
        if (i < 3)
            game->pseudo[i] = key.code + 65;
    }
}

void save_pseudo(game_params *game)
{
    FILE *fp;
    int fd = open("save.txt", O_RDONLY);
    char buffer[1000];
    int size = read(fd, buffer, 1000);
    buffer[size] = 0;
    fp = fopen("save.txt", "w");
    fwrite(game->pseudo, 1, 3, fp);
    fwrite(";", 1, 1, fp);
    fwrite(buffer, 1, size, fp);
    fclose(fp);
    close(fd);
}
