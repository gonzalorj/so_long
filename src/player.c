#include "../includes/so_long.h"

void player_pos(t_game *game, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
	game->player_x = *x;
	game->player_y = *y;
}
