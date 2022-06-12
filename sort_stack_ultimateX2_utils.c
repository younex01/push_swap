/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_ultimateX2_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:51:39 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 15:52:12 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_ulti_x2_loop2_p1(t_stack *stack_a, t_stack *stack_b, int x)
{
	while (stack_b->first->data != (stack_a->first->data - 1))
	{
		if (stack_b->first->data > x)
		{
			if (stack_b->first->data != stack_a->first->data - 1)
			{
				x = stack_b->first->data;
				push_x(stack_a, stack_b, 'a');
				rotate(stack_a, 'a');
			}
		}
		else
			reverse_rotate(stack_b, 'b');
	}
}

void	ps_sort_ulti_x2_loop2_p2(t_stack *stack_a, t_stack *stack_b, int x)
{
	while (stack_b->first->data != (stack_a->first->data - 1))
	{
		if (stack_b->first->data > x)
		{
			if (stack_b->first->data != stack_a->first->data - 1)
			{
				x = stack_b->first->data;
				push_x(stack_a, stack_b, 'a');
				rotate(stack_a, 'a');
			}
		}
		else
			rotate(stack_b, 'b');
	}
}
