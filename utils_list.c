#include "push_swap.h"

void	ft_lstdelone(t_list **lst)
{
	if (!lst)
		return ;
	free((*lst)->content);
	free(*lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(lst);
		*lst = tmp;
	}
}

t_list	*ft_lstnew(int *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_list	*list_initializer(int size, int **arr)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (i < size)
		ft_lstadd_back(&lst, ft_lstnew(arr[i++]));
	return (lst);
}
