
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	out;

	i = 0;
	sign = 1;
	out = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - '0';
		i++;
	}
	return (out * sign);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*ok = "  -5464654";
// 	printf("%d\n", ft_atoi(ok));
// 	printf("%d\n", atoi(ok));
// 	return (0);
// }
