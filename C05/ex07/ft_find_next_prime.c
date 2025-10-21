/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:35:11 by masad             #+#    #+#             */
/*   Updated: 2025/02/25 18:19:52 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0 || nb == 1)
		return (0);
	else if (nb > 1)
	{
		while (nb % i != 0 && i > 1)
			i--;
		if (i == 1)
			return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (&ft_is_prime == 0)
	{
		ft_is_prime(nb);
		nb++;
	}
	return (nb);
}
/*
int	main(void)
{
	printf("%d", ft_find_next_prime(2));
	return (0);
}*/
