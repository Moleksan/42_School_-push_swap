/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:26:50 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/13 17:04:43 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*ft_lstnew(long value)
{
	t_lists	*lst;

	lst = malloc(sizeof(t_lists));
	(lst)->value = value;
	(lst)->index = -1;
	(lst)->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_lists **lst, t_lists *new)
{
	t_lists	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	ft_listclear(t_lists **stack)
{
	t_lists	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	find_min(t_lists *lst)
{
	int	min;

	if (lst == NULL)
		return (-1);
	min = INT_MAX;
	while (lst)
	{
		if (lst->value < min && lst->index == -1)
		{
			min = lst->value;
		}
		lst = lst->next;
	}
	return (min);
}

int	find_max(t_lists *lst)
{
	int	max;

	max = INT_MIN;
	while (lst)
	{
		if (lst->value > max)
		{
			max = lst->value;
		}
		lst = lst->next;
	}
	return (max);
}
