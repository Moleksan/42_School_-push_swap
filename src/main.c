/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:35:52 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/20 17:03:33 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**splitt(int argc, char **argv, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			print_error();
		*should_free = 1;
	}
	else
	{
		args = argv + 1;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_lists	*stack_a;
	t_lists	*stack_b;
	char	**args;
	int		should_free;

	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	args = splitt(argc, argv, &should_free);
	stack_a = init_stack_a(args);
	stack_b = NULL;
	if (should_free)
		free_after_ft_split(args);
	if (verify_sorted(&stack_a) || !stack_a)
		return (0);
	sort_stack(&stack_a, &stack_b, argc);
	return (free_stack(stack_a), 0);
}
