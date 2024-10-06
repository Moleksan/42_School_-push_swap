/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:00:47 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/20 16:46:26 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_lists *stack)
{
	t_lists	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_operation(const char *op)
{
	ft_printf("%s\n", op);
}

int	verify_sorted(t_lists **stack)
{
	t_lists	*current;

	if (!(*stack) || !(*stack)->next)
	{
		ft_listclear(stack);
		return (1);
	}
	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	ft_listclear(stack);
	return (1);
}

void	free_after_ft_split(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}
