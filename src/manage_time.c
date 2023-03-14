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

bool get_elapsed_time_since(sfClock *clock, sfTime *reftime, float time)
{
    float sec = 0.0;
    sfTime time_real;
    time_real = sfClock_getElapsedTime(clock);
    sec = (time_real.microseconds - reftime->microseconds) / 1000000.0;
    if (sec > time) {
        *reftime = sfClock_getElapsedTime(clock);
        return true;
    }
    return false;
}

void set_time(sfClock *clock, entity_t *entity)
{
    entity->reftime_anim = malloc(sizeof(sfTime));
    entity->reftime_mov = malloc(sizeof(sfTime));
    *entity->reftime_anim = sfClock_getElapsedTime(clock);
    *entity->reftime_mov = sfClock_getElapsedTime(clock);
}
