
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				size;
	unsigned char	unc;

	unc = (unsigned char)c;
	i = 0;
	size = ft_strlen(s);
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	while (size)
	{
		if (s[i] == unc)
			return ((char *)&s[i]);
		i--;
		size--;
	}
	if (s[i] == unc)
		return ((char *)&s[i]);
	return (NULL);
}
