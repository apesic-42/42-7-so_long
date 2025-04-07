
#include "so_long.h"

void	free_game(t_solong *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->back)
		mlx_destroy_image(game->mlx, game->back);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->player1)
		mlx_destroy_image(game->mlx, game->player1);
	if (game->player2)
		mlx_destroy_image(game->mlx, game->player2);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_display(game->mlx);
	free_double_table(game->map);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	press_cross(t_solong *game)
{
	return (ft_printf("Game closed with CROSS\n"), free_game(game), 0);
}

int	check_if_end(int keycode, t_solong *game)
{
	if (keycode == ESC_KEY)
		(ft_printf("Game closed with ESC_KEY\n"), free_game(game));
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == UP_KEY || keycode == LEFT_KEY
		|| keycode == DOWN_KEY || keycode == RIGHT_KEY)
	{
		if (move_player(keycode, game) == 1)
		{
			if (game->moves < 2)
				ft_printf("%d move\n", game->moves++);
			else
				ft_printf("%d moves\n", game->moves++);
		}
	}
	if (game->coins_ok == game->total_coins)
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			game->e_pos.x * WIDTH, game->e_pos.y * HEIGHT);
	if (game->coins_ok == game->total_coins && game->p_pos.y == game->e_pos.y
		&& game->p_pos.x == game->e_pos.x)
		(ft_printf("\nWow... you completed this ridiculous difficult level in"),
			ft_printf(" just %d moves ! That's impressive !\n", game->moves - 1),
			ft_printf("Have you ever thought about an e-sport career ?\n\n"),
			free_game(game));
	return (0);
}

int	play(t_solong *game)
{
	init_images(game);
	game->window = mlx_new_window(game->mlx, game->size.x
			* WIDTH, game->size.y * HEIGHT, "so_long");
	if (!game->window)
		return (perror("Error\nFail to create display\n"), free_game(game), 1);
	print_map(game);
	mlx_hook(game->window, 2, 1L, check_if_end, game);
	mlx_hook(game->window, CROSS, 0, press_cross, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}

int	main(int ac, char **av)
{
	char       	**m;
	t_solong	game;

	if (ac != 2)
		return (ft_printf("Error\nUsage: ./so_long <map_file>\n"), 1);
	m = check_map(av[1]);
	if (!m)
		return (1);
	init_game(&game, m);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_double_table(m), perror("Error\nFail to launch MLX\n"), 1);
	if (!check_screen_size(&game))
	{
		(free_double_table(m), mlx_destroy_display(game.mlx), free(game.mlx));
		return (1);
	}
	return (play(&game));
}
