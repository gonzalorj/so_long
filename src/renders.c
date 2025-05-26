/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:17 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:19:17 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*mlx_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		error_clean(game, "Mlx img failed.", 1);
	return (img);
}

void	get_images(t_game *game)
{
	game->graphs->background = mlx_image(game, "sprites/background.xpm");
	game->graphs->collectible = mlx_image(game, "sprites/collectible.xpm");
	game->graphs->exit = mlx_image(game, "sprites/exit.xpm");
	game->graphs->player = mlx_image(game, "sprites/player.xpm");
	game->graphs->wall = mlx_image(game, "sprites/wall.xpm");
}

static void	*pos_value(t_game *game, int pos)
{
	void	*img;

	img = NULL;
	if (pos == '1')
		img = game->graphs->wall;
	else if (pos == 'E')
		img = game->graphs->exit;
	else if (pos == 'C')
		img = game->graphs->collectible;
	else if (pos == '0' || pos == 'P')
		img = game->graphs->background;
	if (!img)
		ft_error("");
	return (img);
}

void	load(t_game *game)
{
	void	*img;
	int		row;
	int		col;

	row = 0;
	while (game->map->mat[row] != NULL)
	{
		col = 0;
		while (game->map->mat[row][col])
		{
			img = pos_value(game, game->map->mat[row][col]);
			mlx_put_image_to_window(game->mlx, game->window, img,
				col * PIXELS, row * PIXELS);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->graphs->player,
		game->player.col * PIXELS,
		game->player.row * PIXELS);
}
