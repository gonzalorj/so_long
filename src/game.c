/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:18:49 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:18:49 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*start_map(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	return (map);
}

t_graph	*start_graphs(void)
{
	t_graph	*graphs;

	graphs = (t_graph *)ft_calloc(1, sizeof(t_graph));
	if (!graphs)
		return (NULL);
	return (graphs);
}

t_game	*start_game(void)
{
	t_game	*so_long;

	so_long = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!so_long)
		error_clean(NULL, "Game allocation fail.", 1);
	so_long->map = start_map();
	if (!so_long->map)
		error_clean(so_long, "Map allocation fail", 1);
	so_long->graphs = start_graphs();
	if (!so_long->graphs)
		error_clean(so_long, "Image allocatoin fail", 1);
	so_long->player.moves = 1;
	return (so_long);
}

void	start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_clean(game, "Mlx fail.", 1);
	game->window = mlx_new_window(game->mlx, (game->map->col * PIXELS),
			(game->map->row * PIXELS), "so_long");
	if (!game->window)
		error_clean(game, "Mlx window failed", 1);
}

void	count_elements(t_game *game)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			c = game->map->mat[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				error_clean(game, "Invalid chars", 1);
			if (c == 'C')
				game->map->c_c++;
			else if (c == 'E')
				game->map->e_c++;
			else if (c == 'P')
			{
				game->map->p_c++;
				game->player.row = i;
				game->player.col = j;
			}
		}
	}
}
