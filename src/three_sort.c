/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   three_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:59:20 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/12 17:08:54 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* Checks to sort in this order: 132,213,231,312,321 */
void	three_sort(t_stack *a, t_stack *b)
{
	t_numbers	*num;

	num = a->num;
	if (num->prev->data > num->data && num->prev->data < num->next->data)
	{
		rules("sa\n", a, b, 1);
		rules("ra\n", a, b, 1);
	}
	else if (num->data > num->next->data && num->data < num->prev->data)
		rules("sa\n", a, b, 1);
	else if (num->data < num->next->data && num->data > num->prev->data)
		rules("rra\n", a, b, 1);
	else if (num->prev->data < num->data && num->prev->data > num->next->data)
		rules("ra\n", a, b, 1);
	else if (num->next->data < num->data && num->next->data > num->prev->data)
	{
		rules("sa", a, b, 1);
		rules("rra\n", a, b, 1);
	}
}
