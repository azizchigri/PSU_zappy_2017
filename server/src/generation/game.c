/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** game begins here
*/

#include "game.h"

t_game_p *game_init(int w, int h, int f)
{
	t_game_p *game;

	if (w <= 1 || h <= 1 || f <= 0)
		return (NULL);
	game = malloc(sizeof(t_game_p) * 1);
	if (game == NULL)
		return (NULL);
	game->height = h;
	game->width = w;
	game->f = f;
	game->teams = NULL;
	if (create_map(game) == -1)
		return (NULL);
	return (game);
}
