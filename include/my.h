/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MUL_MY_HUNTER_2018_INCLUDE_H
#define MUL_MY_HUNTER_2018_INCLUDE_H

#define MEMCHECK(x) if(!x) exit(84)
#define MAX_WIDTH (900)
#define MAX_LENGTH (600)

typedef struct spr_s {
    sfMusic *music;
    sfText *scor;
    sfClock *score;
    sfClock *clock;
    sfSprite *build;
    sfSprite *end;
    sfSprite *begin;
    sfSprite *car;
    sfSprite *perso;
    sfSprite *perso1;
    sfSprite *far;
    sfSprite *fore;
    sfSprite *build1;
    sfSprite *far1;
    sfSprite *fore1;
    sfSprite *bob;
    sfTexture *Tbuild;
    sfTexture *Tend;
    sfTexture *Tbegin;
    sfTexture *Tcar;
    sfTexture *perso2;
    sfTexture *Tfar;
    sfTexture *Tperso;
    sfTexture *Tfore;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfVector2f pos4;
    sfVector2f pos5;
    sfVector2f pos6;
    sfVector2f gravity;
    sfVector2f move1;
    sfVector2f move2;
    sfVector2f move3;
    sfVector2f move4;
    int jump;
    int nb_of_cars;
    int sco;
    int nb_tot;
} spr_t;

#endif

char *inttochar(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void setposit_left(spr_t *back);
void move_para(spr_t *back, sfSprite **tkt);
void getpos(spr_t *back);
void move_hero(spr_t *back, sfIntRect *rect);
int cloc(spr_t *back, sfIntRect *rect, sfSprite **tkt);
void free_assets(spr_t *back);
void jump(spr_t *back, sfRenderWindow *window);
int speed(spr_t *back);
int analyse_events(sfRenderWindow *window, spr_t *back);
int drawback(spr_t *back, sfRenderWindow *window, sfSprite **tkt);
sfSprite **addcar(char *map, spr_t *back);
int checkifcar(sfSprite **tkt, spr_t *back, char *map);
int car_inf(sfSprite **tkt, spr_t *back, char *map);
int score(spr_t *back);
int create_window(spr_t *back, char *map, int inf, sfRenderWindow *window);
void init(spr_t *back);
void init_game_back2(spr_t *back);
void init_game(spr_t *back);
void set_text(spr_t *back);
char *readl(char *file);
void helpb(void);
int analyse_eventsend(sfRenderWindow *window, spr_t *back);
int lose(spr_t *back, sfRenderWindow *window);
int before_create_window(spr_t *back, char *map, int inf);
int main(int argc, char **argv);
