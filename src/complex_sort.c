/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:33:24 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/20 17:49:04 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	group_sort(t_lists **lst_a, t_lists **lst_b, int total_count)
{
	int	bl_size;
	int	sorted_count;

	bl_size = block_size(total_count);
	sorted_count = 0;
	while (*lst_a)
	{
		if ((*lst_a)->index <= sorted_count)
		{
			pb(lst_b, lst_a);
			if (check_lst_size(*lst_b) > 1)
				rb(lst_b);
			sorted_count++;
		}
		else if ((*lst_a)->index <= sorted_count + bl_size)
		{
			pb(lst_b, lst_a);
			sorted_count++;
		}
		else
		{
			ra(lst_a);
		}
	}
}

void	move_to_top(t_lists **lst_b)
{
	int	total_size;
	int	dist_to_up;
	int	dist_to_down;
	int	max_distance;

	total_size = check_lst_size(*lst_b);
	max_distance = position(*lst_b, find_max);
	dist_to_up = max_distance;
	dist_to_down = total_size - max_distance;
	if (dist_to_up <= dist_to_down)
	{
		while (dist_to_up > 0)
		{
			rb(lst_b);
			dist_to_up--;
		}
	}
	else
	{
		while (dist_to_down > 0)
		{
			rrb(lst_b);
			dist_to_down--;
		}
	}
}

int	block_size(int count)
{
	int	size;

	size = 1;
	if (count <= 50)
		return (size + 0);
	else if (count <= 100)
		return (size + 5);
	else if (count <= 250)
		return (size + 10);
	else if (count <= 500)
		return (size + 20);
	else
		return (size + 30);
}

int	position(t_lists *lst, int (*f)(t_lists *))
{
	int			dist;
	int			target_value;
	t_lists		*current;

	dist = 0;
	current = lst;
	if (!lst || !f)
		return (-1);
	target_value = f(lst);
	while (current)
	{
		if (current->value == target_value)
			return (dist);
		current = current->next;
		dist++;
	}
	return (-1);
}
