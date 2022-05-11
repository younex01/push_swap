#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	i;
	long	j;
	long	resulte;

	resulte = 0;
	i = 0;
	j = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resulte = resulte * 10 + (str[i] - '0');
		i++;
	}
	return (resulte * j);
}
