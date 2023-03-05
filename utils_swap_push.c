/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:43 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/03/05 03:58:16 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!(*stack_a))
		return ;
	if ((*(*stack_a)->content > t_data.max_b))
		t_data.max_b = *(*stack_a)->content;
	if ((*(*stack_a)->content < t_data.min_b))
		t_data.min_b = *(*stack_a)->content;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	(*stack_a) = temp;
	t_data.size_a -= 1;
	t_data.size_b += 1;
	ft_putstr("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	(*stack_b) = temp;
	t_data.size_a += 1;
	t_data.size_b -= 1;
	ft_putstr("pa\n");
}

void	sa(t_list **stack_a)
{
	t_list	*temp_n_n;
	t_list	*temp_root;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	temp_n_n = (*stack_a)->next->next;
	temp_root = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp_root;
	(*stack_a)->next->next = temp_n_n;
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	t_list	*temp_n_n;
	t_list	*temp_root;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	temp_n_n = (*stack_b)->next->next;
	temp_root = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp_root;
	(*stack_b)->next->next = temp_n_n;
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
