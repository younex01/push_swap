/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:33 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 20:38:54 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
		push(stack_a, pop(stack_b));
}

int	ft_is_sort_ckeck(t_stack *stack)
{
	int		i;
	t_list	*courant;

	i = 0;
	courant = stack->first;
	while (courant->next)
	{
		if (courant->data != i)
			return (0);
		courant = courant->next;
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int			i;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc > 1)
	{
		i = 1;
		stack_a = (t_stack *) malloc(sizeof(t_stack));
		stack_init(stack_a);
		stack_b = (t_stack *) malloc(sizeof(t_stack));
		stack_init(stack_b);
		while (i < argc)
		{
			ft_str_int(argv[i], stack_b);
			i++;
		}
		switch_stacks(stack_a, stack_b);
		stack_a = ps_prep(stack_a);
		if (ft_is_sort_ckeck(stack_a))
			return (0);
		desplay(stack_a);
		if (stack_a->size <= 3)
			ps_sort3(stack_a);
		else if (stack_a->size == 4)
			ps_sort4(stack_a, stack_b);
		else if (stack_a->size == 5)
			ps_sort5(stack_a, stack_b);
		else if (stack_a->size <= 100)
			ps_sortUlti(stack_a, stack_b, 3);
		else
			ps_sortUltiX2(stack_a, stack_b, 5);
		printf("||A||\n");
		desplay(stack_a);
	}
	return (0);
}
