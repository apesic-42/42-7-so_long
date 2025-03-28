
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
