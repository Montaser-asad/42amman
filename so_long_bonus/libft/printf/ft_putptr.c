/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:17:53 by masad             #+#    #+#             */
/*   Updated: 2025/09/22 15:36:24 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_writeptr(unsigned long nb, int *cnt)
{
	char	x;

	(*cnt)++;
	if (nb >= 16)
		ft_writeptr(nb / 16, cnt);
	x = (nb % 16);
	if (x <= 9)
		x = (nb % 16) + '0';
	else
		x += ('a' - 10);
	write(1, &x, 1);
}

void	ft_putptr(unsigned long nb, int *cnt)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		(*cnt) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*cnt) += 2;
	ft_writeptr(nb, cnt);
}
