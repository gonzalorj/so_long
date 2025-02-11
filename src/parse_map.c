#include "../includes/so_long.h"

void check_borders(char **map, int i, int j)
{
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			ft_error();
		j++;
	}
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			ft_error();
		i++;
	}
	i--;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			ft_error();
		j++;
	}
}

void check_lines_len(char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error();
		i++;
	}
}

void check_inside(t_map *game, char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
				game->player_count++;
			else if (map[i][j] == 'E')
				game->exit_count++;
			else if (map[i][j] == 'C')
				game->consum_count++;
			j++;
		}
		i++;
	}
	check_count(*game);
}

void full_parse_map(t_game *game)
{
	check_borders(game->map, 0, 0);
	check_lines_len(game->map);
	check_inside(game, game->map);
}