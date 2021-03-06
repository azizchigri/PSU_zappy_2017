/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server function header
*/

#ifndef PSU_ZAPPY_2017_SERVER_H
#define PSU_ZAPPY_2017_SERVER_H

#define ERROR_PARAM (-84)

#include "reseau.h"
#include "game.h"

#define BUFF_SIZE (2048)
#define SERVER_EAT (125)
#define RESSOURCES_TICK (600)

typedef struct s_buff t_buff;
struct s_buff {
	char **cmd;
	float time;
};

typedef struct s_client t_client;
struct s_client {
	int fd;
	t_player_p *player;
	t_buff buf[10];
	char *buffer;
	t_client *next;
};

typedef struct s_server t_server;
struct s_server {
	int eat;
	int fd_connection;
	int fds_len;
	int higher_fd;
	int graph;
	int ressources;
	t_options options;
	fd_set readfds;
	t_game_p *game;
	t_client *client;
	t_egg *egg;
	int fds[999999];
};

int init_server(t_server *server);
int add_connection(t_server *server);
void read_fd(t_server *server, int fd);
int manage_fd(t_server *server, fd_set set);
int manage_server(t_server *server);
int get_options(int ac __attribute__((unused)), char **av __attribute__(
(unused)), t_server *server);
t_client *add_client(t_client *liste, t_client *client);
int manage_new_client(t_server *server, int fd);
char **str_to_wordtab(char *str);
int execute_commands(t_server *server);
void init_client_player(t_server *server, t_client *client, char **tab);
void add_client_cmd(t_server *server, int fd, char *buff);
int connect_client(t_server *server, t_client *client, int fd, char **tab);
void clear_cmd(t_client *client);
void destroy_client(t_server *server, t_client *client);
char **get_cmd(char *buff);
void manage_buff(t_server *server, char *buff, int fd);
t_client *delete_client(t_client *liste, t_client *delete);
void manage_cmd(t_server *server, t_client *client);
void execute_broadcast(t_server *server, t_client *client);
t_egg *check_egg(t_server *server, t_egg *start);
t_egg *add_egg(t_server *server, t_egg *start, char *team);
void check_ressources(t_server *server);
void execute_incantation(t_server *server, t_client *client);
void execute_incantation_next(t_server *server, t_client *client);
int manage_parameters_cases(int ac, char **av, int c, t_server *server);
int get_int_parameter(char *param);
void get_n_parameter(int ac __attribute__((unused)),
char **av __attribute__((unused)), int index __attribute__((unused)),
		t_server *server);
void init_client_graph(t_server *server, t_client *client);
char *eat(t_player_p *player, t_server *server);
int execute_other_md_next(t_server *server, t_client *client, char **tab);
int launch_server(int ac, char **av);

#endif //PSU_ZAPPY_2017_SERVER_H
