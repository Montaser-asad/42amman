/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:26:03 by masad             #+#    #+#             */
/*   Updated: 2026/01/20 15:58:16 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;
	long	old_res;

	result = 0;
	sign = 1;
	i = 0;
	old_res = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			sign = -sign;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		if (result < old_res)
			return (__LONG_MAX__);
		old_res = result;
		i++;
	}
	return (result * sign);
}
