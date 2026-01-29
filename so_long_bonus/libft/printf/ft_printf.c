/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:36:06 by masad             #+#    #+#             */
/*   Updated: 2025/09/24 14:49:46 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_char_str(char spec, va_list args, int *count)
{
	char	c;
	char	*str;

	if (spec == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		(*count)++;
	}
	else if (spec == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str, count);
	}
	else if (spec == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

void	handle_numbers(char spec, va_list args, int *count)
{
	if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (spec == 'u')
		ft_putnbr((unsigned int)(va_arg(args, int)), count);
	else if (spec == 'x')
		ft_puthex(va_arg(args, unsigned int), 'a', count);
	else if (spec == 'X')
		ft_puthex(va_arg(args, unsigned int), 'A', count);
	else if (spec == 'p')
		ft_putptr(va_arg(args, unsigned long), count);
}

int	handle_format(const char *specifier, va_list args, int *count)
{
	if (*specifier == 'c' || *specifier == 's' || *specifier == '%')
		handle_char_str(*specifier, args, count);
	else if (*specifier == 'd' || *specifier == 'i')
		handle_numbers(*specifier, args, count);
	else if (*specifier == 'u' || *specifier == 'x')
		handle_numbers(*specifier, args, count);
	else if (*specifier == 'p' || *specifier == 'X')
		handle_numbers(*specifier, args, count);
	else if (*specifier == '%')
	{
		write(1, "%", 1);
		write(1, specifier, 1);
		(*count) += 2;
	}
	else
		(*count) = -1;
	return (2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
			i += handle_format(format + i + 1, args, &count);
		else
		{
			if (format[i] == '%' || count == -1)
				return (-1);
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
