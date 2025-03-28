
#include "libft.h"

char	*ft_realloc(char *ptr, int len_realloc)
{
	char	*tmp;
	int		i;

	i = ft_strlen(ptr);
	tmp = malloc(sizeof(char) * (i + len_realloc + 1));
	if (!tmp)
		return (free(ptr), NULL);
	tmp[0] = '\0';
	tmp = ft_strcpy(tmp, ptr);
	free(ptr);
	return (tmp);
}
