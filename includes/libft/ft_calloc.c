
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total;
	unsigned char	*ptr;

	total = nmemb * size;
	if (nmemb > 0 && size > 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(sizeof(unsigned char) * total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
