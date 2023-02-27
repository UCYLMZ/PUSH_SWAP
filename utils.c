/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:03:47 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/27 10:03:48 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

char	*ft_strjoin_v3(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!result)
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	free(s1);
	result[i++] = ' ';
	result[i] = '\0';
	return (result);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48) * sign;
		if (result > 2147483647 || result < -2147483648)
		{
			ft_putstr("*** All numbers must be in integer value range!\n");
			exit (1);
		}
		i++;
	}
	return ((int)result);
}

char	*all_in_one(int count, char **values)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (i < count)
		result = ft_strjoin_v3(result, values[i++]);
	return (result);
}
