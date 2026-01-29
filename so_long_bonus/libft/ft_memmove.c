/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:17:30 by masad             #+#    #+#             */
/*   Updated: 2025/09/10 19:40:15 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(void *d, const char *s, size_t n)
{
	unsigned char	*p;

	p = d;
	while (n--)
	{
		*p = *s;
		p++;
		s++;
	}
}

static void	rev_cpy(void *d, const char *s, size_t n)
{
	unsigned char	*p;

	p = d;
	p += n - 1;
	s += n - 1;
	while (n--)
	{
		*p = *s;
		s--;
		p--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if ((unsigned char *)d > (const unsigned char *)s)
		rev_cpy(d, s, n);
	else
		cpy(d, s, n);
	return (dest);
}
