#include "push_swap.h"

void	ps_sort4(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*courant;
	int		size;

	size = stack_a->size;
	while(stack_a->size > 3)
	{
		courant = stack_a->first;
		if(courant->data == 0)
			push_x(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	ps_sort3(stack_a);
	courant = stack_b->first;
	if(courant->data == 0)
		swap(stack_b, 'b');
	if(size == 5)
		push_x(stack_a, stack_b,'a');
	push_x(stack_a, stack_b,'a');
}
