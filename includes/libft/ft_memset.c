
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	ok[120] = "QUELLE BELLE JOURNEE AUJOURD'HUI";
// 	char	okok[120] = "QUELLE BELLE JOURNEE AUJOURD'HUI";
// 	char	c = 'A';

// 	printf("%s\n", (char *)ft_memset(ok, c, 25));
// 	printf("%s\n", (char *)memset(okok, c, 25));
// 	return (0);
// }
