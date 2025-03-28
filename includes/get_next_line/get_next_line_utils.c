
#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	unc;
// 	int				i;

// 	unc = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == unc)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (unc == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	int		i;

// 	if (!s)
// 		return (NULL);
// 	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!dup)
// 		return (NULL);
// 	i = -1;
// 	while (s[++i])
// 		dup[i] = s[i];
// 	dup[i] = '\0';
// 	return (dup);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*out;
// 	size_t	i;
// 	size_t	j;
// 	size_t	s1len;
// 	size_t	s2len;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	out = malloc(sizeof(char) * (s1len + s2len + 1));
// 	if (!out)
// 		return (NULL);
// 	i = -1;
// 	while (++i < s1len)
// 		out[i] = s1[i];
// 	j = -1;
// 	while (++j < s2len)
// 		out[i + j] = s2[j];
// 	out[i + j] = '\0';
// 	return (out);
// }

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	while (++i < len)
// 		str[i] = s[start + i];
// 	str[i] = '\0';
// 	return (str);
// }
