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