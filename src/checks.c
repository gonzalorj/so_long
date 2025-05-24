#include "../includes/so_long.h"

void check_name(char *name)
{
	int len;

	len = ft_strlen(name);
	if (!name)
		error_clean(NULL, "You need a map.", 1);
	if (len < 5 || ft_strncmp(name + len - 4, ".ber", 4) != 0)
		error_clean(NULL, "Invalid map extension.", 1);
}

void check_full_file(char *path)
{
	int 	fd;
	char 	*test_line;
	char 	*name;

	if (!ft_strnstr(path, "map/", ft_strlen(path)))
		error_clean(NULL, "Directory name is wrong or doesn't exist.", 1);
	name = ft_strrchr(path, '/');
	if (name[0] != '\0' && name)
		name++;
	else
		error_clean(NULL, "Invalid file name or map/ is empty", 1);
	check_name(name);
	fd = open(path, O_RDONLY);
	if(fd == -1)
		error_clean(NULL, "Error while opening the file.", 1);
	test_line = get_next_line(fd);
	if (!test_line)
		error_clean(NULL, "File is empty", 1);
	while(test_line)
	{
		free(test_line);
		test_line = get_next_line(fd);
	}
	close (fd);
}
