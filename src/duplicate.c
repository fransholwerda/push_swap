/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   duplicate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 17:54:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/15 13:15:17 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	is_in_list(t_numbers *list, int number)
{
	t_numbers	*rest_list;

	if (list->pos < list->next->pos)
	{
		rest_list = list->next;
		while (rest_list->pos < rest_list->next->pos)
		{
			if (number == rest_list->data)
				stop("Error\n");
			rest_list = rest_list->next;
		}
		if (number == rest_list->data)
			stop("Error\n");
	}
}

void	check_duplicate(t_stack *a)
{
	t_numbers	*list;

	list = a->num;
	while (list->pos < list->next->pos)
	{
		is_in_list(list, list->data);
		list = list->next;
	}
}
