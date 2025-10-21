/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:48:58 by masad             #+#    #+#             */
/*   Updated: 2025/02/25 18:17:13 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_fibonacci(int index)
{
	int	n;

	n = 0;
	if (index < 0)
		return (-1);
	else if (index == 1 || index == 2)
		return (1);
	else if (index > 0)
		n = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (n);
}

/*int	main(void)
{
	printf("%d",ft_fibonacci(6));
	return(0);
}*/
