/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subarraynonorm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:25:53 by masad             #+#    #+#             */
/*   Updated: 2025/02/22 18:09:44 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void print(char *c)
{
	printf("%s \n" ,c);
}

void	subarray(char *input)
{
	int	i;
	int	j;
	int	len;
	int	x;
	char	temp[3];

	len = 0;
	while(input[len])
		len++;
	i = 0;
	while(len)
	{
		j = 0;
		x = 0;
		if (len % 3 == 1)
		{
			temp[j] = input[i++];
			j++;
			len -= 1;
		}
		else if (len % 3 == 2)
		{
			while (x++ < 2)
			{
				temp[j] = input[i++];
				j++;
			}
			len -= 2;
		}	
		else if (len % 3 == 0 )
		{
			while (x++ < 3)
			{
				temp[j] = input[i++];	
				j++;
			}
			len -= 3;
		}
	print(temp);
	}
}

int	main(void)
{
	subarray("98654321");
	return(0);
}
