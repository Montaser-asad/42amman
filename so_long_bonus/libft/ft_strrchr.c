/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:50:50 by masad             #+#    #+#             */
/*   Updated: 2025/08/14 01:10:32 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*s)
		s++;
	if ((char)c == '\0')
		return ((char *)s);
	while (s >= p)
		if (*(s--) == (char)c)
			return ((char *)(s + 1));
	return (NULL);
}
