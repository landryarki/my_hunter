/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-landry.gigant
** File description:
** No file there , just an epitech header example .
*/

#include <stdlib.h>

char *my_put_nbr_to_str(int nb)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 5);
    char *tmp = malloc(sizeof(char) * 5);
    for (; (nb) != 0; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    if (i == 0) {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    i--;
    for (;str[j] != 0; j++, i--) {
        tmp[j] = str[i];
    }
    tmp[j] = '\0';
    return tmp;
}
