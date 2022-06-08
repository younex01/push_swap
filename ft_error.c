#include "push_swap.h"

// void	ft_clear(t_stack *stack)
// {
//     int val;

// 	while (stack)
// 		val = pop(stack);
// 	free(stack);
// }

int	ft_error(t_stack *stack_a,t_stack *stack_b)
{
	free(stack_a);
	free(stack_b);
	write(1,"Error\n",6);
	exit(1);
}

