/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apesic <apesic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:23:08 by apesic            #+#    #+#             */
/*   Updated: 2024/11/24 14:42:02 by apesic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize <= dlen)
	{
		return (dstsize + slen);
	}
	while (i < dstsize - dlen - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}


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

/* #include <unistd.h>
#include <bsd/string.h>
#include <string.h>


int	main(void)
{
	char	dest[11];
	char	test[11];

	dest[10] = 'a';
	ft_strlcat(dest, "lorem ipsum dolor sit amet", 0);
	write(1, "\n", 1);
	write(1, dest, 15);
	test[10] = 'a';
	strlcat(test, "lorem ipsum dolor sit amet", 0);
	write(1, "\n", 1);
	write(1, test, 15);
}

 */
