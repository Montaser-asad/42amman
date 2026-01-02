/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:34:22 by masad             #+#    #+#             */
/*   Updated: 2026/01/02 19:02:26 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void				sa(t_list **a);
void				sa(t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list *a, t_list *b);
void				rra(t_list *a);
void				rrb(t_list *b);
void				rrr(t_list *a, t_list *b);
void				push(t_list **node, int n);
int					pop(t_list **node);
long				ft_atol(const char *nptr);
int					check_max(const char *n);
int					check_dup(const char **n);
int					check_in(const char *n);
#endif
