/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   five_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:59:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/13 12:33:12 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	locate_smallest(t_numbers *num)
{
	int	smallest;
	int	smallest_pos;

	smallest = num->data;
	smallest_pos = num->pos;
	while (num->pos < num->next->pos)
	{
		num = num->next;
		if (num->data < smallest)
		{
			smallest = num->data;
			smallest_pos = num->pos;
		}
	}
	return (smallest_pos);
}

/* It will take out the smallest numbers until 3 remain in stack A */
void	five_sort(t_stack *a, t_stack *b)
{
	while (a->num->prev->pos >= 3)
	{
		while (locate_smallest(a->num) != 0)
		{
			if (locate_smallest(a->num) <= 2)
				rules("ra\n", a, b, 1);
			else
				rules("rra\n", a, b, 1);
		}
		rules("pb\n", a, b, 1);
	}
	if (a->num->prev->pos == 2)
		three_sort(a, b);
	else
		rules("sa\n", a, b, 1);
	while (b->num)
		rules("pa\n", a, b, 1);
}
