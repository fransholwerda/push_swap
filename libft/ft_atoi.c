/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:46:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/18 14:29:52 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../include/push_swap.h"

static int	of_check(long int value, int minus, int extra)
{
	if ((value * 10 * minus + extra) > INT_MAX)
	{
		stop("Error\n");
		return (-1);
	}
	else if ((value * 10 * minus - extra) < INT_MIN)
	{
		stop("Error\n");
		return (0);
	}
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	long int	value;
	int			minus;
	int			i;

	value = 0;
	minus = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (of_check(value, minus, (nptr[i] - 48)) < 1)
			return (of_check(value, minus, (nptr[i] - 48)));
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	return ((int)(value * minus));
}
