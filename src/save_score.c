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

int my_str_len(char *str)
{
    int i = 0;
    for (; str[i] != 0; i++) {}
    return i;
}

void save_score(int score)
{
    char *str = my_put_nbr_to_str(score);
    int len = my_str_len(str);
    FILE *fp;
    int fd = open("save.txt", O_RDONLY);
    char buffer[1000];
    int size = read(fd, buffer, 1000);
    buffer[size] = 0;
    fp = fopen("save.txt", "w");
    fwrite(str, 1, len, fp);
    fwrite("\n", 1, 1, fp);
    fwrite(buffer, 1, size, fp);
    fclose(fp);
    close(fd);
}

int add_value(char c, int result)
{
    int value = c - 48;
    result = result * 10 + value;
    return result;
}

int get_highscore(void)
{
    int fd = open("save.txt", O_RDONLY);
    int score = 0;
    int best_score = 0;
    char *buffer;
    int size = 0;
    buffer = malloc(1000);
    size = read(fd, buffer, 1000);
    for (int i = 0; i < size; i++) {
        for (; buffer[i] != '\n'; i++)
            score = add_value(buffer[i], score);
        if (best_score < score)
            best_score = score;
        score = 0;
        for (; buffer[i] != ';'; i++);
    }
    close(fd);
    return best_score;
}

int get_leaderscore(void)
{
    int fd = open("save.txt", O_RDONLY);
    int score = 0;
    int best_score = 0;
    char *buffer;
    int size = 0;
    buffer = malloc(1000);
    size = read(fd, buffer, 1000);
    for (int i = 0; i < size; i++) {
        for (; buffer[i] != ';'; i++);
        i++;
        for (; buffer[i] != '\n'; i++)
            score = add_value(buffer[i], score);
        if (best_score < score)
            best_score = score;
        score = 0;
    }
    close(fd);
    return best_score;
}
