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

int analyse_eventsend(sfRenderWindow *window, spr_t *back)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
            return (0);
        }
        if (sfKeyboard_isKeyPressed(sfKeyR))
            return (1);
    }
}

int lose(spr_t *back, sfRenderWindow *window)
{
    int i = 2;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back->end, NULL);
        sfRenderWindow_drawText(window, back->scor, NULL);
        sfText_setPosition(back->scor, (sfVector2f){540, 300});
        i = analyse_eventsend(window, back);
        if (i == 1)
            return (2);
        else if (i == 0) {
            return (3);
        }
    }
}

int before_create_window(spr_t *back, char *map, int inf)
{
    int w = -1;
    sfRenderWindow *window;
    sfVideoMode video_mode = {MAX_WIDTH, MAX_LENGTH, 32};

    window = sfRenderWindow_create(video_mode, "RRRRRUUUUUUUNNNNNNNNNNNN",
    sfDefaultStyle | sfClose, NULL);
    w = create_window(back, map, inf, window);
    while (sfRenderWindow_isOpen(window) || w == 1 || w == 2) {
        w = lose(back, window);
        if (w == 2)
            w = create_window(back, map, inf, window);
    }
    free_assets(back);
    sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    spr_t *back = malloc(sizeof(*back));
    char *map;
    int inf = 0;

    for (int i = 0; argv[i]; i++)
        if (argv[i][0] == '-')
            if (argv[i][1] == 'h') {
                helpb();
                return (1);
            }
            else if (argv[i][1] == 'i')
                inf = 1;
    map = readl(argv[1]);
    if (map == NULL)
        return (84);
    back->score = sfClock_create();
    back->clock = sfClock_create();
    init_game(back);
    init(back);
    set_text(back);
    before_create_window(back, map, inf);
}
