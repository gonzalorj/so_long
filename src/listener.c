#include "../includes/so_long.h"

int exit_game(t_game *game)
{
	error_clean(game, "Game stopped", 0);
	return 0;
}

static void print_moves(t_game *game)
{
	ft_putstr_fd("Moves:", 1);
	ft_putnbr_fd(game->player.moves++, 1);
	write(1, "\n", 1);
	if (game->map->mat[game->player.row][game->player.col] == 'C')
	{
		game->map->mat[game->player.row][game->player.col] = '0';
		game->map->c_c--;
	}
	if (game->map->mat[game->player.row][game->player.col] == 'E' &&
		game->map->c_c == 0)
		error_clean(game, "Game stopped", 0);
}

static void input_move(int input, t_game *game)
{
	int row;
	int col;

	row = game->player.row;
	col = game->player.col;
	if (input == XK_w || input == XK_Up)
		row--;
	else if (input == XK_s || input == XK_Down)
		row++;
	else if (input == XK_a || input == XK_Left)
		col--;
	else if (input == XK_d || input == XK_Right)
		col++;
	else if (input == XK_Escape)
		error_clean(game, "Game stopped", 0);
	if (game->map->mat[row][col] != '1')
	{
		game->player.row = row;
		game->player.col = col;
		print_moves(game);
	}
}



int listener(int input, t_game *game)
{
	if (input == XK_w || input == XK_a || 
		input == XK_s || input == XK_d || input == XK_Escape);
	{
		input_move(input, game);
		load(game);
	}
}