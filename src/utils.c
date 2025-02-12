#include "../includes/so_long.h"

void check_file(int ac, char **av)
{
	int len;

	len = ft_strlen(av[1]);
	if (len < 5 || ft_strcmp(av[1] + len - 4, ".ber") != 0)
	{
		ft_printf("%s", "Wrong map extension\n");
		exit (1);
	}
}

void check_line(char *str)
{
	if (ft_strnstr(str, "\n\n", ft_strlen(str)) || str[ft_strlen(str) - 1] == '\n')
	{
		ft_printf("Error\nInvalid map format\n");
		exit(1);
	}
}

void check_count(t_game *game)
{
	if (game.player_count != 1 || game.exit_count != 1
		|| game.consum_count < 1)
		ft_error();
}

int flood_fill(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'P')
	{
		game->map[x][y] == 'H';
		aux_fill(game, x, y);
	}
	else if(game->map[x][y] == 'E')
	{
		game->map[x][y];
		game->exit_count--;
	}
	else if (game->map[x][y] == 'C')
	{
		game->map[x][y] = 'H';
		game->count++;
		aux_fill(game, x, y);
	}
	else if (game->map[x][y] == '0')
	{
		game->map[x][y] = 'X'
		aux_fill(data, x, y);
	}
	if (game->exit_count == 0 && 
		game->cons_count == game->count)
		return (0);
	return (1);
}

void aux_fill(t_game *game, x, y)
{
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}