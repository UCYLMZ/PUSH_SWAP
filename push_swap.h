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
void	sorter(t_list *stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

#endif