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
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("\n-- push b x 3 --\n");
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


	rr(&stack_a, &stack_b);
	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("\n-- rr --\n");
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


	rrr(&stack_a, &stack_b);
	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("\n-- rrr --\n");
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

	ss(&stack_a, &stack_b);
	ptr_a = stack_a;
	ptr_b = stack_b;
	printf("\n-- ss --\n");
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
}
