/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2_Bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:16 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 14:34:18 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_reverse_rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_bonus(stack_a);
	reverse_rotate_bonus(stack_b);
}

void	double_rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	rotate_bonus(stack_a);
	rotate_bonus(stack_b);
}
