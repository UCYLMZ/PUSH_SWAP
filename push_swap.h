#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*all_in_one(int count, char **values);
char	*ft_strjoin_v3(char *s1, char *s2);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
int		char_check(char *data);
void	ft_putstr(char *str);
int		*to_arr(char *str, int *size);
int		check_doubles(int *arr, int size);
#endif