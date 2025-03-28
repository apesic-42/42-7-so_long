
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	unc;

	str = (unsigned char *)s;
	unc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == unc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*ok = "QUELLE BELLE JOURNEE AUJOURD'HUI";
// 	char	c = 'A';

// 	printf("%p\n", ft_memchr(ok, c, 25));
// 	printf("%p\n", memchr(ok, c, 25));
// 	return (0);
// }
