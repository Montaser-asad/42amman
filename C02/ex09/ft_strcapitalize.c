/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:37:03 by masad             #+#    #+#             */
/*   Updated: 2025/02/13 18:56:10 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[i++] != '\0')
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	i = 0 if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] -= 32;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
		{
			str[i + 1] -= 32;
			i += 2;
		}
		else
			i++;
	}
	return (str);
}
