#include "push_swap.h"

void	sorter(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;

	t_list *ptr_a = stack_a;
	t_list *ptr_b = stack_b;
	printf("\n");
	while (ptr_a)
	{
		printf("a: %d\n", *(ptr_a->content));
		ptr_a = ptr_a->next;
	}
	printf("\n");
	while (ptr_b)
	{
		printf("b: %d\n", *(ptr_b->content));
		ptr_b = ptr_b->next;
	}
	pb(&stack_a, &stack_b);
	sa(&stack_a);
	pb(&stack_a, &stack_b);
	sb(&stack_b);
	pb(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("\n-- push b --\n");
	while (ptr_a)
	{
		printf("a: %d\n", *(ptr_a->content));
		ptr_a = ptr_a->next;
	}
	printf("\n");
	while (ptr_b)
	{
		printf("b: %d\n", *(ptr_b->content));
		ptr_b = ptr_b->next;
	}

	// pa(&stack_a, &stack_b);
	// ptr_a = stack_a;
	// ptr_b = stack_b;
	// printf("\n-- push a --\n");
	// while (ptr_a)
	// {
	// 	printf("a: %d\n", *(ptr_a->content));
	// 	ptr_a = ptr_a->next;
	// }
	// printf("\n");
	// while (ptr_b)
	// {
	// 	printf("b: %d\n", *(ptr_b->content));
	// 	ptr_b = ptr_b->next;
	// }
}
