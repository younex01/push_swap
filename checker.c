/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:13 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 19:26:11 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_cmp(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return (swap_bonus(stack_a));
	if (!ft_strncmp(str, "sb\n", 3))
		return (swap_bonus(stack_b));
	if (!ft_strncmp(str, "ss\n", 3))
		return (double_swap_bonus(stack_a, stack_b));
	if (!ft_strncmp(str, "pa\n", 3))
		return (push_x_bonus(stack_a, stack_b, 'a'));
	if (!ft_strncmp(str, "pb\n", 3))
		return (push_x_bonus(stack_a, stack_b, 'b'));
	if (!ft_strncmp(str, "ra\n", 3))
		return (rotate_bonus(stack_a));
	if (!ft_strncmp(str, "rb\n", 3))
		return (rotate_bonus(stack_b));
	if (!ft_strncmp(str, "rra\n", 4))
		return (reverse_rotate_bonus(stack_a));
	if (!ft_strncmp(str, "rrb\n", 4))
		return (reverse_rotate_bonus(stack_b));
	if (!ft_strncmp(str, "rrr\n", 4))
		return (double_reverse_rotate_bonus(stack_a, stack_b));
	if (!ft_strncmp(str, "rr\n", 3))
		return (double_rotate_bonus(stack_a, stack_b));
	else
		ft_error(stack_a, stack_b);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		ft_check_cmp(stack_a, stack_b, read);
		free(read);
		read = get_next_line(0);
	}
}

void	switch_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
		push(stack_a, pop(stack_b));
}

void	ft_main(t_stack *stack_a, t_stack *stack_b)
{
	switch_stacks(stack_a, stack_b);
	stack_a = ps_prep(stack_a);
	ft_sort(stack_a, stack_b);
	if (ft_is_sort(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	if (argc > 1)
	{
		stack_a = (t_stack *) malloc(sizeof(t_stack));
		if (!stack_a)
			return (0);
		stack_init(stack_a);
		stack_b = (t_stack *) malloc(sizeof(t_stack));
		if (!stack_b)
			return (0);
		stack_init(stack_b);
		while (++i < argc)
			ft_str_int(argv[i], stack_b);
		ft_main(stack_a, stack_b);
	}
	return (0);
}
