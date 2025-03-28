
#include "libft.h"

int	ft_intlen(int n)
{
	int	lalendeint;

	lalendeint = 0;
	if (n < 0)
	{
		lalendeint++;
		n = -n;
	}
	if (n == 0)
		lalendeint++;
	while (n != 0)
	{
		n /= 10;
		lalendeint++;
	}
	return (lalendeint);
}

char	*lemalloc(int len)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = ft_intlen(nbr);
	result = lemalloc(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + '0');
		nbr /= 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_itoa(-0));
// 	return (0);
// }
