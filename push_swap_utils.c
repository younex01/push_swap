/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:01 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/12 20:19:12 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_loop(char *str, int *i, int *bool, t_stack *stack_b)
{
	long	resulte;

	resulte = 0;
	while (str[*i] != ' ' && str[*i])
	{
		*bool = 1;
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			resulte = resulte * 10 + (str[*i] - '0');
			(*i)++;
		}
		else
			ft_error2(stack_b);
		if (resulte > 2147483648)
			ft_error2(stack_b);
	}
	return (resulte);
}

void	ft_atoi(char *str, int *i, t_stack *stack_b)
{
	long	resulte;
	int		j;
	int		bool;

	j = 1;
	bool = 0;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			j *= -1;
		(*i)++;
	}
	resulte = ft_atoi_loop(str, &(*i), &bool, stack_b);
	if (!bool)
		ft_error2(stack_b);
	push(stack_b, resulte * j);
}

void	ft_str_int(char *str, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (str[i] == ' ' )
		i++;
	if (!str[i])
		ft_error2(stack_b);
	while (str[i])
	{
		ft_atoi(str, &i, stack_b);
		while (str[i] == ' ' )
			i++;
	}
}
