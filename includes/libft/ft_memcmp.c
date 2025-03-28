
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*ok = "QUELLE BELLE JOURNEE AUJOURD'HUI";
// 	char	*okok = "JOUR";

// 	printf("%d\n", ft_memcmp(ok, okok, 25));
// 	printf("%d\n", memcmp(ok, okok, 25));
// 	return (0);
// }
