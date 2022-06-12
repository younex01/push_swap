/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_for_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:50 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 15:26:32 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort2(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->first->data > stack->first->next->data)
			swap(stack, 'a');
	}
}

void	ps_sort3_do_the_work(t_stack *stack, int val1, int val2, int val3)
{
	if ((val1 > val2 && val2 > val3) && val1 > val3)
	{	
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if ((val1 > val2 && val2 < val3) && val1 > val3)
		rotate(stack, 'a');
	else if ((val1 < val2 && val2 > val3) && val3 < val1)
		reverse_rotate(stack, 'a');
	else if ((val1 > val2 && val2 < val3) && val3 > val1)
		swap(stack, 'a');
	else if ((val1 < val2 && val2 > val3) && val3 > val1)
	{	
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if ((val1 < val2 && val2 < val3) && val3 > val1)
		return ;
}

void	ps_sort3(t_stack *stack)
{
	t_list	*courant;
	int		val1;
	int		val2;
	int		val3;

	if (stack->size < 3)
		return (ps_sort2(stack));
	courant = stack->first;
	val1 = courant->data;
	val2 = courant->next->data;
	val3 = courant->next->next->data;
	ps_sort3_do_the_work(stack, val1, val2, val3);
}
