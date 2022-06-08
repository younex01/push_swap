/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:01 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/08 17:29:38 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi(char *str,int *i,t_stack *stack_b)
{
	long	resulte;
	int		j;
	int		bool;

	resulte  = 0;
	j = 1;
	bool = 0;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			j *= -1;
		(*i)++;
	}
	while (str[*i] != ' ' && str[*i])
	{
		bool = 1;
		if(str[*i] >= '0' && str[*i] <= '9')
		{
			resulte = resulte * 10 + (str[*i] - '0');
			(*i)++;
		}
		else 
			ft_error2(stack_b);
		if(resulte > 2147483648)
			ft_error2(stack_b);
	}
	if(!bool)
		ft_error2(stack_b);
	push(stack_b, resulte * j);
}




void	ft_str_int(char *str,t_stack *stack_b)
{
	int	i;

	i = 0;
	while (str[i] == ' ' )
		i++;
	if(!str[i])
		ft_error2(stack_b);
	while (str[i])
	{
		ft_atoi(str,&i,stack_b);
		while (str[i] == ' ' )
			i++;
	}
}