
#include "so_long.h"

static int	is_move_up_or_left(int keycode, t_solong *game, int *found_coin)
{
	if ((keycode == W_KEY || keycode == UP_KEY) && game->map[game->p_pos.y
		- 1][game->p_pos.x] != '1')
	{
		if (game->map[game->p_pos.y - 1][game->p_pos.x] == 'C')
		{
			game->map[game->p_pos.y - 1][game->p_pos.x] = '0';
			*found_coin = 1;
		}
		return (game->p_pos.y = game->p_pos.y - 1, 1);
	}
	if ((keycode == A_KEY || keycode == LEFT_KEY)
		&& game->map[game->p_pos.y][game->p_pos.x - 1] != '1')
	{
		if (game->map[game->p_pos.y][game->p_pos.x - 1] == 'C')
		{
			game->map[game->p_pos.y][game->p_pos.x - 1] = '0';
			*found_coin = 1;
		}
		return (game->p_pos.x = game->p_pos.x - 1, 1);
	}
	return (0);
}

static int	is_move_down_or_right(int keycode, t_solong *game, int *found_coin)
{
	if ((keycode == S_KEY || keycode == DOWN_KEY) && game->map[game->p_pos.y
		+ 1][game->p_pos.x] != '1')
	{
		if (game->map[game->p_pos.y + 1][game->p_pos.x] == 'C')
		{
			game->map[game->p_pos.y + 1][game->p_pos.x] = '0';
			*found_coin = 1;
		}
		return (game->p_pos.y = game->p_pos.y + 1, 1);
	}
	if ((keycode == D_KEY || keycode == RIGHT_KEY)
		&& game->map[game->p_pos.y][game->p_pos.x + 1] != '1')
	{
		if (game->map[game->p_pos.y][game->p_pos.x + 1] == 'C')
		{
			game->map[game->p_pos.y][game->p_pos.x + 1] = '0';
			*found_coin = 1;
		}
		return (game->p_pos.x = game->p_pos.x + 1, 1);
	}
	return (0);
}

int	is_move_possible(int keycode, t_solong *game, int *found_coin)
{
	*found_coin = 0;
	if (is_move_up_or_left(keycode, game, found_coin))
		return (1);
	if (is_move_down_or_right(keycode, game, found_coin))
		return (1);
	return (0);
}

int	move_player(int keycode, t_solong *game)
{
	t_coords	old_p_pos;
	int			found_coin;

	old_p_pos = game->p_pos;
	if (is_move_possible(keycode, game, &found_coin) == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->back, old_p_pos.x
			* WIDTH, old_p_pos.y * HEIGHT);
		if (found_coin)
			game->coins_ok++;
		if (game->coins_ok == game->total_coins)
			mlx_put_image_to_window(game->mlx, game->window, game->player2,
				game->p_pos.x * WIDTH, game->p_pos.y * HEIGHT);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->player1,
				game->p_pos.x * WIDTH, game->p_pos.y * HEIGHT);
		return (1);
	}
	return (0);
}
