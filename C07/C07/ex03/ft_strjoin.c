/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:05 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 19:54:48 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
//#include<stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	while (i < size)
	{
		x += ft_strlen(strs[i]);
		i++;
	}
	str = (char *) malloc (x + ft_strlen (sep) * (size - 1));
	i = 0;
	if (strs == NULL)
		return (0);
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i != (size - 1))
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/*int	main(void)
{
	int		size;
	char	*sep;
	char	*strs[] = {"sadf","asdf","asdf","sadf"};
	
	size = 4;
	sep = ", ";
	printf("%s",ft_strjoin(size, strs , sep));
}*/
