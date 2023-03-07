/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:13 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/03/06 23:44:04 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

struct	s_data
{
	t_list	*stack_a;
	t_list	*stack_b;

	int		size_a;
	int		size_b;

	int		min_b;
	int		max_b;

	int		target;

	int		index_a;
	int		index_b;

	int		cost_a;
	int		cost_b;
	int		all_cost;
}	t_data;

char	*all_in_one(int count, char **values);
char	*ft_strjoin_v3(char *s1, char *s2);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
int		char_check(char *data);
void	ft_putstr(char *str);
void	print_error(char *str);
int		**to_arr(char *str, int *size);
void	free_double_char(char **ptr);
int		check_doubles(int **arr, int size);
t_list	*list_initializer(int size, int **arr);
void	ft_lstclear(t_list **lst);
void	sort_init(t_list *list, int size);
int		is_list_sorted(t_list *list);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	is_it_first(int a, t_list *stack_b);
void	low_size_handler(t_list *stack_a);
int		ft_abs(int a);
int		ft_abs_larger(int a, int b);
void	decider(int target);
void	prepare_stack_a(void);
void	prepare_stack_b(void);
void	get_biggest_top(int i);

#endif