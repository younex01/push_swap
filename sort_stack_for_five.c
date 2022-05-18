#include "push_swap.h"

void	ps_sort3for5(t_stack *stack)
{
	t_list	*courant;

	courant = stack->first;
	if(courant->data == 4 && courant->next->data == 3)
	{	
		swap(stack,'a');
		reverse_rotate(stack,'a');
	}
	else if(courant->data == 4 && courant->next->data == 2)
		rotate(stack,'a');
	else if(courant->data == 3 && courant->next->data == 4)
		reverse_rotate(stack,'a');
	else if(courant->data == 3 && courant->next->data == 2)
		swap(stack,'a');
	else if(courant->data == 2 && courant->next->data == 4)
	{	swap(stack,'a');
		rotate(stack,'a');}
}

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
	ps_sort3for5(stack_a);
	courant = stack_b->first;
	if(courant->data == 0)
		swap(stack_b, 'b');
	push_x(stack_a, stack_b,'a');
	push_x(stack_a, stack_b,'a');
}
