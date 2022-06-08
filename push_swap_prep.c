/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:27 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 20:11:49 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_prep(t_stack *stack)
{	
	int		*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (int *) malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	arr = do_the_work(stack, arr, i, j);
	stack = arr_to_stack(stack, arr);
	return (stack);
}

int	*do_the_work(t_stack *stack, int *arr, int i, int j)
{
	t_list	*courant_first;
	t_list	*courant_second;

	arr[0] = 0;
	courant_first = stack->first->next;
	while (++i < stack->size)
	{
		j = -1;
		courant_second = stack->first;
		arr[i] = 0;
		while (++j < i)
		{
			if (courant_second->data < courant_first->data)
				arr[i]++;
			else if (courant_second->data > courant_first->data)
				arr[j]++;
			else
				ft_error2(stack);
			courant_second = courant_second->next;
		}
		courant_first = courant_first->next;
	}
	return (arr);
}

t_stack	*arr_to_stack(t_stack *stack, int *arr)
{
	int		i;
	t_list	*courant;

	i = 0;
	courant = stack->first;
	while (i < stack->size)
	{
		courant->data = arr[i];
		courant = courant->next;
		i++;
	}
	return (stack);
}
