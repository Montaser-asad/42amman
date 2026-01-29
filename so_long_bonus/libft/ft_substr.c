/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:09:22 by masad             #+#    #+#             */
/*   Updated: 2026/01/29 18:13:04 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*tmp;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	s += start;
	if (len >= ft_strlen(s))
		return (ft_strdup(s));
	len += 1;
	sub = malloc(len);
	if (!sub)
		return (NULL);
	tmp = sub;
	while (--len)
		*sub++ = *s++;
	*sub = '\0';
	return (tmp);
}
