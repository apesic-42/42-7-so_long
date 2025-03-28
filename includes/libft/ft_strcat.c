
#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
