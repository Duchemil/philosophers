/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:54 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/16 14:30:03 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while ((str[i]) >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

int	ft_int(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (str[i])
	{
		if ((str[0]) == '-' && neg == 0)
		{
			neg = 1;
			i++;
		}
		if ((str[i]) >= '0' && str[i] <= '9')
			i++;
		else
			return (write(2, "Error, an argument isn't an int\n", 33), 1);
	}
	return (0);
}
