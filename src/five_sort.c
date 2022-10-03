/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   five_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:59:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/03 17:48:13 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	locate_smallest(t_numbers *num)
{
	int	smallest;
	int	smallest_pos;

	smallest = num->index;
	smallest_pos = num->pos;
	while (num->pos < num->next->pos)
	{
		num = num->next;
		if (num->index < smallest)
		{
			smallest = num->index;
			smallest_pos = num->pos;
		}
	}
	return (smallest_pos);
}

void	five_sort(t_stack *a, t_stack *b)
{
	// if (locate_smallest(a->num) == 0)
	// {
		
	// }
	a = NULL;
	b = NULL;
}
