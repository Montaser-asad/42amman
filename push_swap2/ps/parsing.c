/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:05:01 by masad             #+#    #+#             */
/*   Updated: 2026/01/06 20:37:32 by masad            ###   ########.fr       */
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
			if (ft_atol(n[i]) > ft_atol(n[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	check_sort(const char **n)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (n[i] && n[i + 1])
	{
		if (n[i] > n[i + 1])
			r = 1;
		i++;
	}
	return (r);
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

int	parse(const char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (!check_in(input[i]) || !check_max(input[i]))
			return (1);
		else
			i++;
	}
	if (!check_dup(input))
		return (1);
	if (!check_sort(input))
		return (2);
	return (0);
}