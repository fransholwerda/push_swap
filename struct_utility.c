/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:37:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/22 17:14:28 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*lst_new(int data)
{
	t_numbers	*lst;

	lst = (t_numbers *)malloc(sizeof(t_numbers));
	lst->data = data;
	lst->pos = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	lst_add_back(t_numbers *list, int data)
{
	t_numbers	*new_list;

	if (!list)
		list = lst_new(data);
	else
	{
		while (list->next)
			list = list->next;
		new_list = lst_new(data);
		new_list->prev = list;
		new_list->pos = list->pos + 1;
		list->next = new_list;
	}
}

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

void	free_list(t_numbers *list)
{
	while (list->next)
	{
		list = list->next;
		free (list->prev);
	}
	free(list);
}
