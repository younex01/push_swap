#include "push_swap.h"

void	ps_sortUlti(t_stack *stack_a, t_stack *stack_b)
{
	int	val;
	int	len;
	int start;

	len = stack_a->size;
	val = len/3;
	start = 0;
	while(stack_a->size > 3)
	{
		while(stack_b->size <= start + val)
		{
			// if(stack_b->size > 2 && stack_b->first->data < start + val/2 && stack_a->first->data > val)
			// 	double_rotate(stack_a, stack_b, 1);
			if(stack_b->size > 2 && stack_b->first->data > start && stack_b->first->data < start + val/2)
				rotate(stack_b, 'b');
			if(stack_a->first->data <= start + val)
				push_x(stack_a, stack_b, 'b');
			else
				rotate(stack_a, 'a');
		}
		start += val;
		val = (stack_a->size)/3;
	}
	ps_sort3(stack_a);
	t_list	*courant;
	while(stack_b->size > 0)
	{
		int i = 0;
		courant = stack_b->first;
		while(courant->next != NULL)
		{
			if(courant->data == (stack_b->size - 1))
				break;
			i++;
			courant = courant->next;
		}
		if (i > (stack_b->size / 2))
		{while (stack_b->first->data != (stack_b->size - 1))
			reverse_rotate(stack_b, 'b');}
		else
		{	while (stack_b->first->data != (stack_b->size - 1))
				rotate(stack_b, 'b');}
		push_x(stack_a, stack_b, 'a');
	}
}