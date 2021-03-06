/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inventory cmd
*/

#include "game.h"

char *int_to_str(int nb)
{
	char *str;
	int tmp;
	int size = 1;
	for (tmp = nb; tmp != 0; tmp /= 10)
		size += 1;
	str = malloc(sizeof(char) * (size + 1));
	sprintf(str, "%d", nb);
	return (str);
}

char *init_strcat_stone(char *str_nb, char *respond, int size3)
{
	char *tmp;
	int size2 = 0;
	int size = 0;
	if (respond != NULL)
		size = strlen(respond);
	if (str_nb == NULL)
		return (NULL);
	size2 = strlen(str_nb);
	tmp = malloc(sizeof(char) * (size + size2 + size3 + 1));
	return (tmp);
}

int write_in(char *tmp, char *str1, char *str2)
{
	int i;
	int j;
	int size = 0;
	int size2 = strlen(str2);

	if (str1 != NULL)
		size = strlen(str1);
	for (i = 0; i < size; i += 1)
		tmp[i] = str1[i];
	for (j = 0; j < size2; j += 1) {
		tmp[i] = str2[j];
		i += 1;
	}
	return (i);
}

char *strcat_stone(char *stone_name, int nb_stone, char *respond)
{
	int i;
	int j;
	int size =  0;
	char *tmp;
	char *str_nb = int_to_str(nb_stone);
	tmp = init_strcat_stone(str_nb, respond, strlen(stone_name));
	if (tmp == NULL)
		return (NULL);
	size = strlen(str_nb);
	i = write_in(tmp, respond, stone_name);
	for (j = 0; j < size; j += 1) {
		tmp[i] = str_nb[j];
		i += 1;
	}
	tmp[i] = 0;
	if (respond != NULL)
		free(respond);
	free(str_nb);
	return (tmp);
}

char *inventory(t_player_p *player)
{
	int i;
	char *respond = NULL;
	char *stone[7] = {"linemate ", " deraumere ", " sibur ",
			" mendiane ", " phiras ", " thystame ", " food "};
	int nb_stone[7] = {player->linemate, player->deraumere,
			player->sibur, player->mendiane,
			player->phiras, player->thystame, player->food};
	for (i = 0; i < 7; i += 1) {
		respond = strcat_stone(stone[i], nb_stone[i], respond);
		if (respond == NULL)
			return (NULL);
	}
	return (respond);
}
