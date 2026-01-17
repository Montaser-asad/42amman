/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:26:07 by masad             #+#    #+#             */
/*   Updated: 2026/01/14 21:10:07 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elm;

	elm = (malloc(sizeof(t_list)));
	if (!elm)
		return (NULL);
	elm->index = 0;
	elm->content = content;
	elm->next = (NULL);
	return (elm);
}
