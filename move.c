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

void getpos(spr_t *back)
{
    back->pos1 = sfSprite_getPosition(back->build);
    back->pos2 = sfSprite_getPosition(back->build1);
    back->pos3 = sfSprite_getPosition(back->far);
    back->pos4 = sfSprite_getPosition(back->far1);
    back->pos5 = sfSprite_getPosition(back->fore);
    back->pos6 = sfSprite_getPosition(back->fore1);
}

void move_hero(spr_t *back, sfIntRect *rect)
{
    int max_value = 800;
    int offset = 100;

    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = rect->left - max_value;
}

int cloc(spr_t *back, sfIntRect *rect, sfSprite **tkt)
{
    float time = 0;

    sfSprite_setTextureRect(back->perso, *rect);
    getpos(back);
    time = sfClock_getElapsedTime(back->clock).microseconds;
    if (time >= 2000) {
        move_para(back, tkt);
    }
    if (time >= 105000){
        move_hero(back, rect);
        sfClock_restart(back->clock);
    }
    setposit_left(back);
}

void free_assets(spr_t *back)
{
    sfTexture_destroy(back->Tbuild);
    sfTexture_destroy(back->Tfar);
    sfTexture_destroy(back->Tfore);
    sfTexture_destroy(back->Tend);
    sfSprite_destroy(back->build);
    sfSprite_destroy(back->build1);
    sfSprite_destroy(back->far);
    sfSprite_destroy(back->far1);
    sfSprite_destroy(back->fore);
    sfSprite_destroy(back->fore1);
    sfSprite_destroy(back->end);
    sfText_destroy(back->scor);
    sfMusic_destroy(back->music);
}

void jump(spr_t *back, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(back->perso);

    if (back->jump == 1) {
        sfSprite_move(back->perso, back->gravity);
        sfSprite_setTexture(back->perso, back->perso2, sfTrue);
    }
    back->gravity.y += 0.0009;
    if (pos.y > 490) {
        sfSprite_setPosition(back->perso, (sfVector2f){70, 450});
        back->gravity.y = 0;
        back->jump = 0;
        sfSprite_setTexture(back->perso, back->Tperso, sfTrue);
    }
}
