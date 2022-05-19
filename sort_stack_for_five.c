#include "push_swap.h"

void	ps_sort5(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*courant;

	while(stack_a->size > 3)
	{
		courant = stack_a->first;
		if(courant->data == 0 || courant->data == 1)
			push_x(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	ps_sort3(stack_a);
	courant = stack_b->first;
	if(courant->data == 0)
		swap(stack_b, 'b');
	push_x(stack_a, stack_b,'a');
	push_x(stack_a, stack_b,'a');
}
