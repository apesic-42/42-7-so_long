
#include "so_long.h"

static int	basic_checks_next(char *map, int *p, int *e, int *c)
{
	int	n_nbr;
	int	i;

	n_nbr = 0;
	i = -1;
	while (map[++i])
	{
		if ((map[0] != '1') || (map[i] == '\n' && map[i + 1] == '\n')
			|| !(map[i] == 'P' || map[i] == 'C' || map[i] == 'E'
				|| map[i] == '1' || map[i] == '0' || map[i] == '\n'))
			return (ft_printf("Error\n1rst char != 1 | n -> n | invalid char\n"), 0);
		if (map[i] == '\n')
			n_nbr++;
		if (map[i] == 'P')
			(*p)++;
		if (map[i] == 'E')
			(*e)++;
		if (map[i] == 'C')
			(*c)++;
	}
	if (map[i - 2] != '1' || n_nbr < 2 || *p != 1 || *e != 1 || *c < 1)
		return (ft_printf("Error\nLast char, p, e != 1 | < 2 n | c < 1\n"), 0);
	return (1);
}

int	basic_checks(char *map)
{
	int	map_len;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	map_len = ft_strlen(map);
	if (!map_len)
		return (ft_printf("Error\nEmpty map\n"), 0);
	if (map_len < 17)
		return (ft_printf("Error\nMap too small,minimum size must be 17 chars\n"), 0);
	if (!basic_checks_next(map, &p, &e, &c))
		return (0);
	return (1);
}

char	**map_checks(char *map)
{
	int		is_map_ok;
	char	**map_split;
	char	**map_copy;

	is_map_ok = basic_checks(map);
	if (!is_map_ok)
		return (NULL);
	map_split = ft_split(map, '\n');
	if (!map_split)
		return (ft_printf("Error\nFail when split map\n"), NULL);
	if (!is_map_rectangular(map_split) || !are_limits_ok(map_split))
		return (free_double_table(map_split), NULL);
	map_copy = copy_map(map_split);
	if (!map_copy)
		return (ft_printf("Error\nFail when copy splited map\n"), NULL);
	if (!is_solvable(map_copy))
		return (free_double_table(map_split), free_double_table(map_copy),
			NULL);
	return (free_double_table(map_copy), map_split);
}

char	*reead_map(int fd)
{
	char	*buff;
	char	*line;
	int		len;

	len = 0;
	buff = NULL;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		buff = ft_realloc(buff, len);
		if (!buff)
			return (free(line), ft_printf("Error\nFail when realloc\n"), NULL);
		buff = ft_strcat(buff, line);
		free(line);
		line = get_next_line(fd);
	}
	return (buff);
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
