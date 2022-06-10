/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:58:38 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/09 13:58:39 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_list	*courant;

	i = 0;
	if (stack_b->size > 0)
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	courant = stack_a->first;
	while (courant->next)
	{
		if (courant->data != i)
		{
			free(stack_a);
			free(stack_b);
			return (0);
		}
		i++;
		courant = courant->next;
	}
	return (1);
}
