/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:13 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/06 18:40:56 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "get_next_line.h"


void	ft_check_cmp(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if(!ft_strncmp(str,"sa\n",3))
		return (swap(stack_a, 'a'));
	if(!ft_strncmp(str,"sb\n",3))
		return (swap(stack_b, 'b'));
	if(!ft_strncmp(str,"ss\n",3))
		return (double_swap(stack_a, stack_b, 'w'));
	if(!ft_strncmp(str,"pa\n",3))
		return (push_x(stack_a, stack_b, 'a'));
	if(!ft_strncmp(str,"pb\n",3))
		return (push_x(stack_a, stack_b, 'b'));
	if(!ft_strncmp(str,"ra\n",3))
		return (rotate(stack_a, 'a'));
	if(!ft_strncmp(str,"rb\n",3))
		return (rotate(stack_b, 'b'));
	if(!ft_strncmp(str,"rra\n",4))
		return (reverse_rotate(stack_a, 'a'));
	if(!ft_strncmp(str,"rrb\n",4))
		return (reverse_rotate(stack_b, 'b'));
	if(!ft_strncmp(str,"rrr\n",4))
		return (double_reverse_rotate(stack_a, stack_b, 'w'));
	if(!ft_strncmp(str,"rr\n",3))
		return (double_rotate(stack_a, stack_b, 'w'));

}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	char *read;

	read = get_next_line(0);
	while(read)
	{
			ft_check_cmp(stack_a, stack_b, read);
			free(read);
			read = get_next_line(0);
	}
}

void switch_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while(stack_b->size > 0)
		push(stack_a,pop(stack_b));
}

int main(int argc, char *argv[])
{
	int i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 1;
	stack_a =  (t_stack *) malloc(sizeof(t_stack));
	stack_init(stack_a);
	stack_b =  (t_stack *) malloc(sizeof(t_stack));
	stack_init(stack_b);
	while(i < argc)
	{
		ft_str_int(argv[i],stack_b);
		i++;
	}
	switch_stacks(stack_a,stack_b);
	stack_a = ps_prep(stack_a);
	ft_sort(stack_a, stack_b);
	if (ft_is_sort(stack_a, stack_b))
		write(1,"OK\n",3);
	else
		write(1,"KO\n",3);
}
