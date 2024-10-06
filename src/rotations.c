/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:57:46 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/10 17:15:03 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_lists **lst)
{
	lst_rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_lists **lst)
{
	lst_rotate(lst);
	ft_printf("rb\n");
}

void	rr(t_lists **lst_a, t_lists **lst_b)
{
	lst_rotate(lst_a);
	lst_rotate(lst_b);
	ft_printf("rr\n");
}
