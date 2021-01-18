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

char *inttochar(int nb)
{
    char *str;
    int tmp = nb;
    int tkt;
    int i = 0;

    for (; tmp >= 10; i++)
        tmp = tmp / 10;
    tmp = nb;
    str[i + 1] = '\0';
    for (int j = 0; i != j; i--) {
        tmp = tmp / 10;
        tkt = tmp % 10;
        str[i] = tkt + '0';
    }
    return (str);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void setposit_left(spr_t *back)
{
    sfVector2f po = {900, 0};
    sfVector2f posi = {900, 110};

    if (back->pos1.x <= -900)
        sfSprite_setPosition(back->build, po);
    if (back->pos2.x <= -900)
        sfSprite_setPosition(back->build1, po);
    if (back->pos3.x <= -900)
        sfSprite_setPosition(back->far, po);
    if (back->pos4.x <= -900)
        sfSprite_setPosition(back->far1, po);
    if (back->pos5.x <= -900)
        sfSprite_setPosition(back->fore, posi);
    if (back->pos6.x <= -900)
        sfSprite_setPosition(back->fore1, posi);
}

void move_para(spr_t *back, sfSprite **tkt)
{
    sfSprite_move(back->build, back->move3);
    sfSprite_move(back->build1, back->move3);
    sfSprite_move(back->far1, back->move2);
    sfSprite_move(back->far, back->move2);
    sfSprite_move(back->fore, back->move1);
    sfSprite_move(back->fore1, back->move1);
    for (int i = 0; i < back->nb_of_cars; i++)
        sfSprite_move(tkt[i], back->move4);
}
