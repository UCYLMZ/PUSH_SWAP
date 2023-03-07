/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:13 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/03/06 23:44:10 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "./SRC/get_next_line.h"

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

char	*all_in_one(int count, char **values);
char	*ft_strjoin_v3(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
int		char_check(char *data);
void	ft_putstr(char *str);
void	print_error(char *str);
int		**to_arr(char *str, int *size);
void	free_double_char(char **ptr);
int		check_doubles(int **arr, int size);
t_list	*list_initializer(int size, int **arr);
void	ft_lstclear(t_list **lst);
int		is_list_sorted(t_list *list);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif