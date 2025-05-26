/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:02 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:19:02 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_rows(t_game *game, char *path)
{
	char	*row;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_clean(game, "Fd failed.", 1);
	row = get_next_line(fd);
	while (row)
	{
		game->map->row++;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	close(fd);
	if (game->map->row < 3)
		error_clean(game, "Small map", 1);
	game->map->mat = (char **)ft_calloc(game->map->row + 1, sizeof(char *));
	if (!game->map->mat)
		error_clean(game, "Allocation failed", 1);
}

static void	gnl_cleaner(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

static void	mat_reader(int fd, t_game *game)
{
	char	*line;
	int		i;
	char	*clean_row;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		clean_row = ft_strtrim(line, "\r\n");
		free(line);
		if (!clean_row)
		{
			gnl_cleaner(fd);
			error_clean(game, "Allocation failed", 1);
		}
		game->map->mat[i++] = clean_row;
		line = get_next_line(fd);
	}
	free(line);
	game->map->mat[i] = NULL;
}

void	m_create(char *path, t_game *game)
{
	int	fd;

	get_rows(game, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_clean(game, "Fd error.", 1);
	mat_reader(fd, game);
	close(fd);
}

void	check_valid_shape(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	game->map->col = (int)ft_strlen(game->map->mat[0]);
	if (game->map->col < 3)
		error_clean(game, "Invalid map", 1);
	while (i < game->map->row)
	{
		len = (int)ft_strlen(game->map->mat[i]);
		if (len != game->map->col)
			error_clean(game, "Invalid shape", 1);
		i++;
	}
}
