
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	int	ok[5] = {1, 2, 3, 4, 5};

// 	while (i < 5)
// 		printf("%d\n", ok[i++]);
// 	ft_bzero(ok, 4);
// 	i = 0;
// 	while (i < 5)
// 		printf("%d\n", ok[i++]);
// 	return (0);
// }
