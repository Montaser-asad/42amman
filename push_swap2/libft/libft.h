/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:34:22 by masad             #+#    #+#             */
/*   Updated: 2026/01/02 19:16:37 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
long		ft_atol(const char *nptr);
int			ft_isdigit(int c);
static int	count(char const *str, char c);
char		*ft_strchr(const char *s, int c);

#endif