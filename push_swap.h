#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
 
// A structure to represent a stack
typedef	struct s_list{
    int data;
    struct s_list *next;
}t_list;

typedef	struct s_stack{
	t_list	*first;
	int	last;
	int	size;
}t_stack;


void	ft_atoi(char *str,int *i,t_stack *stack_b);
void	stack_init(t_stack *stack);
void	push(t_stack *stack, long data);
int		pop(t_stack *stack);
void	desplay(t_stack *stack);

void	swap(t_stack *stack, char	x);
void	rotate(t_stack *stack, char x);
void	reverse_rotate(t_stack *stack, char x);
int		rev_pop(t_stack *stack);
void	push_x(t_stack *stack_a, t_stack *stack_b, char x);
void	double_swap(t_stack *stack_a, t_stack *stack_b, char x);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char x);
void	double_rotate(t_stack *stack_a, t_stack *stack_b, char x);

t_stack	*ps_prep(t_stack *stack);
t_stack	*arr_to_stack(t_stack *stack,int *arr);
int 	*do_the_work(t_stack *stack, int *arr, int i, int j);

//test
void	ft_str_int(char *str,t_stack *stack_b);
void	switch_stacks(t_stack *stack_a, t_stack *stack_b);

void	ps_sort3(t_stack *stack);
void	ps_sort4(t_stack *stack_a, t_stack *stack_b);
void	ps_sort5(t_stack *stack_a, t_stack *stack_b);
void	ps_sortUlti(t_stack *stack_a, t_stack *stack_b,int k);
void	ps_sortUltiX2(t_stack *stack_a, t_stack *stack_b,int k);
//bonus
int 	ft_is_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_strncmp(char *s1, char *s2, int n);

void	swap_Bonus(t_stack *stack);
void	rotate_Bonus(t_stack *stack);
void	reverse_rotate_Bonus(t_stack *stack);
int		rev_pop_Bonus(t_stack *stack);
void	push_x_Bonus(t_stack *stack_a, t_stack *stack_b, char x);
void	double_swap_Bonus(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate_Bonus(t_stack *stack_a, t_stack *stack_b);
void	double_rotate_Bonus(t_stack *stack_a, t_stack *stack_b);
//get_next_line

char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_find_next_line(char *stash);
char	*ft_check_line(char *stash);
char	*ft_rest(char *stash);
int		ft_line_size(char *stash);

void	ft_clear(t_stack *stack);
int		ft_error(t_stack *stack_a,t_stack *stack_b);
int		ft_error2(t_stack *stack);
int	ft_is_sort_ckeck(t_stack *stack);

#endif