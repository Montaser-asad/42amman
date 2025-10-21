/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:31:34 by masad             #+#    #+#             */
/*   Updated: 2025/09/22 15:36:20 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr(long nb, int *cnt);
void	ft_putstr(char *str, int *cnt);
void	ft_puthex(unsigned int nb, char hex, int *cnt);
void	ft_putptr(unsigned long nb, int *cnt);
int		ft_printf(const char *format, ...);

#endif
