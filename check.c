/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** __DESCRIPTION__
*/

#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <unistd.h>
#include "include/my.h"

int car_inf(sfSprite **tkt, spr_t *back, char *map)
{
    sfVector2f pos;

    for (int i = 0; i != back->nb_of_cars; i++) {
        pos = sfSprite_getPosition(tkt[i]);
        if (pos.x < -100)
            sfSprite_setPosition(tkt[i],
            (sfVector2f){(back->nb_tot * 100 + 600), 510});
    }
}

int score(spr_t *back)
{
    float time = 0;
    char *sc = inttochar(back->sco);
    sfText_setString(back->scor, sc);
    time = sfClock_getElapsedTime(back->score).microseconds;
    if (time >= 1000000) {
        back->sco += 10;
        sfClock_restart(back->score);
    }
}

int create_window(spr_t *back, char *map, int inf, sfRenderWindow *window)
{
    sfSprite **tkt;
    int car = 0;
    int win = 0;
    sfIntRect rect = {0, 0, 100, 105};

    back->sco = 0;
    tkt = addcar(map, back);
    sfMusic_play(back->music);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        cloc(back, &rect, tkt);
        drawback(back, window, tkt);
        analyse_events(window, back);
        jump(back, window);
        car = checkifcar(tkt, back, map);
        if (car == 1)
            return (0);
        score(back);
        if (inf == 1)
            car_inf(tkt, back, map);
        if (inf == 0)
            if (sfSprite_getPosition(tkt[back->nb_of_cars - 1]).x < -100)
                return (1);
    }
}

void init(spr_t *back)
{
    back->move1.x = -0.2;
    back->move2.x = -0.1;
    back->move3.x = -0.15;
    back->move4.x = -0.3;
    back->Tend = sfTexture_createFromFile("fin.png", NULL);
    back->end = sfSprite_create();
    sfSprite_setTexture(back->end, back->Tend, sfTrue);
}

void init_game_back2(spr_t *back)
{
    sfVector2f position = {900, 0};
    sfVector2f posi = {900, 110};
    sfVector2f pos = {0, 110};
    sfVector2f pos_perso = {70, 450};

    sfSprite_setPosition(back->build1, posi);
    sfSprite_setPosition(back->perso, pos_perso);
    sfSprite_setPosition(back->far1, position);
    sfSprite_setPosition(back->fore1, posi);
    sfSprite_setPosition(back->fore, pos);
    sfSprite_setTexture(back->perso, back->Tperso, sfTrue);
    sfSprite_setTexture(back->car, back->Tcar, sfTrue);
    sfSprite_setTexture(back->build, back->Tbuild, sfTrue);
    sfSprite_setTexture(back->build1, back->Tbuild, sfTrue);
    sfSprite_setTexture(back->far, back->Tfar, sfTrue);
    sfSprite_setTexture(back->far1, back->Tfar, sfTrue);
    sfSprite_setTexture(back->fore, back->Tfore, sfTrue);
    sfSprite_setTexture(back->fore1, back->Tfore, sfTrue);
}
