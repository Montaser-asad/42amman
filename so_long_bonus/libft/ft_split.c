/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:03:34 by masad             #+#    #+#             */
/*   Updated: 2025/09/04 18:58:52 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static int	len(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str && *str++ != c)
		len++;
	return (len);
}

static int	free_all(char **ptr, int l)
{
	while (l--)
		free(ptr[l]);
	free(ptr);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**sqr;
	int		cnt;
	int		i;

	i = 0;
	cnt = count(s, c);
	sqr = (malloc(sizeof(char *) * (cnt + 1)));
	if (!sqr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			sqr[i] = ft_substr(s, 0, len(s, c));
			if (sqr[i++] == NULL)
				if (free_all(sqr, i))
					return (NULL);
		}
		while (*s && *s != c)
			s++;
	}
	sqr[i] = NULL;
	return ((sqr));
}
