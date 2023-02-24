#include "push_swap.h"

void	ra(t_list	**stack_a)
{
	t_list	*temp_a;
	t_list	*last;

	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while((last)->next)
		last = (last)->next;
	(last)->next = temp_a;
	(last)->next->next = NULL;
}

void	rb(t_list	**stack_b)
{
	t_list	*temp_b;
	t_list	*last;

	temp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while((last)->next)
		last = (last)->next;
	(last)->next = temp_b;
	(last)->next->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
