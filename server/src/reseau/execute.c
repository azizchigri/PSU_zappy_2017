/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** execute function
*/

#include "server.h"

void clear_cmd(t_client *client)
{
	client->buf[0].time = -1;
	for (int i = 1; i < 10; i += 1) {
		client->buf[i - 1].cmd = client->buf[i].cmd;
		client->buf[i - 1].time = client->buf[i].time;
	}
	client->buf[9].cmd = NULL;
	client->buf[9].time = -1;
}

void eat_client(t_server *server)
{
	t_client *client = server->client;
	if (server->eat == 0) {
		while (client != NULL) {
			if (client->player != NULL) {
				char *str = eat(client->player, server);
				if (str != NULL && strcmp(str, "dead") == 0) {
					FD_CLR(client->fd, &(server->readfds));
					send(client->fd, "dead\n", 5, 0);
					destroy_client(server, client);
					client = NULL;
				}
			}
			if (client != NULL)
				client = client->next;
		}
		server->eat = SERVER_EAT;
	} else
		server->eat -= 1;
}

void check_client_win(t_server *server)
{
	char *status = check_win(server->game);
	if (strcmp(status, "ko") != 0) {
		t_client *client = server->client;
		printf("Le gagnant est:%s\n", status);
		for (; client != NULL; client = client->next) {
			destroy_client(server, client);
		}
		send(server->graph, "seg bbsn\n", strlen("seg bbsn\n"), 0);
		exit(0);
	}
}

int execute_other_cmd(t_server *server, t_client *client, char **tab)
{
	if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
		connect_client(server, client, client->fd, tab);
		return (0);
	}
	if (tab != NULL && strcmp(tab[0], "Graphical") == 0) {
		init_client_graph(server, client);
		return (0);
	}
	if (tab != NULL && strcmp(tab[0], "Broadcast") == 0 &&
	client->buf[0].time == 0) {
		execute_broadcast(server, client);
		return (0);
	}
	return (execute_other_md_next(server, client, tab));
}

int execute_commands(t_server *server)
{
	t_client *client = server->client;
	int result;
	while (client != NULL) {
		char **tab = client->buf[0].cmd;
		result = execute_other_cmd(server, client, tab);
		if (result == -1 && (client->buf[0].time != -1)) {
			manage_cmd(server, client);
		}
		client = client->next;
	}
	eat_client(server);
	check_client_win(server);
	server->egg = check_egg(server, server->egg);
	check_ressources(server);
	return (0);
}
