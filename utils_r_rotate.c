/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:34 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 15:54:20 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	**nuller;
	t_list	*temp_last;
	t_list	*temp_a;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	temp_a = *stack_a;
	nuller = stack_a;
	temp_last = (*stack_a)->next;
	while (temp_last->next)
	{
		temp_last = temp_last->next;
		*nuller = (*nuller)->next;
	}
	(*nuller)->next = NULL;
	*stack_a = temp_last;
	(*stack_a)->next = temp_a;
}

void	rrb(t_list **stack_b)
{
	t_list	**nuller;
	t_list	*temp_last;
	t_list	*temp_b;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	temp_b = *stack_b;
	nuller = stack_b;
	temp_last = (*stack_b)->next;
	while (temp_last->next)
	{
		temp_last = temp_last->next;
		*nuller = (*nuller)->next;
	}
	(*nuller)->next = NULL;
	*stack_b = temp_last;
	(*stack_b)->next = temp_b;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr("rrr\n");
}
