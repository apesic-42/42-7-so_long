
#include "libft.h"

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
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*ok = "IL ETAIT UNE FOIS DANS L'OUEST";
// 	char	c = 'D';

// 	printf("%s\n", ft_strchr(ok, c));
// 	printf("%s\n", strchr(ok, c));
// 	return (0);
// }
