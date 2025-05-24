#include "libft.h"

void ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}