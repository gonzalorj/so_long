#include "../includes/so_long.h"

void init(t_game *game)
{
	game->image_height = 64;
	game->image_width = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, 
					game->height * 64, "so_long");
	
}