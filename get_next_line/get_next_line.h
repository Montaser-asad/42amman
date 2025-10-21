/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:42:48 by masad             #+#    #+#             */
/*   Updated: 2025/10/06 15:56:20 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
