/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:07 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:19:07 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **map, int *to_obtain, int row, int col)
{
	if (map[row][col] == '1' || *to_obtain == 0)
		return ;
	if (map[row][col] == 'E' || map[row][col] == 'C')
		(*to_obtain)--;
	map[row][col] = '1';
	flood_fill(map, to_obtain, row, col + 1);
	flood_fill(map, to_obtain, row, col - 1);
	flood_fill(map, to_obtain, row + 1, col);
	flood_fill(map, to_obtain, row - 1, col);
}

static char	*tmp_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)ft_calloc(game->map->row, sizeof(char *));
	if (!map)
		error_clean(game, "Allocation failed", 1);
	while (i < game->map->row)
	{
		map[i] = ft_calloc(game->map->col, sizeof(char));
		if (!map[i])
		{
			clean_tmp_map(map, i);
			error_clean(game, "Memory allocation failed", 1);
		}
		ft_memcpy(map[i], game->map->mat[i], game->map->col);
		i++;
	}
	return (map);
}

void	check_elements(t_game *game)
{
	count_elements(game);
	if (game->map->e_c != 1)
		error_clean(game, "Only 1 exit allowed.", 1);
	if (game->map->p_c != 1)
		error_clean(game, "Only 1 player allowed", 1);
	if (game->map->c_c < 1)
		error_clean(game, "At least 1 collectible necessary", 1);
}

void	check_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->col)
	{
		if (game->map->mat[0][i] != '1' ||
			game->map->mat[game->map->row - 1][i] != '1')
			error_clean(game, "Invalid borders", 1);
		i++;
	}
	i = 0;
	while (i < game->map->row)
	{
		if (game->map->mat[i][0] != '1' ||
			game->map->mat[i][game->map->col - 1] != '1')
			error_clean(game, "Invalid borders", 1);
		i++;
	}
}

void	check_fill(t_game *game)
{
	char	**map;
	int		to_obtain;

	to_obtain = game->map->c_c + game->map->e_c;
	map = tmp_map(game);
	flood_fill(map, &to_obtain, game->player.row, game->player.col);
	if (to_obtain != 0)
	{
		clean_tmp_map(map, game->map->row);
		error_clean(game, "Unreachable collectibles", 1);
	}
	clean_tmp_map(map, game->map->row);
}
