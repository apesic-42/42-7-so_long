
#include "get_next_line.h"

/* size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	unc;
	int				i;

	unc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == unc)
			return ((char *)&s[i]);
		i++;
	}
	if (unc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	out = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < s1len)
		out[i] = s1[i];
	j = -1;
	while (++j < s2len)
		out[i + j] = s2[j];
	out[i + j] = '\0';
	return (out);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
} */

char	*read_and_update_backup(int fd, char *backup, ssize_t b_read)
{
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
			return (free(backup), free(buff), NULL);
		else if (b_read == 0)
			break ;
		buff[b_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (free(buff), backup);
}

char	*extract_line_from_backup_else(char **backup)
{
	char	*line;

	line = ft_strdup(*backup);
	if (!line)
		return (NULL);
	free(*backup);
	*backup = NULL;
	return (line);
}

char	*extract_line_from_backup(char **backup, size_t i)
{
	char	*line;
	char	*tmp;

	while ((*backup)[i] != '\0' && (*backup)[i] != '\n')
		i++;
	if ((*backup)[i] == '\n')
	{
		line = ft_substr(*backup, 0, i + 1);
		if (!line)
			return (NULL);
		tmp = ft_strdup(*backup + i + 1);
		if (!tmp)
			return (NULL);
		free(*backup);
		*backup = tmp;
		if (**backup == '\0')
		{
			free(*backup);
			*backup = NULL;
		}
	}
	else
		line = extract_line_from_backup_else(backup);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	size_t		i;
	ssize_t		b_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	b_read = 1;
	backup = read_and_update_backup(fd, backup, b_read);
	if (!backup)
		return (NULL);
	i = 0;
	line = extract_line_from_backup(&backup, i);
	return (line);
}

/* int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	return (0);
} */
