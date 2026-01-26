/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 04:45:50 by masad             #+#    #+#             */
/*   Updated: 2025/09/03 14:00:48 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *b, const char *s, int l)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!*b || !l || *b != *s)
			return (0);
		b++;
		s++;
		l--;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		if (*big == *little)
			if (check(big, little, len))
				return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
