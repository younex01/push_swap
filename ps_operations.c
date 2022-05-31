/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:21 by yelousse          #+#    #+#             */
/*   Updated: 2022/05/31 17:13:22 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char x)
{
	int	swap;

	if (stack->size < 2)
		return ;
	if (stack->size == 2)
		stack->last = stack->first->data;
	swap = stack->first->next->data;
	stack->first->next->data = stack->first->data;
	stack->first->data = swap;
	if (x == 'a')
		write(1, "sa\n", 3);
	if (x == 'b')
		write(1, "sb\n", 3);
}

void	double_swap(t_stack *stack_a, t_stack *stack_b, char x)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (x)
		write(1, "ss\n", 3);
}

void	push_x(t_stack *stack_a, t_stack *stack_b, char x) 
{
	if(!stack_a->size)
		return;
	if(stack_a->size == 1) //last added
		stack_a->last = stack_a->first->data;
	if(stack_b->size == 1)
		stack_b->last = stack_b->first->data;
	if(x == 'a')
	{
		push(stack_a , pop(stack_b));
		write(1,"pa\n",3);
	}
	if(x == 'b')
	{
		push(stack_b , pop(stack_a));
		write(1,"pb\n",3);
	}
}

void	rotate(t_stack *stack, char x)//
{
	t_list *courant;
	int		val;

	// if(stack->size < 2)
	// 	return;
	courant = stack->first;
	val = courant->data;
	while(courant->next)
	{
		courant->data = courant->next->data;
		courant = courant->next;
	}
	courant->data = val;
	stack->last = val;//last added
	if(x == 'a')
		write(1,"ra\n",3);
	if(x == 'b')
		write(1,"rb\n",3);
}

void	reverse_rotate(t_stack *stack, char x)
{
	push(stack, rev_pop(stack));
	if(x == 'a')
		write(1,"rra\n",4);
	if(x == 'b')
		write(1,"rrb\n",4);
}