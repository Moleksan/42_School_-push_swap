/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:21:16 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/12 16:31:39 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_overflow(long num, long prev_num, long sign)
{
	if ((sign == 1 && num < prev_num) || (sign == -1 && (-num) > (-prev_num)))
		print_error();
}

int	check_max_min(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	check_duplicate(t_lists *stack_a, long num)
{
	if (!stack_a)
		return (1);
	while (stack_a)
	{
		if (stack_a->value == num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_num(char *str)
{
	int	i;

	i = 1;
	if (ft_isdigit(str[0]) || ((str[0] == '+' || str[0] == '-') && str[1]))
	{
		while (str[i])
		{
			if (!(ft_isdigit(str[i])))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	check_lst_size(t_lists *lst)
{
	t_lists	*current;
	int		size;

	size = 0;
	current = lst;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
