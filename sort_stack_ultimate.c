#include "push_swap.h"

void	ps_sortUlti(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*courant;
	int	val;
	int	len;
	int start;
	int	i;

	len = stack_a->size;
	val = len/3;
	start = 0;
	i = 0;
	while(stack_a->size > 3)
	{
		while(i < val - 1 && stack_a->size > len - val)
		{
			if(stack_a->first->data < val -1 && stack_a->first->data >= start)
			{
				push_x(stack_a, stack_b, 'b');
				i++;
			}
			else
				rotate(stack_a, 'a');
		}
		val = (len - val)/3 + val;

	}
	ps_sort3(stack_a);
	while(stack_b->size > 0)
	{

	}
}