/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:45:16 by masad             #+#    #+#             */
/*   Updated: 2025/02/26 12:14:58 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include<stdio.h>
char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*ptr;

	len = 0;
	i = 0;
	if (src[0])
	{
		while (len)
			len++;
	}
	ptr = char * malloc(len);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main(void)
{
	printf("%s",ft_strdup ("str"));
	return (0);
}*/
