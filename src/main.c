/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:18:57 by gorodrig          #+#    #+#             */
/*   Updated: 2025/05/26 12:18:57 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!name)
		error_clean(NULL, "You need a map.", 1);
	if (len < 5 || ft_strncmp(name + len - 4, ".ber", 4) != 0)
		error_clean(NULL, "Invalid map extension.", 1);
}

void	check_full_file(char *path)
{
	int		fd;
	char	*test_line;
	char	*name;

	if (!ft_strnstr(path, "map/", ft_strlen(path)))
		error_clean(NULL, "Directory name is wrong or doesn't exist.", 1);
	name = ft_strrchr(path, '/');
	if (name && name[1] != '\0')
		name++;
	else
		error_clean(NULL, "Invalid file name or map/ is empty", 1);
	check_name(name);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_clean(NULL, "Error while opening the file.", 1);
	test_line = get_next_line(fd);
	if (!test_line)
		error_clean(NULL, "File is empty", 1);
	while (test_line)
	{
		free(test_line);
		test_line = get_next_line(fd);
	}
	free(test_line);
	close(fd);
}

void	map_checker(char *path, t_game *game)
{
	m_create(path, game);
	check_valid_shape(game);
	check_elements(game);
	check_borders(game);
	check_fill(game);
}

static void	start_window(t_game *game)
{
	start_mlx(game);
	get_images(game);
	load(game);
}

int	main(int ac, char **av)
{
	t_game	*so_long;

	so_long = NULL;
	if (ac != 2)
		error_clean(NULL, "./so_long -> .ber", 1);
	check_full_file(av[1]);
	so_long = start_game();
	map_checker(av[1], so_long);
	start_window(so_long);
	mlx_hook(so_long->window, KeyPress, KeyPressMask, listener, so_long);
	mlx_hook(so_long->window, DestroyNotify, 0, exit_game, so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
