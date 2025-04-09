/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apesic <apesicstudent.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:17:26 by apesic            #+#    #+#             */
/*   Updated: 2025/04/09 12:17:28 by apesic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

# define WIDTH 64
# define HEIGHT 64

# define IMG_BACK "images/back.xpm"
# define IMG_WALL "images/wall.xpm"
# define IMG_COIN "images/coin.xpm"
# define IMG_PLYR1 "images/player1.xpm"
# define IMG_PLYR2 "images/player2.xpm"
# define IMG_EXIT "images/exit.xpm"

# define CROSS 17
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363

# define ERR_F "Error\n1rst char != 1 | n -> n | invalid char\n"
# define ERR_S "Error\nLast char, p, e != 1 | < 2 n | c < 1\n"
# define ERR_M "Error\nMap too small,minimum size must be 17 chars\n"
# define ERR_F1 "Error\n1rst & last char of lines must be 1\n"

typedef struct s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct s_solong
{
	char		**map;
	t_coords	size;
	t_coords	p_pos;
	t_coords	e_pos;
	int			total_coins;
	int			coins_ok;
	int			moves;
	void		*mlx;
	void		*window;
	void		*back;
	void		*wall;
	void		*coin;
	void		*player1;
	void		*player2;
	void		*exit;
}				t_solong;

/* PARSING */

char			**check_map(char *map_file);
char			*reead_map(int fd);
char			**map_checks(char *map);
int				basic_checks(char *map);
int				is_map_rectangular(char **map);
int				are_limits_ok(char **map);
char			**copy_map(char **map_split);
int				is_solvable(char **map);
int				flood_fill(char **map, t_coords pos);
int				ft_tablen(char **tab);

/* GAME */

void			init_game(t_solong *game, char **map);
void			free_game(t_solong *game);
int				check_screen_size(t_solong *game);
void			init_images(t_solong *game);
void			print_map(t_solong *game);
int				move_player(int keycode, t_solong *game);
int				is_move_possible(int keycode, t_solong *game, int *found_coin);

#endif
