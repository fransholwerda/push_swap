/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:36:42 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/29 16:29:49 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	printf("size: %d\n", size);
	while (i < bit_digits)
	{
		j = 0;
		while (j <= size)
		{
			printf("\ni: %d\nj: %d\n", i, j);
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
