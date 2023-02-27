#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

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
	// printf("target:%d\n", target);
	// printf("index_a:%d\n", t_data.index_a);
	// printf("index_b:%d\n", t_data.index_b);
	int	current_cost_a;
	int	current_cost_b;

	if (t_data.index_a > t_data.size_a - t_data.index_a)
		current_cost_a = -1 * (t_data.size_a - t_data.index_a);
	else
		current_cost_a = t_data.index_a;
	if (t_data.index_b > t_data.size_b - t_data.index_b)
		current_cost_b = -1 * (t_data.size_b - t_data.index_b);
	else
		current_cost_b = t_data.index_b;
	if (ft_abs(current_cost_a) + ft_abs(current_cost_b) < t_data.all_cost)
	{
		t_data.all_cost = ft_abs(current_cost_a) + ft_abs(current_cost_b);
		t_data.target = target;
		t_data.cost_a = current_cost_a;
		t_data.cost_b = current_cost_b;
		// printf("all_cost:%d\n", t_data.all_cost);
		// printf("cost_on_a:%d\n", t_data.cost_a);
		// printf("cost_on_b:%d\n", t_data.cost_b);
		// printf("target:%d\n", t_data.target);
		// printf("\n");
	}
	// printf("current_cost_a:%d\n", current_cost_a);
	// printf("current_cost_b:%d\n", current_cost_b);
	// printf("\n");
}
