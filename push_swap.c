#include "push_swap.h"

int main(int argc, char *argv[])
{
	int i;
	t_stack* stack_a;
	t_stack* stack_b;


	i = argc - 1;
	stack_a =  (t_stack *) malloc(sizeof(t_stack));
	stack_init(stack_a);
	stack_b =  (t_stack *) malloc(sizeof(t_stack));
	stack_init(stack_b);
	while(i > 0)
	{
		push(stack_a, atoi(argv[i]));
		i--;
	}
	desplay(stack_a);
	stack_a = ps_prep(stack_a);
	if(stack_a->size == 3)
		ps_sort3(stack_a);
	if(stack_a->size == 5)
		ps_sort5(stack_a, stack_b);
	if(stack_a->size > 5)
	{
		ps_sortUlti(stack_a, stack_b);
	}
	printf("\n");
	desplay(stack_b);
	printf("\n");
	return 0;
}
