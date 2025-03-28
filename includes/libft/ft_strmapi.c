
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*out;

	out = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
