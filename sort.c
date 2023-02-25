#include "push_swap.h"

void	coast_on_b(int a, t_list *stack_b, int coast_a)
{
	t_list	*last;
	t_list	*actual;
	int		index;

	last = t_data.stack_b;
	while (last->next)
		last = last->next;
	if (a < *(last->content) && a > *(t_data.stack_a->content))
		t_data.coast_b = 0;
	actual = t_data.stack_b;
	last = t_data.stack_b->next;
	index = 0;
	while (last->next)
	{
		if (a > *(actual->content) && a < *(last->content))
			t_data.coast_b = index;
		actual = actual->next;
		last = last->next;
		index++;
	}
}

// void	move_target(t_list *stack_a, t_list *stack_b)
// {

// }

void	push_swap(void)
{
	t_list	*a_ptr;
	int		coast_a;

	coast_a = 0;
	while (a_ptr)
	{
		coast_on_b(*(a_ptr->content), t_data.stack_b, coast_a);
		a_ptr = a_ptr->next;
		coast_a++;
	}
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
	while (t_data.stack_b)
		pa(&t_data.stack_a, &t_data.stack_b);
}

	// while (t_data.stack_a)
	// {
	// 	printf("a:%d\n", *(t_data.stack_a->content));
	// 	t_data.stack_a = t_data.stack_a->next;
	// }
	// while (t_data.stack_b)
	// {
	// 	printf("b:%d\n", *(t_data.stack_b->content));
	// 	t_data.stack_b = t_data.stack_b->next;
	// }
	// printf("coast_a: %d\n", t_data.coast_a);
	// printf("coast_b: %d\n", t_data.coast_b);