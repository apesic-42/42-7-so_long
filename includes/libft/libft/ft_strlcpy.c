/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apesic <apesic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:45:03 by apesic            #+#    #+#             */
/*   Updated: 2024/11/14 12:06:44 by apesic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static void	place_st(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	while (i < siz - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	size;

	if (siz == 0)
		return (ft_strlen(src));
	place_st(dst, src, siz);
	size = ft_strlen(src);
	return (size);
}

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

// #include <string.h>
// #include <stdio.h>
// #include <bsd/string.h>
// int main (int c, char **v)
// {
//     (void)c;

//     // char *ok = v[1];
//     // char *le = v[2];
//     // char *ok2 = v[1];
//     // char *le2 = v[2];
//     //ft_strlcpy(v[1], v[2], 2);
//     ft_strlcpy(v[1], "aaa", 0);
//     printf("f : %s\n", v[1]);

//     strlcpy(v[2], "aaa", 0);
//     printf("v : %s\n", v[2]);
// }
