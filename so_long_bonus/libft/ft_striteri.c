/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:31:20 by masad             #+#    #+#             */
/*   Updated: 2025/09/03 12:58:21 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec(char *s, void (*f)(unsigned int, char *), unsigned int i)
{
	if (s[i] == '\0')
		return (0);
	f(i, &s[i]);
	rec(s, f, i + 1);
	return (1);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (!s || !f)
		return ;
	rec(s, f, 0);
}
