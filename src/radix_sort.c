/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:36:42 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/03 17:48:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	small_sort(t_stack *a, t_stack *b)
{
	a = NULL;
	b = NULL;
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
				rules("ra\n", a, b, 1);
			else
				rules("pb\n", a, b, 1);
			j++;
		}
		while (b->num)
			rules("pa\n", a, b, 1);
		i++;
	}
}
