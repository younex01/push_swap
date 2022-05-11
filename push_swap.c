#include "push_swap.h"

int main(int argc, char *argv[])
{
	int i;
	t_stack* stack_a;

	i = argc - 1;
	stack_a =  (t_stack *) malloc(sizeof(t_stack));
	stack_init(stack_a);
	while(i > 0)
	{
		push(stack_a, atoi(argv[i]));
		i--;
	}
	desplay(stack_a);
	stack_a = ps_prep(stack_a);
	printf("\n");
	desplay(stack_a);
	return 0;
}
