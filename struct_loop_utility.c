/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_loop_utility.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 14:58:05 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/08/05 11:31:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Connecting the first and last entries of the list with eachother, 
making it circular */
void	lst_loop(t_numbers *list)
{
	t_numbers	*list_first;

	if (!list)
		return ;
	list_first = list;
	while (list->next)
	{
		list = list->next;
	}
	list->next = list_first;
	list_first->prev = list;
}

/* Unlinking the first and last entry of the list from eachother */
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
