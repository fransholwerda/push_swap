/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 12:11:53 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/08/26 15:35:16 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a, t_stack *b)
{
	if (a->num->index == )
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	bit_digits;
	int	i;
	int	j;

	size = a->num->prev->pos;
	bit_digits = 0;
	while ((size >> bit_digits) != 0)
		bit_digits++;
	i = 0;
	while (i < bit_digits)
	{
		j = 0;
		while (j <= size)
		{
			if (((a->num->data >> i) & 1) == 1)
			{
				write(1, "ra\n", 3);
				rules("ra\n", a, b);
			}
			else
			{
				write(1, "pb\n", 3);
				rules("pb\n", a, b);
			}
			j++;
		}
		while (b->num)
		{
			write(1, "pa\n", 3);
			rules("pa\n", a, b);
		}
		i++;
	}
}
