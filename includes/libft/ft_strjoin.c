
#include "libft.h"

static int	ft_lenstr(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_lenstr(s1, s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*out;
// 	size_t	i;
// 	size_t	j;
// 	size_t	s1len;
// 	size_t	s2len;

// 	i = 0;
// 	j = 0;
// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	out = malloc(sizeof(char) * (s1len + s2len + 1));
// 	if (!out)
// 		return (NULL);
// 	while (s1[i])
// 		ft_strlcpy(&out[i++], &s1[j++], s1len);
// 	j = 0;
// 	while (s2[j])
// 		ft_strlcpy(&out[i++], &s2[j++], s1len + s2len);
// 	out[i] = '\0';
// 	return (out);
// }
