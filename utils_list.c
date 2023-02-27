/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:31 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 10:03:32 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_list	*new;
	int		i;

	i = 0;
	lst = NULL;
	while (i < size)
	{
		new = ft_lstnew(arr[i++]);
		if (!new)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}
