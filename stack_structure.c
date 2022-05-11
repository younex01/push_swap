#include "push_swap.h"

void	stack_init(t_stack *stack){
	stack->first = NULL;
	stack->size = 0;
}

void	push(t_stack *stack, int data)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	// if ((new_list = (t_list *) malloc(sizeof(t_list))) == NULL)
	// 	return -1;
	// if ((new_list->data = (int *) malloc(sizeof(int))) == NULL)
	// 	return -1;	
	new_list->data = data;
	new_list->next = stack->first;
	stack->first = new_list;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*del_list;
	int		val;

	del_list = stack->first;
	val =  del_list->data;
	free(del_list->next);
	stack->first = stack->first->next;
	stack->size--;
	return val;
}

int	rev_pop(t_stack *stack)
{
	t_list	*del_stack;
	int		val;

	del_stack = stack->first;
	while(del_stack->next->next)
	{
		del_stack =  del_stack->next;
	}
	val = del_stack->next->data;
	// free(del_stack->next);
	del_stack->next = NULL;
	stack->size--;
	return val;
}

void	desplay(t_stack *stack)
{
	t_list *courant;

	courant = stack->first;
	while(courant)
	{
		printf("%d\n",courant->data);
		courant = courant->next;
	}
}