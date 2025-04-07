
#include "so_long.h"

int	flood_fill(char **map, t_coords pos)
{
	int	count;

	count = 0;
	if (map[pos.y][pos.x] != '0' && map[pos.y][pos.x] != 'C'
		&& map[pos.y][pos.x] != 'E' && map[pos.y][pos.x] != 'P')
		return (0);
	if (map[pos.y][pos.x] == 'C' || map[pos.y][pos.x] == 'E')
		count = 1;
	map[pos.y][pos.x] = 'V';
	count += flood_fill(map, (t_coords){pos.x + 1, pos.y});
	count += flood_fill(map, (t_coords){pos.x - 1, pos.y});
	count += flood_fill(map, (t_coords){pos.x, pos.y + 1});
	count += flood_fill(map, (t_coords){pos.x, pos.y - 1});
	return (count);
}

int	is_solvable(char **map)
{
	int			total_c;
	int			collected_c_and_e;
	t_coords	pos;
	t_coords	player;

	total_c = 0;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == 'C')
				total_c++;
			else if (map[pos.y][pos.x] == 'P')
			{
				player.x = pos.x;
				player.y = pos.y;
			}
		}
	}
	collected_c_and_e = flood_fill(map, player);
	if (collected_c_and_e != total_c + 1)
		return (ft_printf("Error\nUnsovable map\n"), 0);
	return (1);
}

char	**copy_map(char **map_split)
{
	t_coords	pos;
	char		**map_copy;

	pos.y = 0;
	while (map_split[pos.y])
		pos.y++;
	map_copy = malloc(sizeof(char *) * (pos.y + 1));
	if (!map_copy)
		return (NULL);
	map_copy[pos.y] = NULL;
	pos.x = -1;
	while (++pos.x < pos.y)
	{
		map_copy[pos.x] = ft_strdup(map_split[pos.x]);
		if (!map_copy[pos.x])
			return (free_split(map_copy), NULL);
	}
	return (map_copy);
}

int	are_limits_ok(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (map[0][++x])
		if (map[0][x] != '1')
			return (ft_printf("Error\n1rst line chars must be just 1\n"), 0);
	while (map[y + 1])
	{
		x = -1;
		while (map[y][++x])
			if ((map[y][0] != '1')
				|| (map[y][x + 1] == '\0' && map[y][x] != '1'))
				return (ft_printf
					("Error\n1rst & last char of lines must be 1\n"), 0);
		y++;
	}
	x = -1;
	while (map[y][++x])
		if (map[y][x] != '1')
			return (ft_printf("Error\nLast line chars must be just 1\n"), 0);
	return (1);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_map_rectangular(char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = ft_strlen(map[i]);
	y = ft_tablen(map);
	if ((x < 5 && y < 3) || (x < 3 && y < 5))
		return (ft_printf("Error\nMinimum map must be 5x3 | 3x5"), 0);
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j + 1] == '\0' && j + 1 != x)
				return (ft_printf
					("Error\nAll lines doesn't have the same size\n"), 0);
		i++;
	}
	return (1);
}
