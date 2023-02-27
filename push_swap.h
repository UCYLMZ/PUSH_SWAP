#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
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
int		**to_arr(char *str, int *size);
void	free_double_char(char **ptr);
int		check_doubles(int **arr, int size);
t_list	*list_initializer(int size, int **arr);
void	ft_lstclear(t_list **lst);
void	sort_init(t_list *list, int size);
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
int		ft_abs(int a);
void	decider(int target);

#endif