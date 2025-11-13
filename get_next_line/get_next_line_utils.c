/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:44:07 by masad             #+#    #+#             */
/*   Updated: 2025/11/13 19:25:21 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dest;
	s = src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);size_t	i;

	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}


char	*
ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
		if (*(s++) == (char)c)
			return ((char *)(s - 1));
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
