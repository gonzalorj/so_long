#include "../includes/so_long.h"

int main(int ac, char **av)
{
	t_game *game;
	int row;
	int column;
	int fd;

	if(ac ! 2)
		exit(1);
	game = ft_calloc(1, sizeof(t_game));
	check_file(ac, av);
	fd = open(av[1], 0_O_RDONLY);
	if (fd < 0)
		ft_error();
	start_game(t_game *game, int fd);
	
}