#include "../includes/so_long.h"

void start_game(t_game *game, int fd)
{
	int i;

	create_map(game, fd);
	game->width = ft_strlen(game->map[0]);
	i = 0;
	while(game->map[i])
		i++;
	game->height = i;
	if(game->height < 3)
		ft_error();
}

void create_map(t_game *game, int fd)
{
	char *s;
	char *join;

	join = ft_strdup("");
	s = get_next_line(fd);
	if(!s || s[0] == "\n")
		ft_error();
	while(s)
	{
		join = ft_strjoin(join, s);
		free (s);
		s = get_next_line(fd);
	}
	check_line(join);
	free (s);
	game->map = ft_split(join, '\n');
	game->map = ft_split(join, '\n');
	free (join);
	if(!game->map)
		ft_error();
}