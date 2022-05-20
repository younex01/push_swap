#include "push_swap.h"

void	ps_sort2(t_stack *stack)
{
	if(stack->size == 2)
	{
		if(stack->first->data > stack->first->next->data)
			swap(stack,'a');
	}
}

void	ps_sort3(t_stack *stack)
{
	t_list	*courant;
	int	val1;
	int	val2;
	int	val3;

	if(stack->size < 3)
		return  ps_sort2(stack);
	courant = stack->first;
	val1 = courant->data;
	val2 = courant->next->data;
	val3 = courant->next->next->data;
	if((val1 > val2 && val2 > val3 )&& val1 > val3) // 2 1 0
	{	
		swap(stack,'a');
		reverse_rotate(stack,'a');
	}
	else if((val1 > val2 && val2 < val3 )&& val1 > val3) // 2 0 1
		rotate(stack,'a');
	else if((val1 < val2 && val2 > val3 )&& val3 < val1) // 1 2 0
		reverse_rotate(stack,'a');
	else if((val1 > val2 && val2 < val3) && val3 > val1) // 1 0 2
		swap(stack,'a');
	else if((val1 < val2 && val2 > val3) && val3 > val1) // 0 2 1
	{	swap(stack,'a');
		rotate(stack,'a');}
	else if((val1 < val2 && val2 < val3) && val3 > val1) // 0 1 2
		return;
}
