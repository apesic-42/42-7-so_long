
#include "libft.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	cnt_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *s, int in, char c)
{
	int	i;

	i = 0;
	while (!(s[in + i] == c || s[in + i] == '\0'))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**out;

	out = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1));
	if (!out)
		return (NULL);
	out[cnt_words(s, c)] = NULL;
	i = 0;
	j = 0;
	while (j < cnt_words(s, c))
	{
		while (s[i] == c)
			i++;
		out[j] = (char *)malloc(sizeof(char) * (word_len(s, i, c) + 1));
		if (!out[j])
			return (free_split(out), NULL);
		out[j][word_len(s, i, c)] = '\0';
		k = 0;
		while (word_len(s, i, c) > 0)
			out[j][k++] = s[i++];
		j++;
	}
	return (out);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	char	*s = "OUI TOUT VA BIEN DANS MA VIE ET TOI ?";
// 	char	c = ' ';
// 	char	**ok = ft_split(s, c);

// 	while (ok[i])
// 	{
// 		printf("%s\n", ok[i]);
// 		i++;
// 	}
// 	return (0);
// }
