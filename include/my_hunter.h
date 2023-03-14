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


#ifndef B_MUL_100_NAN_1_1_MYHUNTER_LANDRY_GIGANT_MY_HUNTER_H
    #define B_MUL_100_NAN_1_1_MYHUNTER_LANDRY_GIGANT_MY_HUNTER_H

typedef struct entity_t {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f *pos;
    sfTime *reftime_mov;
    sfTime *reftime_anim;
} entity_t;

typedef struct game_params_t {
    sfRenderWindow *window;
    sfSprite *background;
    entity_t *jhin;
    sfSprite *play_button;
    sfSprite *play_button2;
    bool on_play_button;
    entity_t *crosshair;
    entity_t **entity;
    sfClock *clock;
    int score;
    int hp;
    int scene;
    int debug_state;
    char *pseudo;
} game_params;

char *my_put_nbr_to_str(int nb);
void manage_mouse_click(sfMouseButtonEvent event, game_params *game);
void manage_killing_entity(sfMouseButtonEvent event, game_params *game);
void mouse_mouvement(sfMouseMoveEvent event, game_params *game);
void analyse_events(game_params *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfSprite *set_background(void);
sfSprite *set_play_button(void);
sfSprite *set_second_play_button(void);
sfSprite *set_sprite(char *filepath, sfIntRect *rect, int nb_sprite);
void set_time(sfClock *clock, entity_t *entity);
sfIntRect *set_rectangle(int left, int top, int width, int height);
sfVector2f *set_position(float x, float y);
entity_t *set_crosshair(void);
entity_t *set_jhin(void);
void set_game(game_params *game);
void scene_menu(game_params *game);
bool get_elapsed_time_since(sfClock *clock, sfTime *reftime, float time);
void play_game(game_params *game);
void set_all_entity(entity_t **entity, sfClock *clock);
void check_pos(entity_t *entity, int *hp, int debug);
void reset_game(game_params *game);
void destroy_game(game_params *game);
void destroy_entity(entity_t *entity);
void destroy_all_entity(entity_t **entity);
void display_text(sfRenderWindow *window, char *str, int x, int y);
void gameover(game_params *game);
void debug_mode_action(sfKeyEvent key, game_params *game);
int debug_mode_state(sfKeyEvent key, game_params *game);
void save_score(int score);
int get_highscore(void);
void history(game_params *game);
int add_value(char c, int result);
void write_pseudo(sfKeyEvent key, game_params *game);
void save_pseudo(game_params *game);
int get_leaderscore(void);

#endif //B_MUL_100_NAN_1_1_MYHUNTER_LANDRY_GIGANT_MY_HUNTER_H
