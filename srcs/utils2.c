/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apesic <apesicstudent.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:53:51 by apesic            #+#    #+#             */
/*   Updated: 2025/04/09 11:53:53 by apesic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{
			if (map[i][j + 1] == '\0' && j + 1 != x)
			{
				ft_printf("Error\nAll lines doesn't have the same size\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

char	**check_map(char *map_file)
{
	int		fd;
	char	*map;
	char	**map_ok;
	int		len;

	len = ft_strlen(map_file);
	if (len < 5 || ft_strcmp(&map_file[len - 4], ".ber") != 0)
		return (ft_printf("Error\nIncorrect map file\n"), NULL);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nFail to open map file"), NULL);
	map = reead_map(fd);
	if (close(fd) == -1)
		return (perror("Error\nFail to close map file"), free(map), NULL);
	if (!map)
		return (ft_printf("Error\nProblem when readed\n"), NULL);
	map_ok = map_checks(map);
	if (!map_ok)
		return (free(map), NULL);
	return (free(map), map_ok);
}
