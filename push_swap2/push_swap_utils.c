/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:33:03 by masad             #+#    #+#             */
/*   Updated: 2026/01/02 18:33:52 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || ((nptr[i] >= 9 && nptr[i] <= 13) && nptr[i]))
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+' && nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_max(const char *n)
{
	long	num;

	num = ft_atol(n);
	if (num <= INT_MAX && num >= INT_MIN)
		return (1);
	else
		return (0);
}

int	check_dup(const char **n)
{
	int	i;
	int	j;

	i = 0;
	while (n[i])
	{
		j = i + 1;
		while (n[j])
		{
			if (ft_atoi(n[i]) == ft_atoi(n[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_in(const char *n)
{
	if (*n == '-' || *n == '+')
		n++;
	while (*n)
	{
		if (*n >= '0' && *n <= '9')
			n++;
		else
			return (0);
	}
	return (1);
}