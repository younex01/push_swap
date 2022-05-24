#include "push_swap.h"

void	ps_sortUltiX2(t_stack *stack_a, t_stack *stack_b,int k)
{
	int	val;
	int	len;
	int start;

	len = stack_a->size;
	val = len/k;
	start = 0;
	while(stack_a->size > 3)
	{
		while(stack_b->size < start + val)
		{
			if(stack_a->first->data < start + val)
				push_x(stack_a, stack_b, 'b');
			else if(stack_b->size > 2 && stack_b->first->data >= start && stack_b->first->data < start + val/2)
				double_rotate(stack_a, stack_b, 1); 
			else
				rotate(stack_a, 'a');
			// if(stack_b->size > 2 && stack_b->first->data >= start && stack_b->first->data < start + val/2)
			// 	rotate(stack_b, 'b');
		}
		start += val;
		val = (stack_a->size) / k;
		if(stack_a->size < 10)
			val = stack_a->size - 3;
	}
	ps_sort3(stack_a);
	t_list	*courant;
	int x;
	// else
	// {x = stack_b->first->next->data;}
	int j = 20;
	while(stack_b->size)
	{
		int i = 0;
		courant = stack_b->first;
		while(courant->next != NULL)
		{
			if(courant->data == (stack_a->first->data - 1))
				break;
			i++;
			courant = courant->next;
		}
		x = 0;
		if(stack_a->last < stack_a->first->data)
			x = stack_a->last;
		if (i > (stack_b->size / 2))
		{
			while (stack_b->first->data != (stack_a->first->data - 1) )
			{
				if(stack_b->first->data > x && stack_b->first->data != stack_a->first->data - 1)
				{
					x = stack_b->first->data;
					push_x(stack_a, stack_b, 'a');
					rotate(stack_a, 'a');
				}
				else
					reverse_rotate(stack_b, 'b');
			}
		}
		else
		{	
			
			while (stack_b->first->data != (stack_a->first->data - 1))
			{
				if(stack_b->first->data > x && stack_b->first->data != stack_a->first->data - 1)
				{
					x = stack_b->first->data;
					push_x(stack_a, stack_b, 'a');
					rotate(stack_a, 'a');
				}
				else
					rotate(stack_b, 'b');
			}
		}
		push_x(stack_a, stack_b, 'a');
		while(stack_a->last == stack_a->first->data - 1)
		{
			reverse_rotate(stack_a,'a');
		}
	}
}