#include "../includes/so_long.h"


void map_checker(char *path, t_game *game)
{
	m_create(path, game);
	check_valid_shape(game);
	check_elements(game);
	check_borders(game);
	check_fill(game);
}

static void start_window(t_game *game)
{
	start_mlx(game);
	get_images(game);
	load(game);
	if (mlx_string_put(game->mlx, game->window,
					   (game->map->col * PIXELS - 60) / 2,
					   (game->map->row * PIXELS / 2),
					   0xFFFFFF, "GO!") != 0)
						ft_error("");
}
int main(int ac, char **av)
{
	t_game *so_long;

	so_long = NULL;
	if (ac != 2)
		error_clean(NULL, "./so_long -> .ber", 1);
	check_full_file(av[1]);
	so_long = start_game();
	map_checker(av[1], so_long);
	start_window(so_long);
	mlx_hook(so_long->window, KeyPress, KeyPressMask, listener, so_long);
	mlx_hook(so_long->window, DestroyNotify, 0, exit_game, so_long);
	mlx_loop(so_long->mlx);
	return 0;
}