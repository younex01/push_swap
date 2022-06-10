/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:58:14 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/09 13:58:17 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_clear(t_stack *stack)
// {
//     int val;

// 	while (stack)
// 		val = pop(stack);
// 	free(stack);
// }

int	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_error2(t_stack *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(1);
}
