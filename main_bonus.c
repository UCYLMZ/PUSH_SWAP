#include "push_swap_bonus.h"

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

void	executer(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(instruction, "pb", 2))
		pb(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa", 2))
		pa(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra", 2))
		ra(stack_a);
	else if (ft_strncmp(instruction, "rb", 2))
		rb(stack_b);
	else if (ft_strncmp(instruction, "rra", 3))
		rra(stack_a);
	else if (ft_strncmp(instruction, "rrb", 3))
		rrb(stack_b);
	else if (ft_strncmp(instruction, "rrr", 3))
		rrr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rr", 2))
		rr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "sa", 2))
		sa(stack_a);
}

int	check_it(t_list *stack_a, char **instructions)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	if (!instructions)
	{
		print_error("Error\n");
		return (0);
	}
	i = 0;
	while (instructions[i])
	{
		executer(instructions[i], &stack_a, &stack_b);
		i++;
	}
	free_double_char(instructions);
	if (is_list_sorted(stack_a) && !stack_b)
		return (1);
	ft_putstr("KO\n");
	return (0);
}

char	**get_instructions(void)
{
	char 	*instructions;
	char	*line;
	char	**result;

	instructions = get_next_line(0);
	line = get_next_line(0);
	while (line)
	{
		instructions = ft_strjoin_v2(instructions, line);
		free (line);
		line = get_next_line(0);
	}
	result = ft_split(instructions, '\n');
	free(instructions);
	return (result);
}

int	main(int ac, char **av)
{
	char	**instructions;
	char	*data_str;
	int		**data_arr;
	int		size;
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	instructions = get_instructions();
	data_str = all_in_one(ac - 1, av + 1);
	if (char_check(data_str))
		return (1);
	data_arr = to_arr(data_str, &size);
	if (!data_arr)
		return (2);
	if (check_doubles(data_arr, size))
		return (1);
	stack_a = list_initializer(size, data_arr);
	if (!stack_a)
		return (2);
	if (check_it(stack_a, instructions))
		ft_putstr("OK\n");
}