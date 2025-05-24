#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../includes/ft_printf.h"
#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include <X11/X.h>


# define PIXELS 32

typedef struct s_player
{
	int row;
	int col;
	int moves;
	int points;
} t_player;

typedef struct s_map
{
	char **mat;
	int row;
	int col;
	int p_c;
	int c_c;
	int e_c;
} t_map;

typedef struct s_graph
{
	void *wall;
	void *player;
	void *background;
	void *collectible;
	void *exit;
} t_graph;

typedef struct s_game
{
	void *mlx;
	void *window;
	t_map *map;
	t_graph *graphs;
	t_player player;
	t_rgba rgba;
} t_game;

void error_clean(t_game *game, char *s, int error);
void clean_tmp_map(char **map, int row);
int listener(int input, t_game *game);
int exit_game(t_game *game);

#endif