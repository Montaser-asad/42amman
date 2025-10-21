/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:25:53 by masad             #+#    #+#             */
/*   Updated: 2025/02/22 21:06:45 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	one(char *input, char *temp, int *i)
{
	int	j;

	j = 0;
	temp[j] = input[(*i)];
	j++;
	(*i)++;
	//temp[j] = '\0';
}

void	two(char *input, char *temp, int *i)
{
	int	j;
	int	x;

	j = -1;
	x = 0;
	while (x++ < 2)
	{
		temp[j] = input[(*i)];
		j++;
		(*i)++;
		//temp[j] = '\0';
	}
}

void	three(char *input, char *temp, int *i)
{
	int	j;
	int	x;
	
	j = 0;
	x = 0;
	while (x++ < 3)
	{
		temp[j] = input[(*i)];
		j++;
		(*i)++;
		//temp[j] = '\0';
	}
}

void	subarray(char *input)
{
	int	i;
	int	len;
	char	temp[4];

	len = 0;
	while(input[len++]);
	i = 0;
	int *index;

	index = &i;
	while(len)
	{
		if (len % 3 == 1)
		{
			one (input, temp, index);
			len -= 1;
		}
		else if (len % 3 == 2)
		{
			two (input, temp, index);
			len -= 2;
		}	
		else if (len % 3 == 0 )
		{
			three (input, temp, index);
			len -= 3;
		}
	}
}

int	main(void)
{
	subarray("123456789");
	return(0);
}
