#include "../includes/so_long.h"

void start_game(t_game *game, int fd)
{
	int i;
}

void create_map(t_game *game, int fd)
{
	char *s;
	char *join;

	join = ft_strdup("");
	s = get_next_line(fd);
	if(!s || s[0] == "\n")
		ft_error();
}