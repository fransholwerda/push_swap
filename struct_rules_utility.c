/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_rules_utility.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 13:29:26 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/29 16:38:25 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_unloop(t_numbers *list)
{
	t_numbers	*last;

	if (list->prev)
	{
		last = list->prev;
		list->prev = NULL;
		last->next = NULL;
	}
}

t_numbers	*add_top(int data, t_numbers *list)
{
	t_numbers	*first;
	int			temp_a;
	int			temp_b;

	if (!list)
	{
		list = lst_new(data);
		lst_loop(list);
		return (list);
	}
	lst_unloop(list);
	first = list;
	temp_a = list->data;
	list->data = data;
	while(list->next)
	{
		list = list->next;
		temp_b = list->data;
		list->data = temp_a;
		temp_a = temp_b;
	}
	lst_add_back(list, temp_a);
	lst_loop(first);
	return	(first);
}

int	rmv_top(t_numbers *list)
{
	t_numbers	*first;
	t_numbers	*last;
	int			data;

	if (!list->next)
	{
		data = list->data;
		free(list);
	}
	else
	{
		data = list->data;
		first = list;
		last = list->prev->prev;
		while (list->next->pos > list->pos)
		{
			list->data = list->next->data;
			list = list->next;
		}
		free(list);
		first->prev = last;
		last->next = first;
	}
	return (data);
}
