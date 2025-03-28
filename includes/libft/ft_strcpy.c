
#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	size_t	*intdest;
	size_t	*intsrc;
	size_t	len_int;
	size_t	i;

	i = 0;
	if (src)
	{
		intdest = (size_t *)dest;
		intsrc = (size_t *)src;
		len_int = ft_strlen(src) / sizeof(size_t);
		while (i < len_int)
		{
			intdest[i] = intsrc[i];
			i++;
		}
		i *= sizeof(size_t);
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest[i] = '\0', dest);
}
