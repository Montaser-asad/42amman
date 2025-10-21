/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 05:40:48 by masad             #+#    #+#             */
/*   Updated: 2025/09/03 13:58:00 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int x)
{
	int	c;

	if (x < 0)
	{
		c = 2;
		x = -x;
	}
	else
		c = 1;
	x /= 10;
	while (x)
	{
		c++;
		x /= 10;
	}
	return (c);
}

static long	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	else if ((power == 0 && nb == 0) || power == 0)
		return (1);
	else if (power > 1)
		nb = nb * ft_pow(nb, power - 1);
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	if (n < 0 && len--)
	{
		*str++ = '-';
		n = -n;
	}
	if (n == 0 && len--)
		*str++ = '0';
	while (len--)
		*str++ = ((n / ft_pow(10, len))) % 10 + '0';
	*str = '\0';
	return (tmp);
}
