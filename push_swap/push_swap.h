/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:34:22 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 20:33:44 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	push_swap(char const *input[]);
int		check_max(const char *n);
int		check_dup(const char **n);
int		check_in(const char *n);
void	short_sort(t_list **a, t_list **b);
int		parse(const char **input);
void	sort(t_list **a, t_list **b);
void	sort_i(t_list **node);
void	radix(t_list **a, t_list **b);
void	free_list(t_list **lst);
void	free_split(char **split);
int		handle_input(char const **argv, char **split);

/* short_sort_utils */
int		is_sorted(t_list *a);
int		find_min(t_list *a);
void	put_min_top(t_list **a);

/* operations */
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
#endif
