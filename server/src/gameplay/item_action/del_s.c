/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** delete stone for incantation
*/

#include "game.h"

int del_s1(t_game_p *game, t_player_p *player)
{
	int x = player->x;
	int y = player->y;
	int tmp = game->map[x][y].linemate;
	if (player->lvl == 1 || player->lvl == 2
	|| player->lvl == 4 || player->lvl == 5
	|| player->lvl == 6)
		game->map[x][y].linemate -= 1;
	else if (player->lvl == 7 || player->lvl == 3)
		game->map[x][y].linemate -= 2;
	if (game->map[x][y].linemate < 0) {
		game->map[x][y].linemate = tmp;
		return (-1);
	}
	return (0);
}

int del_s2(t_game_p *game, t_player_p *player)
{
	int x = player->x;
	int y = player->y;
	int tmp = game->map[x][y].deraumere;
	if (player->lvl == 2 || player->lvl == 4)
		game->map[x][y].deraumere -= 1;
	else if (player->lvl == 7
		|| player->lvl == 6 || player->lvl == 5)
		game->map[x][y].deraumere -= 2;
	if (game->map[x][y].deraumere < 0) {
		game->map[x][y].deraumere = tmp;
		return (-1);
	}
	return (0);
}

int del_s3(t_game_p *game, t_player_p *player)
{
	int x = player->x;
	int y = player->y;
	int tmp = game->map[x][y].sibur;
	if (player->lvl == 2 || player->lvl == 3
	|| player->lvl == 5)
		game->map[x][y].sibur -= 1;
	else if (player->lvl == 7 || player->lvl == 4)
		game->map[x][y].sibur -= 2;
	else if (player->lvl == 6)
		game->map[x][y].sibur -= 3;
	if (game->map[x][y].sibur < 0) {
		game->map[x][y].sibur = tmp;
		return (-1);
	}
	return (0);
}

int del_s4(t_game_p *game, t_player_p *player)
{
	int x = player->x;
	int y = player->y;
	int tmp = game->map[x][y].mendiane;
	if (player->lvl == 5)
		game->map[x][y].mendiane -= 3;
	else if (player->lvl == 7)
		game->map[x][y].mendiane -= 2;
	if (game->map[x][y].mendiane < 0) {
		game->map[x][y].mendiane = tmp;
		return (-1);
	}
	return (0);
}

int del_s5(t_game_p *game, t_player_p *player)
{
	int x = player->x;
	int y = player->y;
	int tmp = game->map[x][y].phiras;
	if (player->lvl == 4 || player->lvl == 6)
		game->map[x][y].phiras -= 1;
	else if (player->lvl == 7 || player->lvl == 3)
		game->map[x][y].phiras -= 2;
	if (game->map[x][y].mendiane < 0) {
		game->map[x][y].phiras = tmp;
		return (-1);
	}
	return (0);
}
