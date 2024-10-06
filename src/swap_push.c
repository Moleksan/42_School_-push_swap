/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:34:06 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/10 17:12:57 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_lists **lst)
{
	lst_swap(lst);
	print_operation("sa");
}

void	sb(t_lists **lst)
{
	lst_swap(lst);
	print_operation("sb");
}

void	ss(t_lists **lst_a, t_lists **lst_b)
{
	lst_swap(lst_a);
	lst_swap(lst_b);
	print_operation("ss");
}

void	pa(t_lists **lst_b, t_lists **lst_a)
{
	push(lst_a, lst_b);
	print_operation("pa");
}

void	pb(t_lists **lst_a, t_lists **lst_b)
{
	push(lst_b, lst_a);
	print_operation("pb");
}
