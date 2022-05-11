#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
// A structure to represent a stack
typedef	struct s_list{
    int data;
    struct s_list *next;
}t_list;

typedef	struct s_stack{
	t_list	*first;
	int	size;
}t_stack;


long	ft_atoi(char *str);
void	stack_init(t_stack *stack);
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
void	desplay(t_stack *stack);

void	rotate(t_stack *stack, char x);
void	reverse_rotate(t_stack *stack, char x);
int		rev_pop(t_stack *stack);

t_stack	*ps_prep(t_stack *stack);
t_stack	*arr_to_stack(t_stack *stack,int *arr);
int 	*do_the_work(t_stack *stack, int *arr, int i, int j);
#endif