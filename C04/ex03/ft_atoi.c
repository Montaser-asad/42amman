/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:19:57 by masad             #+#    #+#             */
/*   Updated: 2025/02/24 15:05:05 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ((str[i] >= 9 && str[i] <= 13) && str[i]))
		i++;
	while (str[i] == '-' || (str[i] == '+' && str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int	main()
{
	printf ("%d", ft_atoi(" 	 	--98789778asefa887"));
	return (0);
}*/
