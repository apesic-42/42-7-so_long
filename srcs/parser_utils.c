/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apesic <apesicstudent.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:11:24 by apesic            #+#    #+#             */
/*   Updated: 2025/04/08 15:11:26 by apesic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (free_double_table(map_copy), NULL);
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
			if ((map[y][0] != '1') || (map[y][x + 1] == '\0'
					&& map[y][x] != '1'))
				return (ft_printf(ERR_F1),
					0);
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
