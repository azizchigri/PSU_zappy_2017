/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of eject
*/

#include "game.h"

int main()
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	t_player_p *player2;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	player2 = init_player(game, 2, "poulet");
	char *tmp = broadcast(game, player, player2);
	printf("%s\n", tmp);
	return (0);
}