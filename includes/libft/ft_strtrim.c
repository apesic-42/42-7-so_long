
#include "libft.h"

int	ft_check(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		len;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_check(set, s1[end]) == 1)
		end--;
	len = end - start + 1;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (start <= end)
		out[i++] = s1[start++];
	out[i] = '\0';
	return (out);
}
