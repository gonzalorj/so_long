#include "../includes/so_long.h"

t_map *start_map(void)
{
	t_game *map;

	map = (t_game*)ft_calloc(1, sizeof(t_game));
	if (!map)
		return (NULL);
	return (map);
}

t_graph *start_graphs(void)
{
	t_graph *graphs;

	graphs = (t_game*)ft_calloc(1, sizeof(t_game));
	if (!graphs)
		return (NULL);
	return (graphs);
}

t_game *start_game(void)
{
	t_game *so_long;

	so_long = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!so_long)
		ft_error("Memory allocation failed.");
	so_long->map = start_map();
	if (!so_long->map)
		ft_error("Memory allocation failed.");
	so_long->graphs = start_graphs();
	if(!so_long->graphs)
		ft_error("Memory allocation failed.");
	so_long->rgba = start_rgba();
	so_long->player.moves = 1;
	return(so_long);
}

void start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Mlx failed.");
	game->window = mlx_new_window(game->mlx, (game->map->col * PIXELS),
	(game->map->row * PIXELS), "so_long");
	if (!game->window)
		ft_error("Mlx window failed");
}