#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

typedef struct s_game
{
	void *player;
	void *collectible;
	void *exit;
	void *wall;
	void *back;
}	t_game;

typedef struct s_map
{
	int x;
	int y;
	char **map;
}	t_map;

#endif