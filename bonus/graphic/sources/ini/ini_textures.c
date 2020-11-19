/*
** EPITECH PROJECT, 2019
** ini_textures
** File description:
** ini_textures
*/

#include "graphic.h"

void ini_textures_back(graphic_t *graphic)
{
    graphic->back[0].texture = sfTexture_createFromFile\
("images/main.png", NULL);
    graphic->back[1].texture = sfTexture_createFromFile\
("images/matrix.png", NULL);
    graphic->back[2].texture = sfTexture_createFromFile\
("images/path.png", NULL);
    graphic->back[3].texture = sfTexture_createFromFile\
("images/light1.png", NULL);
    graphic->back[4].texture = sfTexture_createFromFile\
("images/light2.png", NULL);
    graphic->back[5].texture = sfTexture_createFromFile\
("images/light2.png", NULL);
    graphic->back[6].texture = sfTexture_createFromFile\
("images/win.png", NULL);
    graphic->back[7].texture = sfTexture_createFromFile\
("images/credits.png", NULL);
    graphic->back[8].texture = sfTexture_createFromFile\
("images/back_credits.png", NULL);
}

void ini_textures(graphic_t *graphic)
{
    graphic->buttons[0].texture = sfTexture_createFromFile\
("images/buttons/play.png", NULL);
    graphic->buttons[1].texture = sfTexture_createFromFile\
("images/buttons/settings.png", NULL);
    graphic->buttons[2].texture = sfTexture_createFromFile\
("images/buttons/credits.png", NULL);
    graphic->buttons[3].texture = sfTexture_createFromFile\
("images/buttons/exit.png", NULL);
    graphic->buttons[4].texture = sfTexture_createFromFile\
("images/buttons/row.png", NULL);
    graphic->buttons[5].texture = sfTexture_createFromFile\
("images/buttons/sound1.png", NULL);
    graphic->buttons[6].texture = sfTexture_createFromFile\
("images/buttons/menu.png", NULL);
    graphic->volume[0].texture = sfTexture_createFromFile\
("images/empty_volume.png", NULL);
    graphic->volume[1].texture = sfTexture_createFromFile\
("images/filled_volume.png", NULL);
    ini_textures_back(graphic);
}
