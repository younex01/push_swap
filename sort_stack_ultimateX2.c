/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_ultimateX2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:45 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 18:55:36 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_x2_lp1_pt1(t_stack *stack_a, t_stack *stack_b, int val, int s)
{
	while (stack_b->size < s + val)
	{
		if (stack_a->first->data < s + val)
			push_x(stack_a, stack_b, 'b');
		else if (stack_b->size > 2 && stack_b->first->data > s)
		{	
			if (stack_b->first->data < s + val / 2)
				double_rotate(stack_a, stack_b, 1);
			else
				rotate(stack_a, 'a');
		}
		else
			rotate(stack_a, 'a');
		if (stack_b->size > 2 && stack_b->first->data > s)
		{
			if (stack_b->first->data < s + val / 2)
				rotate(stack_b, 'b');
		}
	}
}

void	ps_sort_ulti_x2_lp1(t_stack *stack_a, t_stack *stack_b, int val, int s)
{
	while (stack_a->size > 3)
	{
		ps_sort_x2_lp1_pt1(stack_a, stack_b, val, s);
		s += val;
		val = (stack_a->size) / 3;
		if (stack_a->size < 10)
			val = stack_a->size - 3;
	}
}

int	ps_sort_ulti_x2_find_index(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*courant;
	int		i;

	i = 0;
	courant = stack_b->first;
	while (courant->next != NULL)
	{
		if (courant->data == (stack_a->first->data - 1))
			break ;
		i++;
		courant = courant->next;
	}
	return (i);
}

void	ps_sort_ulti_x2_loop2(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	x;

	while (stack_b->size)
	{
		i = ps_sort_ulti_x2_find_index(stack_a, stack_b);
		x = 0;
		if (stack_a->last < stack_a->first->data)
			x = stack_a->last;
		if (i > (stack_b->size / 2))
			ps_sort_ulti_x2_loop2_p1(stack_a, stack_b, x);
		else
			ps_sort_ulti_x2_loop2_p2(stack_a, stack_b, x);
		push_x(stack_a, stack_b, 'a');
		while (stack_a->last == stack_a->first->data - 1)
		{
			reverse_rotate(stack_a, 'a');
		}
	}
}

void	ps_sort_ulti_x2(t_stack *stack_a, t_stack *stack_b)
{
	int		val;

	val = stack_a->size / 5;
	ps_sort_ulti_x2_lp1(stack_a, stack_b, val, 0);
	ps_sort3(stack_a);
	ps_sort_ulti_x2_loop2(stack_a, stack_b);
}
