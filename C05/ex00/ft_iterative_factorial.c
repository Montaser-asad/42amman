/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:32:35 by masad             #+#    #+#             */
/*   Updated: 2025/02/25 15:59:59 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (nb > 1)
		{
			result = result * (nb - 1);
			nb--;
		}
	}
	return (result);
}

/*int	main(void)
{
	printf("%d", ft_iterative_factorial(31));
	return(0);
}*/
