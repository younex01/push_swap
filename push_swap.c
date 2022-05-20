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
	stack_a = ps_prep(stack_a);
	//desplay(stack_a);
	
	if(stack_a->size <= 3)
		ps_sort3(stack_a);
	else if(stack_a->size <= 5)
		ps_sort5(stack_a, stack_b);
	else if(stack_a->size <= 100)
		ps_sortUlti(stack_a, stack_b,3);
	else
		ps_sortUlti(stack_a, stack_b,5);
	// printf("||B||\n");
	// desplay(stack_b);
	// printf("\n");
	// printf("||A||\n");
	// desplay(stack_a);
	// printf("\n");
	return 0;
}
