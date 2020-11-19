/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** testing_file_openning
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>

champion_t *ini_champion(char *filepath);
bool read_file(int fd, champion_t *champion, int lenght, bool is_header);

Test(Corewar, file_cant_be_openned, .init = redirect_all_std)
{
    cr_assert_null(ini_champion("nonexising_file.cor"));
    cr_assert_stderr_eq_str("\033[1;35mError: the file can't be red\n");
}

Test(Corewar, wrong_header_prog_size, .init = redirect_all_std)
{
    int fd = open("tests/bandol.s", O_RDONLY);
    champion_t champion;
    header_t header;

    read(fd, &header, sizeof(header_t));
    champion.header = malloc(sizeof(header_t));
    champion.file = malloc(sizeof(char) * 1000);
    cr_assert(read_file(fd, &champion, 1000, false));
    cr_assert_stderr_eq_str("\033[1;35mError: unexpected read size\n");
    free(champion.file);
    free(champion.header);
}
