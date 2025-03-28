
#include "libft.h"

void	*ft_memcpy(const void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return ((void *)dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	dst[123] = "OUI.CEST BON";
// 	char	dst2[123] = "OUI.CEST BON";

// 	printf("%s\n", (char *)ft_memcpy(dst + 3, dst, 10));
// 	printf("%s\n", (char *)memcpy(dst2 + 3, dst2, 10));
// 	return (0);
// }
