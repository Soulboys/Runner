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

void init_game(spr_t *back)
{
    back->perso2 = sfTexture_createFromFile("blob move.png", NULL);
    back->Tcar = sfTexture_createFromFile("RandomCar.png", NULL);
    back->Tbuild = sfTexture_createFromFile
    ("cyberpunk-street-files/PNG/layers/back-buildings.png", NULL);
    back->Tperso = sfTexture_createFromFile("blob minion walk.png", NULL);
    back->Tfar = sfTexture_createFromFile
    ("cyberpunk-street-files/PNG/layers/far-buildings.png", NULL);
    back->Tfore = sfTexture_createFromFile
    ("cyberpunk-street-files/PNG/layers/foreground.png", NULL);
    back->build = sfSprite_create();
    back->build = sfSprite_create();
    back->perso = sfSprite_create();
    back->car = sfSprite_create();
    back->far = sfSprite_create();
    back->fore = sfSprite_create();
    back->build1 = sfSprite_create();
    back->far1 = sfSprite_create();
    back->fore1 = sfSprite_create();
    init_game_back2(back);
}

void set_text(spr_t *back)
{
    sfFont* font;

    back->music = sfMusic_createFromFile("wii-sports-wii-sports-theme.ogg");
    back->scor = sfText_create();
    font = sfFont_createFromFile("arial.ttf");
    sfText_setFont(back->scor, font);
    sfText_setCharacterSize(back->scor, 35);
}

char *readl(char *file)
{
    int thecat = 6;
    char *buff = malloc(sizeof(char) * 2975);
    int size = 1;

    MEMCHECK(buff);
    thecat = open(file, O_RDONLY);
    if (thecat == -1) {
        write(1, "No such file or directory\n use -h\n", 26);
        return (NULL);
    }
    size = read(thecat, buff, 2975);
    buff[size] = '\0';
    close(thecat);
    return (buff);
}

void helpb(void)
{
    my_putstr("Finite runner created with CSFML.\n USAGE\n./my_runner map");
    my_putstr(".txt\nOPTIONS\n-i launch the game in infinity mode.\n-h pri");
    my_putstr("nt the usage and quit.\nUSER INTERACTIONS\nSPACE_KEY jump.\n");
}
