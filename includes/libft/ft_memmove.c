
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*undest;
	unsigned char	*unsrc;

	if (!dest && !src)
		return (NULL);
	undest = (unsigned char *)dest;
	unsrc = (unsigned char *)src;
	i = 0;
	if (unsrc < undest)
	{
		while (n-- > 0)
			undest[n] = unsrc[n];
	}
	else
	{
		while (i < n)
		{
			undest[i] = unsrc[i];
			i++;
		}
	}
	return ((void *)dest);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	ok[20] = "CA VA ET TOI";
// 	printf("%s\n", (char *)ft_memmove(ok + 3, ok, 3));
// 	printf("%s\n", (char *)memmove(ok + 3, ok, 3));
// 	return (0);
// }
