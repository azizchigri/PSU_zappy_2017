/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of cmd
*/

#include "game.h"

Test(parsing_cmd, turn_Right)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 1);
	t_player_p *player = init_player(game, 1);
	msg_r[0] = "Right";
	msg_r[1] = NULL;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game), "OK"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}


Test(parsing_cmd, bad_cmd)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 1);
	t_player_p *player = init_player(game, 1);
	msg_r[0] = "poulet";
	msg_r[1] = NULL;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game), "KO"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}