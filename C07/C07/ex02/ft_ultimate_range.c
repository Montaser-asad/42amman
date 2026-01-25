/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:36:43 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 19:05:36 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include<stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	range[0] = (int *)malloc(sizeof(int) * (max - min));
	if (range[0] == NULL)
		return (-1);
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	range[0][i] = '\0';
	return (i);
}

/*int	main(void)
{
	int	*ptr;
	int	i;
	int	n;

	i = 0;
	n = ft_ultimate_range(&ptr,9, 0);
	while (i < 0)
	{
		printf("%d", ptr[i]);
		i++;
	}printf("%d", n);
	return (0);
}*/
