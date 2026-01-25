/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:39:05 by masad             #+#    #+#             */
/*   Updated: 2025/09/22 15:36:07 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, int *cnt)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*cnt) += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*cnt)++;
	}
}
