#include "../includes/so_long.h"

int exit_game(t_game *game)
{
	ft_error("closed");
	return 0;
}

static void	input_move(int input, t_game *game)
{
	int	row;
	int	col;

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
		ft_error("game closed");
	if (game->map->mat[row][col] != '1')
	{
		game->player.row = row;
		game->player.col = col;
		print_moves(game);
	}
}

static void print_moves(t_game *game)
{
	ft_putstr("Moves:");
	ft_putnbr(game->player.moves++);
	write(1, "\n", 1);
	if (game->map->mat[game->player.row][game->player.col] == 'C')
	{
		game->map->mat[game->player.row][game->player.col] = '0';
		game->map->c_c--;
	}
	if (game->map->mat[game->player.row][game->player.col] == 'E' &&
		game->map->c_c == 0)
		ft_error("Game finished.");
}

int listener(int input, t_game *game)
{
	if (input == XK_w || input == XK_a || input == XK_s
		|| input == XK_d || input == XK_Escape);
	{
		move(input, game);
		load(game);
	}
}