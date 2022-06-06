
#include "push_swap.h"

int ft_is_sort(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    t_list *courant;

	i = 0;
    if(stack_b->size > 0)
    {
        free(stack_a);
        free(stack_b);
        return(0);
    }
    courant = stack_a->first;
    while(courant->data)
    {
        if(courant->data != i)
        {
            free(stack_a);
            free(stack_b);
            return(0);
        }
        i++;
        courant = courant->next;
    }
    return (1);
}