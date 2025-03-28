
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	j = 0;
	if (destlen < n)
	{
		while (src[j] && destlen + j < n - 1)
		{
			dest[destlen + j] = src[j];
			j++;
		}
		dest[destlen + j] = '\0';
		return (destlen + srclen);
	}
	return (n + srclen);
}
