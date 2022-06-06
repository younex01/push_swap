/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2_Bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:16 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/06 18:52:17 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_reverse_rotate_Bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_Bonus(stack_a, 0);
	reverse_rotate_Bonus(stack_b, 0);
}

void	double_rotate_Bonus(t_stack *stack_a, t_stack *stack_b)
{
	rotate_Bonus(stack_a, 0);
	rotate_Bonus(stack_b, 0);
}