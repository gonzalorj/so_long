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

