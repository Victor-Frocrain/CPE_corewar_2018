/*
** EPITECH PROJECT, 2019
** ini_text
** File description:
** ini_text
*/

#include "graphic.h"

void update_text(sfText *text, char *str, int nb)
{
    char *number = my_getstr(nb);
    char *cat = my_strcat(str, number);

    sfText_setString(text, cat);
    free(number);
    free(cat);
}

bool ini_settings_strings(graphic_t *graphic)
{
    sfVector2f pos = {(100.0 / 1920) * graphic->video.width, (50.0 / 1080) * \
graphic->video.height};
    int size = (40.0 / 1920.0) * graphic->video.width;
    char *tim = my_strcat("Time between each cycle (in milliseconds) : ", \
my_getstr(graphic->limit_round));

    if (!tim)
        return (false);
    sfText_setString(graphic->indic.text[6], tim);
    sfText_setString(graphic->indic.text[7], "Volume :");
    for (int i = 6; i < 8; i++) {
        sfText_setCharacterSize(graphic->indic.text[i], size);
        sfText_setPosition(graphic->indic.text[i], pos);
        pos.y += (300.0 / 1080) * graphic->video.height;
    }
    free(tim);
    return (ini_images(graphic));
}

bool ini_strings(graphic_t *graphic)
{
    char *die = my_strcat("Cycle to die : ", my_getstr(CYCLE_TO_DIE));
    char *champ1 = my_strcat("Champion 1 : ", "Killian");
    char *champ2 = my_strcat("Champion 2 : ", "Nathan");
    char *champ3 = my_strcat("Champion 3 : ", "Stephane");
    char *champ4 = my_strcat("Champion 4 : ", "Victor");

    if (!die || !champ1 || !champ2 || !champ3 || !champ4)
        return (false);
    sfText_setString(graphic->indic.text[1], die);
    sfText_setString(graphic->indic.text[2], champ1);
    sfText_setString(graphic->indic.text[3], champ2);
    sfText_setString(graphic->indic.text[4], champ3);
    sfText_setString(graphic->indic.text[5], champ4);
    free(die);
    free(champ1);
    free(champ2);
    free(champ3);
    free(champ4);
    return (ini_settings_strings(graphic));
}

bool ini_text(graphic_t *graphic)
{
    sfVector2f pos = {(1450.0 / 1920) * graphic->video.width, \
(100.0 / 1080) * graphic->video.height};
    int size = (28.0 / 1920.0) * graphic->video.width;

    for (int i = 0; i < TEXT; i++) {
        graphic->indic.text[i] = sfText_create();
        if (graphic->indic.text[i] == NULL)
            return (false);
        sfText_setFont(graphic->indic.text[i], graphic->indic.font);
        sfText_setCharacterSize(graphic->indic.text[i], size);
        sfText_setColor(graphic->indic.text[i], sfWhite);
        sfText_setPosition(graphic->indic.text[i], pos);
        pos.y += size + (15.0 / 1080) * graphic->video.height;
    }
    return (ini_strings(graphic));
}
