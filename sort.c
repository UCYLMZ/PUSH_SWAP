#include "push_swap.h"

void	sort_init(t_list *list, int size)
{
	t_data.stack_a = list;
	t_data.size_a = size;
	t_data.max_b = -2147483648;
	t_data.min_b = 2147483647;

	// t_list *ptr_a = stack_a;
	// t_list *ptr_b = stack_b;
	// printf("\n");
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


	pb(&t_data.stack_a, &t_data.stack_b);
	// pb(&t_data.stack_a, &t_data.stack_b);
	// pb(&t_data.stack_a, &t_data.stack_b);
	// pb(&t_data.stack_a, &t_data.stack_b);
	// pb(&t_data.stack_a, &t_data.stack_b);
	// pb(&t_data.stack_a, &t_data.stack_b);
	t_list *ptr_a = t_data.stack_a;
	t_list *ptr_b = t_data.stack_b;
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

	printf("size_b:%d\n", t_data.size_b);
	printf("size_a:%d\n", t_data.size_a);
	printf("min_b:%d\n", t_data.min_b);
	printf("max_b:%d\n", t_data.max_b);

	// rr(&stack_a, &stack_b);
	// ptr_a = stack_a;
	// ptr_b = stack_b;
	// printf("\n-- rr --\n");
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


	// rrr(&stack_a, &stack_b);
	// ptr_a = stack_a;
	// ptr_b = stack_b;
	// printf("\n-- rrr --\n");
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

	// ss(&stack_a, &stack_b);
	// ptr_a = stack_a;
	// ptr_b = stack_b;
	// printf("\n-- ss --\n");
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
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
}
