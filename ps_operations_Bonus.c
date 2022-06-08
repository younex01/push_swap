/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_Bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:21 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 20:10:07 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_bonus(t_stack *stack)
{
	int	swap;

	if (stack->size < 2)
		return ;
	if (stack->size == 2)
		stack->last = stack->first->data;
	swap = stack->first->next->data;
	stack->first->next->data = stack->first->data;
	stack->first->data = swap;
}

void	double_swap_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	swap_Bonus(stack_a);
	swap_Bonus(stack_b);
}

void	push_x_bonus(t_stack *stack_a, t_stack *stack_b, char x) 
{
	if (!stack_a->size)
		return ;
	if (stack_a->size == 1) //last added
		stack_a->last = stack_a->first->data;
	if (stack_b->size == 1)
		stack_b->last = stack_b->first->data;
	if (x == 'a')
		push(stack_a, pop(stack_b));
	if (x == 'b')
		push(stack_b, pop(stack_a));
}

void	rotate_bonus(t_stack *stack)//
{
	t_list	*courant;
	int		val;

	// if(stack->size < 2)
	// 	return;
	courant = stack->first;
	val = courant->data;
	while (courant->next)
	{
		courant->data = courant->next->data;
		courant = courant->next;
	}
	courant->data = val;
	stack->last = val;
}

void	reverse_rotate_bonus(t_stack *stack)
{
	push(stack, rev_pop(stack));
}
