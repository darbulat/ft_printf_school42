#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (lst)
	{
		lst->content = content;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}
