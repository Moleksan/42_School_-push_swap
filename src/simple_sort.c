/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:04:47 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/12 16:31:51 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_lists **lst)
{
	if (lst && *lst && (*lst)->next)
	{
		if ((*lst)->value > (*lst)->next->value)
		{
			sa(lst);
		}
	}
}

void	sort_three(t_lists **lst)
{
	int	first;
	int	second;
	int	third;

	if (!(*lst)->next->next)
		return ;
	first = (*lst)->value;
	second = (*lst)->next->value;
	third = (*lst)->next->next->value;
	if (first < third && third < second)
	{
		sa(lst);
		ra(lst);
	}
	else if (first > third && first < second)
		rra(lst);
	else if (second < third && third < first)
		ra(lst);
	else if (first > second && first < third)
		sa(lst);
	else if (first > second && second > third)
	{
		sa(lst);
		rra(lst);
	}
}

void	sort_four(t_lists **lst_a, t_lists **lst_b)
{
	mv_position(lst_a);
	pb(lst_b, lst_a);
	sort_three(lst_a);
	pa(lst_a, lst_b);
}

void	sort_five(t_lists **lst_a, t_lists **lst_b)
{
	int	count;

	count = 0;
	if (check_lst_size(*lst_a) < 5)
		return ;
	while (count < 2)
	{
		mv_position(lst_a);
		pb(lst_b, lst_a);
		count++;
	}
	sort_three(lst_a);
	pa(lst_a, lst_b);
	pa(lst_a, lst_b);
}

void	simple_sort(t_lists **stack_a, t_lists **stack_b)
{
	int	size;

	size = check_lst_size(*stack_a);
	if (size == 2)
	{
		sort_two(stack_a);
	}
	else if (size == 3)
	{
		sort_three(stack_a);
	}
	else if (size == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if (size == 5)
	{
		sort_five(stack_a, stack_b);
	}
}
