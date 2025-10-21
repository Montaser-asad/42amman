/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:41:54 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 11:03:08 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if ((power == 0 && nb == 0) || power == 0)
		return (1);
	else if (power > 1)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
int	main(void)
{
	printf("%d",ft_recursive_power(5,3));
	return(0);
}*/
