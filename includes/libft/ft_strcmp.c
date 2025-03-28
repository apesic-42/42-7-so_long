
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*true_s1;
	unsigned char	*true_s2;

	true_s1 = (unsigned char *)s1;
	true_s2 = (unsigned char *)s2;
	i = 0;
	while (true_s2[i] || true_s1[i])
	{
		if (true_s1[i] != true_s2[i])
		{
			if (true_s1[i] < true_s2[i])
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}
