/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:15:35 by masad             #+#    #+#             */
/*   Updated: 2025/09/03 14:01:00 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*end;
	char		*res;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = s1 + ft_strlen(s1);
	while (s1 < end && ft_strchr(set, *(end - 1)))
		--end;
	res = ft_substr(s1, 0, (end - s1));
	return (res);
}
