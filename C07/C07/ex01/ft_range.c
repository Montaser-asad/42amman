/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:33:36 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 17:09:26 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include<stdio.h>
int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (NULL);
	else if (array == NULL)
		return (NULL);
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
int	main(void)
{
	int	*ptr;
	int	i;

	i = 0;
	ptr = ft_range(1, 9);
	while (i < 8)
	{
		printf("%d", ptr[i]);
		i++;
	}
	return (0);
}*/
