/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:02:54 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 17:46:32 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stack_b(void)
{
	if (t_data.cost_b > 0)
	{
		while (t_data.cost_b > 0)
		{
			rb(&t_data.stack_b);
			ft_putstr("rb\n");
			t_data.cost_b--;
		}
	}
	else if (t_data.cost_b < 0)
	{
		while (t_data.cost_b < 0)
		{
			rrb(&t_data.stack_b);
			ft_putstr("rrb\n");
			t_data.cost_b++;
		}
	}
}

void	prepare_stack_a(void)
{
	if (t_data.cost_a > 0)
	{
		while (t_data.cost_a > 0)
		{
			ra(&t_data.stack_a);
			ft_putstr("ra\n");
			t_data.cost_a--;
		}
	}
	else if (t_data.cost_a < 0)
	{
		while (t_data.cost_a < 0)
		{
			rra(&t_data.stack_a);
			ft_putstr("rra\n");
			t_data.cost_a++;
		}
	}
}

void	prepare_both(void)
{
	if (t_data.cost_a < 0 && t_data.cost_b < 0)
	{
		while (t_data.cost_a < 0 && t_data.cost_b < 0)
		{
			rrr(&t_data.stack_a, &t_data.stack_b);
			t_data.cost_a++;
			t_data.cost_b++;
		}
	}
	if (t_data.cost_a > 0 && t_data.cost_b > 0)
	{
		while (t_data.cost_a > 0 && t_data.cost_b > 0)
		{
			rr(&t_data.stack_a, &t_data.stack_b);
			t_data.cost_a--;
			t_data.cost_b--;
		}
	}
	prepare_stack_b();
	prepare_stack_a();
}

void	push_swap(void)
{
	t_list	*a_ptr;

	t_data.index_a = 0;
	t_data.all_cost = 2147483647;
	a_ptr = t_data.stack_a;
	while (a_ptr)
	{
		t_data.index_b = 0;
		is_it_first(*(a_ptr->content), t_data.stack_b);
		decider(*(a_ptr->content));
		a_ptr = a_ptr->next;
		t_data.index_a++;
	}
	prepare_both();
	pb(&t_data.stack_a, &t_data.stack_b);
}

void	sort_init(t_list *list, int size)
{
	t_data.stack_a = list;
	t_data.size_a = size;
	t_data.max_b = -2147483648;
	t_data.min_b = 2147483647;
	pb(&t_data.stack_a, &t_data.stack_b);
	pb(&t_data.stack_a, &t_data.stack_b);
	while (t_data.stack_a)
		push_swap();
	get_biggest_top();
	while (t_data.stack_b)
		pa(&t_data.stack_a, &t_data.stack_b);
	//t_list *ptr = t_data.stack_a;
	// while (ptr)
	// {
	// 	printf("a: %d  ", *(ptr->content));
	// 	ptr = ptr->next;
	// }
	// printf("\nbiggest:%d\n", t_data.max_b);
	// printf("lowest:%d\n", t_data.min_b);
}
