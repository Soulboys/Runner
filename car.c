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

int speed(spr_t *back)
{
    back->move1.x -=0.01;
    back->move2.x -= 0.01;
    back->move3.x -= 0.01;
    back->move4.x -= 0.01;
}

int analyse_events(sfRenderWindow *window, spr_t *back)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) && back->jump == 0) {
            back->gravity.y = -0.46;
            back->gravity.x = 0;
            back->jump = 1;
            speed(back);
        }
    }
}

int drawback(spr_t *back, sfRenderWindow *window, sfSprite **tkt)
{

    sfRenderWindow_drawSprite(window, back->far, NULL);
    sfRenderWindow_drawSprite(window, back->far1, NULL);
    sfRenderWindow_drawSprite(window, back->build, NULL);
    sfRenderWindow_drawSprite(window, back->build1, NULL);
    sfRenderWindow_drawSprite(window, back->fore, NULL);
    sfRenderWindow_drawSprite(window, back->fore1, NULL);
    sfRenderWindow_drawSprite(window, back->perso, NULL);
    for (int i = 0; i < back->nb_of_cars; i++)
        sfRenderWindow_drawSprite(window, tkt[i], NULL);
    sfRenderWindow_drawText(window, back->scor, NULL);
}

sfSprite **addcar(char *map, spr_t *back)
{
    sfSprite **tkt;

    back->nb_of_cars = 0;
    for (back->nb_tot = 0; map[back->nb_tot]; back->nb_tot++)
        if (map[back->nb_tot] == 'x')
            back->nb_of_cars++;
    tkt = malloc(sizeof(sfSprite *) * (back->nb_of_cars + 1));
    MEMCHECK(tkt);
    for (int i = 0; i < back->nb_of_cars; i++) {
        tkt[i] = sfSprite_create();
        sfSprite_setTexture(tkt[i], back->Tcar, sfTrue);
    }
    for (int i = 0, z = 0, j = 600; map[i]; i++, j += 100)
        if (map[i] == 'x') {
            sfSprite_setPosition(tkt[z], (sfVector2f){j, 510});
            z++;
        }
    return (tkt);
}

int checkifcar(sfSprite **tkt, spr_t *back, char *map)
{
    int i = 0;
    sfVector2f pos;
    sfVector2f po_per = sfSprite_getPosition(back->perso);

    for (int f = 0; f != back->nb_of_cars; f++) {
        pos = sfSprite_getPosition(tkt[f]);
        if (pos.x < po_per.x + 70 &&
        pos.y < po_per.y + 100 && pos.x > po_per.x) {
            return (1);
        }
    }
    return (0);
}
