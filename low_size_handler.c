/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_size_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:56:41 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/03/05 03:56:53 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_list *list)
{
	t_list	*next;

	next = list->next;
	while (next)
	{
		if (*(list->content) > *(next->content))
			return (0);
		list = list->next;
		next = next->next;
	}
	return (1);
}

void	list_reducer(t_list *stack_a)
{
	int	min;
	int	index;

	min = *(stack_a->content);
	index = 0;
	while (stack_a)
	{
		if (*(stack_a->content) <= min)
		{
			min = *(stack_a->content);
			t_data.index_a = index;
			t_data.target = *(stack_a->content);
		}
		stack_a = stack_a->next;
		index++;
	}
	if (t_data.index_a > t_data.size_a - t_data.index_a)
		t_data.cost_a = -1 * (t_data.size_a - t_data.index_a);
	else
		t_data.cost_a = t_data.index_a;
	prepare_stack_a();
	pb(&t_data.stack_a, &t_data.stack_b);
}

void	handle_three(int first, int second, int third, t_list *stack_a)
{
	while (!is_list_sorted(t_data.stack_a))
	{
		if (first > second && first > third)
		{
			ra(&t_data.stack_a);
			ft_putstr("ra\n");
		}
		else if (second > first && second > third)
		{
			rra(&t_data.stack_a);
			ft_putstr("rra\n");
		}
		else if (third > first && third > second)
			sa(&t_data.stack_a);
		first = *(t_data.stack_a->content);
		second = *(t_data.stack_a->next->content);
		third = *(t_data.stack_a->next->next->content);
	}
}

void	low_size_handler(t_list *stack_a)
{
	int	arr[3];
	int	i;

	while (t_data.size_a > 3)
		list_reducer(t_data.stack_a);
	if (t_data.size_a == 2)
		sa(&t_data.stack_a);
	if (is_list_sorted(t_data.stack_a))
		return ;
	else
	{
		i = 0;
		while (stack_a)
		{
			arr[i] = *(stack_a->content);
			stack_a = stack_a->next;
			i++;
		}
		stack_a = t_data.stack_a;
		if (is_list_sorted(t_data.stack_a))
			return ;
		handle_three(arr[0], arr[1], arr[2], stack_a);
	}
}
