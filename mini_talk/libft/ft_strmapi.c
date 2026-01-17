/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:05:23 by masad             #+#    #+#             */
/*   Updated: 2025/09/03 12:43:27 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec(char *dst, char const *s, char (*f)(unsigned int, char),
		unsigned int i)
{
	if (s[i] == '\0')
	{
		dst[i] = '\0';
		return (0);
	}
	dst[i] = f(i, s[i]);
	rec(dst, s, f, i + 1);
	return (1);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	rec(res, s, f, 0);
	return (res);
}
