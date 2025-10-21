/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:27:02 by masad             #+#    #+#             */
/*   Updated: 2025/02/19 10:44:37 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l_d;
	unsigned int	i;
	unsigned int	l_s;
	unsigned int	temp;

	l_s = 0;
	i = 0;
	l_d = 0;
	while (src[l_s] != '\0')
		l_s++;
	while (dest[l_d] != '\0')
		l_d++;
	temp = l_d;
	if (size > temp)
	{
		while (temp < (size - 1) && src[i] != '\0')
		{
			dest[temp] = src[i];
			temp++;
			i++;
		}
		dest[temp] = '\0';
		return (l_s + l_d);
	}
	return (size + l_s);
}
