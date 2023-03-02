/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:28 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 17:54:10 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_where(int a, t_list *stack_b)
{
	t_list	*next;
	t_list	*actual;

	actual = stack_b;
	next = stack_b->next;
	while (next)
	{
		t_data.index_b++;
		if (a < *(actual->content) && a > *(next->content))
			return ;
		actual = next;
		next = next->next;
	}
}

void	biggest_lowest(int a, t_list *stack_b)
{
	t_list	*ptr_b;

	ptr_b = stack_b;
	if (a > t_data.min_b && a < t_data.max_b)
		return (find_where(a, stack_b));
	if (a < t_data.min_b)
	{
		while (*(ptr_b->content) != t_data.max_b)
		{
			ptr_b = ptr_b->next;
			t_data.index_b++;
		}
	}
	else if (a > t_data.max_b)
	{
		while (*(ptr_b->content) != t_data.max_b)
		{
			ptr_b = ptr_b->next;
			t_data.index_b++;
		}
	}
}

void	is_it_first(int a, t_list *stack_b)
{
	t_list	*last;

	last = t_data.stack_b;
	while (last->next)
		last = last->next;
	if (a < *(last->content) && a > *(t_data.stack_b->content))
	{
		t_data.index_b = 0;
		return ;
	}
	return (biggest_lowest(a, stack_b));
}

void	decider(int target)
{
	int	current_cost_a;
	int	current_cost_b;
	int	current_all_cost;

	if (t_data.index_a > t_data.size_a - t_data.index_a)
		current_cost_a = -1 * (t_data.size_a - t_data.index_a);
	else
		current_cost_a = t_data.index_a;
	if (t_data.index_b > t_data.size_b - t_data.index_b)
		current_cost_b = -1 * (t_data.size_b - t_data.index_b);
	else
		current_cost_b = t_data.index_b;
	if ((current_cost_a > 0 && current_cost_b > 0) || (current_cost_a < 0 && current_cost_b < 0))
		current_all_cost = ft_abs_larger(current_cost_a, current_cost_b);
	else
		current_all_cost = ft_abs(current_cost_a) + ft_abs(current_cost_b);
	if (current_all_cost < t_data.all_cost)
	{
		t_data.all_cost = current_all_cost;
		t_data.target = target;
		t_data.cost_a = current_cost_a;
		t_data.cost_b = current_cost_b;
	}
}

void	get_biggest_top(void)
{
	t_list	*biggest;
	int		i;

	biggest = t_data.stack_b;
	while (*(biggest->content) != t_data.max_b)
	{
		biggest = biggest->next;
		i++;
	}
	if (i < t_data.size_b - i)
	{
		while (*(t_data.stack_b->content) != t_data.max_b)
		{
			rb(&t_data.stack_b);
			ft_putstr("rb\n");
		}
	}
	else
	{
		while (*(t_data.stack_b->content) != t_data.max_b)
		{
			rrb(&t_data.stack_b);
			ft_putstr("rrb\n");
		}
	}
}
