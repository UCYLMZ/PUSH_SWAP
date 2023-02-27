#include "push_swap.h"

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
			rb(&t_data.stack_b);
	}
	else
		while (*(t_data.stack_b->content) != t_data.max_b)
			rrb(&t_data.stack_b);
}

void	prepare_stack_b(void)
{
	if (t_data.cost_b > 0)
	{
		while (t_data.cost_b > 0)
		{
			rb(&t_data.stack_b);
			t_data.cost_b--;
		}
	}
	else if (t_data.cost_b < 0)
	{
		while (t_data.cost_b < 0)
		{
			rrb(&t_data.stack_b);
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
			rb(&t_data.stack_a);
			t_data.cost_a--;
		}
	}
	else if (t_data.cost_a < 0)
	{
		while (t_data.cost_a < 0)
		{
			rrb(&t_data.stack_a);
			t_data.cost_a++;
		}
	}
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
		// printf("cost_on_b_from_is_it_first:%d\n", t_data.index_b);
		decider(*(a_ptr->content));
		a_ptr = a_ptr->next;
		t_data.index_a++;
	}
	prepare_stack_b();
	prepare_stack_a();
	pb(&t_data.stack_a, &t_data.stack_b);
	// printf("final_all_cost:%d\n", t_data.all_cost);
	// printf("final_cost_a:%d\n", t_data.cost_a);
	// printf("final_cost_b:%d\n", t_data.cost_b);
	// printf("final_target:%d\n", t_data.target);
}

void	sort_init(t_list *list, int size)
{
	t_data.stack_a = list;
	t_data.size_a = size;
	t_data.max_b = -2147483648;
	t_data.min_b = 2147483647;
	pb(&t_data.stack_a, &t_data.stack_b);
	pb(&t_data.stack_a, &t_data.stack_b);
	//pb(&t_data.stack_a, &t_data.stack_b);
	while (t_data.stack_a)
		push_swap();
	get_biggest_top();
	while (t_data.stack_b)
		pa(&t_data.stack_a, &t_data.stack_b);
	while (t_data.stack_a)
	{
		printf("a:%d\n", *(t_data.stack_a->content));
		t_data.stack_a = t_data.stack_a->next;
	}
	printf("\n");
	t_list	*ptr = t_data.stack_b;
	while (ptr)
	{
		printf("b:%d\n", *(ptr->content));
		ptr = ptr->next;
	}
	// printf("cost_a: %d\n", t_data.cost_a);
	// printf("index_b: %d\n", t_data.index_b);
}