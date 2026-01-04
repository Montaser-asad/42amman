/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:33:03 by masad             #+#    #+#             */
/*   Updated: 2026/01/04 19:51:52 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_atol(n[i]) == ft_atol(n[j]))
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
