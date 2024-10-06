/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:07 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/12 16:17:05 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lst_swap(t_lists **lst)
{
	t_lists	*head;
	t_lists	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return (0);
	second = (*lst)->next;
	head = second->next;
	second->next = *lst;
	(*lst)->next = head;
	*lst = second;
	return (1);
}

int	lst_rotate(t_lists **lst)
{
	t_lists	*tmp;
	t_lists	*head;

	if (!lst)
		return (0);
	tmp = *lst;
	head = (*lst)->next;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->next->next = NULL;
	*lst = head;
	return (1);
}

int	lst_reverse_rotate(t_lists **lst)
{
	t_lists	*head;
	t_lists	*last;

	if (!lst)
		return (0);
	last = *lst;
	while (last->next->next)
		last = last->next;
	head = last->next;
	last->next = NULL;
	head->next = (*lst);
	*lst = head;
	return (1);
}

int	push(t_lists **src, t_lists **dest)
{
	t_lists	*node_to_move;

	if (*src == NULL)
		return (0);
	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = *dest;
	*dest = node_to_move;
	return (1);
}
