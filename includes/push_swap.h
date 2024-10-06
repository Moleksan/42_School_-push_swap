/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:08:01 by moleksan          #+#    #+#             */
/*   Updated: 2024/09/20 17:03:10 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_lists
{
	int				value;
	int				index;
	int				position;
	struct s_lists	*next;
}			t_lists;

//check.c 
void	check_overflow(long num, long prev_num, long sign);
int		check_max_min(long num);
int		check_duplicate(t_lists *stack_a, long num);
int		check_num(char *str);
int		check_lst_size(t_lists *lst);

//complex_sort.c 
void	group_sort(t_lists **lst_a, t_lists **lst_b, int total_count);
void	move_to_top(t_lists **lst_b);
int		block_size(int count);
int		position(t_lists *lst, int (*f)(t_lists *));

//error_handling.c
void	print_error(void);
int		verify_sorted(t_lists **stack);
void	print_operation(const char *optn);
void	free_stack(t_lists *stack);
void	free_after_ft_split(char **split_args);

// input_validation.c
t_lists	*init_stack_a(char **args);
void	sort_stack(t_lists **stack_a, t_lists **stack_b, int argc);
void	mv_position(t_lists **lst_a);
void	find_index(t_lists **lst);
long	ft_atoi_n(const char *str);

//reverse_rotation.c
void	rra(t_lists **lst);
void	rrb(t_lists **lst);
void	rrr(t_lists **lst_a, t_lists **lst_b);

//rotations.c
void	ra(t_lists **lst);
void	rb(t_lists **lst);
void	rr(t_lists **lst_a, t_lists **lst_b);

//simple_sort.c
void	sort_two(t_lists **lst);
void	sort_three(t_lists **lst);
void	sort_four(t_lists **lst_a, t_lists **lst_b);
void	sort_five(t_lists **lst_a, t_lists **lst_b);
void	simple_sort(t_lists **stack_a, t_lists **stack_b);

//stack_operations.c
int		lst_swap(t_lists **lst);
int		lst_rotate(t_lists **lst);
int		lst_reverse_rotate(t_lists **lst);
int		push(t_lists **src, t_lists **dest);

//stack_utils.c
void	ft_listclear(t_lists **stack);
void	ft_lstadd_back(t_lists **lst, t_lists *new);
t_lists	*ft_lstnew(long value);
int		find_min(t_lists *lst);
int		find_max(t_lists *lst);

//swap_push.c 
void	sa(t_lists **lst);
void	sb(t_lists **lst);
void	ss(t_lists **lst_a, t_lists **lst_b);
void	pa(t_lists **lst_b, t_lists **lst_a);
void	pb(t_lists **lst_a, t_lists **lst_b);

//main.c
char	**splitt(int argc, char **argv, int *should_free);

#endif