/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:34:03 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 11:02:24 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	else if ((power == 0 && nb == 0) || power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			result = result * nb;
			power--;
		}
	}
	return (result);
}
/*
int	main(void)
{
	printf("%d",ft_iterative_power(1,4));
	return(0);
}*/
