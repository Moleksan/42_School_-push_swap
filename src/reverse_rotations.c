/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:54:32 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/10 17:16:28 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_lists **lst)
{
	lst_reverse_rotate(lst);
	ft_printf("rra\n");
}

void	rrb(t_lists **lst)
{
	lst_reverse_rotate(lst);
	ft_printf("rrb\n");
}

void	rrr(t_lists **lst_a, t_lists **lst_b)
{
	lst_reverse_rotate(lst_a);
	lst_reverse_rotate(lst_b);
	ft_printf("rrr\n");
}
