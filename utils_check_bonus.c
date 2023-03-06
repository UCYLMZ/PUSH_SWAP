/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:16 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 10:03:17 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	check_doubles(int **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (*(arr[i]) == *(arr[j]))
			{
				print_error("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	**to_arr(char *str, int *size)
{
	char	**d_str;
	int		**arr;
	int		i;

	d_str = ft_split(str, ' ');
	*size = 0;
	while (d_str[*size])
		(*size)++;
	if (*size == 1)
		return (NULL);
	arr = malloc(sizeof(int *) * (*size));
	if (!arr)
		return (NULL);
	i = 0;
	while (d_str[i])
	{
		arr[i] = malloc(sizeof(int));
		if (!arr[i])
			return (NULL);
		*(arr[i]) = ft_atoi(d_str[i]);
		i++;
	}
	free_double_char(d_str);
	return (arr);
}

int	char_check(char *d)
{
	int	result;

	result = 1;
	while (*d)
	{
		if ((*d < '0' || *d > '9') && (*d != ' '
			&& result % 2 != 0) && (*d != '+' && *d != '-'))
			result *= 2;
		if ((*d >= '0' && *d <= '9') && ((*(d + 1) != ' ')
			&& (*(d + 1) < '0' || *(d + 1) > '9')))
			result *= 3;
		if ((*d == '-' || *d == '+') && (*(d + 1) <= '0'
			|| *(d + 1) > '9') && result % 3 != 0)
			result *= 3;
		d++;
	}
	if (result == 1)
		return (0);
	print_error("Error\n");
	return (1);
}
