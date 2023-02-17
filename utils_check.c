#include "push_swap.h"

int	check_doubles(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr("*** The arguments must not repeat!\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int *to_arr(char *str, int *size)
{
	char	**d_str;
	int		*arr;
	int		i;

	d_str = ft_split(str, ' ');
	*size = 0;
	while (d_str[*size])
		(*size)++;
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	i = 0;
	while (d_str[i])
	{
		arr[i] = ft_atoi(d_str[i]);
		i++;
	}
	return (arr);
}

int	char_check(char *d)
{
	int	result;

	result = 1;
	while (*d)
	{
		if ((*d < '0' || *d > '9') && (*d != ' ' && result % 2 != 0) && (*d != '+' && *d != '-'))
			result *= 2;
		if ((*d == '-' || *d == '+') && (*(d + 1) <= '0' || *(d + 1) > '9') && result % 3 != 0)
			result *= 3;
		d++;
	}
	if (result == 1)
		return (0);
	ft_putstr("Error\n");
	if (result % 2 == 0)
		ft_putstr("*** All arguments must be integer!\n");
	if (result % 3 == 0)
		ft_putstr("*** Sign of arguments must be valid!\n");
	return (1);
}
