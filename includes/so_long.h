#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
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
} t_game;

void clean_tmp_map(char **map, int row);
void error_clean(t_game *game, char *s, int error);
t_map *start_map(void);
t_graph *start_graphs(void);
t_game *start_game(void);
void start_mlx(t_game *game);
void count_elements(t_game *game);
int exit_game(t_game *game);
int listener(int input, t_game *game);
void m_create(char *path, t_game *game);
void check_valid_shape(t_game *game);
void check_elements(t_game *game);
void check_borders(t_game *game);
void check_fill(t_game *game);
void get_images(t_game *game);
void load(t_game *game);

#endif