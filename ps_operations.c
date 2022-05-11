#include "push_swap.h"

void	swap(t_stack *stack, char	x)
{
	int	swap;

	if (stack->size < 2)
		return ;
	swap = stack->first->next->data;
	stack->first->next->data = stack->first->data;
	stack->first->data = swap;
	if (x == 'a')
		write(1,"sa\n",3);
	if (x == 'b')
		write(1,"sb\n",3);
}

void	double_swap(t_stack *stack_a, t_stack *stack_b, char x)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if(x)
		write(1,"ss\n",3);
}

void	push_x(t_stack *stack_a, t_stack *stack_b, char x)
{
	push(stack_a , pop(stack_b));
	if(x == 'a')
		write(1,"pa\n",3);
	if(x == 'b')
		write(1,"pb\n",3);
}

void	rotate(t_stack *stack, char x)
{
	t_list *courant;
	int		val;

	courant = stack->first;
	val = courant->data;
	while(courant->next)
	{
		courant->data = courant->next->data;
		courant = courant->next;
	}
	courant->data = val;
	if(x == 'a')
		write(1,"ra\n",3);
	if(x == 'b')
		write(1,"rb\n",3);
}

void	reverse_rotate(t_stack *stack, char x)
{
	int		val;

	val = rev_pop(stack);
	push(stack, val);
	if(x == 'a')
		write(1,"rra\n",4);
	if(x == 'b')
		write(1,"rrb\n",4);
}