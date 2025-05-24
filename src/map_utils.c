#include "../includes/so_long.h"

void m_create(t_game *game, char *path)
{
	int fd;

	get_rows(game, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_clean(game, "Fd error.", 1);
	mat_reader(fd, game);
	close(fd);
}

static void mat_reader(int fd, t_game *game)
{
	char *line;
	int i;
	char *clean_row;

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
		line = get_next_line;
	}
	free(line);
	game->map->mat[i] = NULL;
}

static void get_rows(t_game *game, char *path)
{
	char *row;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_clean(game, "Fd failed.", 1);
	row = get_next_line(fd);
	while (row)
	{
		game->map->row += 1;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	close(fd);
	if (game->map->row < 3)
		ft_error("Small map");
	game->map->mat = (char **)ft_calloc(game->map->row + 1, sizeof(char *));
	if (!game->map->mat)
		ft_error("Allocation failed.");
}

void check_valid_shape(t_game *game)
{
	int i;
	int len;

	i = 0;
	game->map->col = ft_strlen(game->map->mat[0]);
	if (game->map->col < 3)
		ft_error("Invalid map");
	while (i < game->map->row)
	{
		len = ft_strlen(game->map->mat[i]);
		if (len != game->map->col)
			ft_error("Invalid shape.");
		i++;
	}
}

void count_elements(t_game *game)
{
	char c;
	int i;
	int j;

	i = -1;
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			c = game->map->mat[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				ft_error("Invalid char");
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