/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2_Bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:16 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 20:05:59 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_reverse_rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_Bonus(stack_a);
	reverse_rotate_Bonus(stack_b);
}

void	double_rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	rotate_Bonus(stack_a);
	rotate_Bonus(stack_b);
}
