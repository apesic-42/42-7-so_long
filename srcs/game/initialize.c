
#include "so_long.h"

void	print_map(t_game *game)
{
	t_coords	c;

	c.y = -1;
	while (game->map[++c.y])
	{
		c.x = -1;
		while (game->map[c.y][++c.x])
		{
			if (game->map[c.y][c.x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, c.x
					* WIDTH, c.y * HEIGHT);
			else if (game->map[c.y][c.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->coin, c.x
					* WIDTH, c.y * HEIGHT);
			else if (game->map[c.y][c.x] == 'P')
				mlx_put_image_to_window
				(game->mlx, game->window, game->player1, c.x
					* WIDTH, c.y * HEIGHT);
			else
				mlx_put_image_to_window(game->mlx, game->window, game->back, c.x
					* WIDTH, c.y * HEIGHT);
		}
	}
}

void	init_images(t_game *game)
{
	t_coords	img;

	img.x = WIDTH;
	img.y = HEIGHT;
	game->back = mlx_xpm_file_to_image(game->mlx, IMG_BACK, &img.x, &img.y);
	if (!game->back || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_BACK\n"), free_game(game));
	game->wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &img.x, &img.y);
	if (!game->wall || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_WALL\n"), free_game(game));
	game->coin = mlx_xpm_file_to_image(game->mlx, IMG_COIN, &img.x, &img.y);
	if (!game->coin || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_COIN\n"), free_game(game));
	game->player1 = mlx_xpm_file_to_image(game->mlx, IMG_PLYR1, &img.x, &img.y);
	if (!game->player1 || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_PLYR1\n"), free_game(game));
	game->player2 = mlx_xpm_file_to_image(game->mlx, IMG_PLYR2, &img.x, &img.y);
	if (!game->player2 || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_PLYR2\n"), free_game(game));
	game->exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT, &img.x, &img.y);
	if (!game->exit || img.x != WIDTH || img.y != HEIGHT)
		(ft_printf("Error\nFFail to load IMG_EXIT\n"), free_game(game));
}

int	is_screen_size_ok(t_game *game)
{
	int	pc_width;
	int	pc_height;

	pc_width = 0;
	pc_height = 0;
	mlx_get_screen_size(game->mlx, &pc_width, &pc_height);
	if (game->size.x * WIDTH > pc_width)
		return (ft_printf("Error\nFMap width too big\n"), 0);
	if (game->size.y * HEIGHT > pc_height)
		return (ft_printf("Error\nFMap height too big\n"), 0);
	return (1);
}

void	init_game(t_game *game, char **map)
{
	game->map = map;
	game->total_coins = 0;
	game->size.y = -1;
	while (map[++game->size.y])
	{
		game->size.x = -1;
		while (map[game->size.y][++game->size.x])
		{
			if (map[game->size.y][game->size.x] == 'C')
				game->total_coins++;
			else if (map[game->size.y][game->size.x] == 'P')
				game->p_pos = game->size;
			else if (map[game->size.y][game->size.x] == 'E')
				game->e_pos = game->size;
		}
	}
	game->coins_ok = 0;
	game->moves = 1;
	game->window = NULL;
	game->back = NULL;
	game->wall = NULL;
	game->coin = NULL;
	game->player1 = NULL;
	game->player2 = NULL;
	game->exit = NULL;
}
