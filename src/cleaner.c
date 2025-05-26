/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:18:43 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:22:19 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_tmp_map(char **map, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->mat)
	{
		while (i < map->row)
		{
			free(map->mat[i]);
			i++;
		}
		free(map->mat);
	}
	free(map);
}

static void	clean_sprites(void *mlx, t_graph *img)
{
	if (img->wall)
		mlx_destroy_image(mlx, img->wall);
	if (img->player)
		mlx_destroy_image(mlx, img->player);
	if (img->background)
		mlx_destroy_image(mlx, img->background);
	if (img->collectible)
		mlx_destroy_image(mlx, img->collectible);
	if (img->exit)
		mlx_destroy_image(mlx, img->exit);
}

static void	clean_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map);
		if (game->graphs)
		{
			if (game->window)
				clean_sprites(game->mlx, game->graphs);
			free(game->graphs);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}

void	error_clean(t_game *game, char *s, int error)
{
	if (game)
		clean_game(game);
	if (error)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(s, 2);
		write(1, "\n", 1);
	}
	exit(0);
}
