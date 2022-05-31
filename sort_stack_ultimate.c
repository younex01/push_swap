/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:42 by yelousse          #+#    #+#             */
/*   Updated: 2022/05/31 17:13:43 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sortUlti(t_stack *stack_a, t_stack *stack_b,int k)
{
	int	val;
	int	len;
	int start;

	len = stack_a->size;
	val = len/k;
	start = 0;
	while(stack_a->size > 3)
	{
		while(stack_b->size < start + val)
		{
			if(stack_a->first->data < start + val)
				push_x(stack_a, stack_b, 'b');
			else if(stack_b->size > 2 && stack_b->first->data >= start && stack_b->first->data < start + val/2)
				double_rotate(stack_a, stack_b, 1); 
			else if(stack_b->size > 2 && stack_b->first->data >= start && stack_b->first->data < start + val/2)
				rotate(stack_b, 'b');
			else
				rotate(stack_a, 'a');
		}
		start += val;
		val = (stack_a->size) / k;
		if(stack_a->size < 10)
			val = stack_a->size - 3;
	}
	ps_sort3(stack_a);
	t_list	*courant;
	while(stack_b->size)
	{
		int i = 0;
		courant = stack_b->first;
		while(courant->next != NULL)
		{
			if(courant->data == (stack_a->first->data - 1))
				break;
			i++;
			courant = courant->next;
		}
		if (i > (stack_b->size / 2))
		{
			while (stack_b->first->data != (stack_a->first->data - 1) )
				reverse_rotate(stack_b, 'b');
		}
		else
		{			
			while (stack_b->first->data != (stack_a->first->data - 1))
					rotate(stack_b, 'b');
		}
		push_x(stack_a, stack_b, 'a');
	}
}