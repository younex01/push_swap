/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:16 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 20:06:43 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char x)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (x)
		write(1, "rrr\n", 4);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b, char x)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (x)
		write(1, "rr\n", 3);
}
