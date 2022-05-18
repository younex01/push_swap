#include "push_swap.h"

void	ps_sort3(t_stack *stack)
{
	t_list	*courant;

	courant = stack->first;
	if(courant->data == 2 && courant->next->data == 1)
	{	
		swap(stack,'a');
		reverse_rotate(stack,'a');
	}
	else if(courant->data == 2 && courant->next->data == 0)
		rotate(stack,'a');
	else if(courant->data == 1 && courant->next->data == 2)
		reverse_rotate(stack,'a');
	else if(courant->data == 1 && courant->next->data == 0)
		swap(stack,'a');
	else if(courant->data == 0 && courant->next->data == 2)
	{	swap(stack,'a');
		rotate(stack,'a');}
	else if(courant->data == 0 && courant->next->data == 1)
		exit(0);
}