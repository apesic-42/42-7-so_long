
#include "libft.h"

int	ft_tablen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
