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

typedef struct s_graphics
{
	void *player;
	void *collectible;
	void *exit;
	void *wall;
	void *floor;
}	t_graphics;

typedef struct s_map
{
	int width;
	int height;
	int moves;
	int player_x;
	int player_y;
	char **map;
	int n_collect;
	int exit_x;
	int exit_y;
}	t_map;

#endif