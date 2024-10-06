/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:55:03 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/20 17:02:46 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_index(t_lists **lst)
{
	t_lists	*temp;
	int		index;
	int		size;
	int		min_value;

	index = 0;
	size = check_lst_size(*lst);
	if (size <= 1)
		return ;
	while (index < size)
	{
		min_value = find_min(*lst);
		temp = *lst;
		while (temp)
		{
			if (temp->value == min_value)
			{
				temp->index = index;
				break ;
			}
			temp = temp->next;
		}
		index++;
	}
}

void	mv_position(t_lists **lst_a)
{
	int	to_bottom;
	int	to_top;
	int	size;

	if (!lst_a || !(*lst_a))
		return ;
	size = check_lst_size(*lst_a);
	to_top = position(*lst_a, find_min);
	to_bottom = size - to_top;
	if (to_top <= to_bottom)
	{
		while (to_top > 0)
		{
			ra(lst_a);
			to_top--;
		}
	}
	else
	{
		while (to_bottom > 0)
		{
			rra(lst_a);
			to_bottom--;
		}
	}
}

long	ft_atoi_n(const char *str)
{
	long	num;
	long	sign;
	int		i;
	long	prev_num;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev_num = num;
		num = (num * 10) + (str[i++] - '0');
		check_overflow(num, prev_num, sign);
	}
	return (sign * num);
}

t_lists	*init_stack_a(char **args)
{
	t_lists	*head;
	t_lists	*new_node;
	long	num;
	int		i;

	head = NULL;
	i = 0;
	while (args[i])
	{
		if (check_num(args[i]))
		{
			num = ft_atoi_n(args[i]);
			if (!check_max_min(num) || !check_duplicate(head, num))
				print_error();
			new_node = ft_lstnew(num);
			if (!new_node)
				print_error();
			ft_lstadd_back(&head, new_node);
		}
		else
			print_error();
		i++;
	}
	return (head);
}

void	sort_stack(t_lists **stack_a, t_lists **stack_b, int argc)
{
	if (argc >= 3 && argc <= 6)
	{
		simple_sort(stack_a, stack_b);
	}
	else
	{
		find_index(stack_a);
		group_sort(stack_a, stack_b, argc);
		while (*stack_b)
		{
			move_to_top(stack_b);
			pa(stack_a, stack_b);
		}
	}
}
