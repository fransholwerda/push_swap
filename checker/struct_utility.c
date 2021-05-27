/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:37:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/27 16:58:52 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_numbers	*lst_new(int data)
{
	t_numbers	*lst;

	lst = (t_numbers *)malloc(sizeof(t_numbers));
	lst->data = data;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	lst_add_back(t_numbers *list, int data)
{
	t_numbers	*new_list;

	while (list->next)
		list = list->next;
	new_list = lst_new(data);
	new_list->prev = list;
	list->next = new_list;
}

void	lst_loop(t_numbers *list)
{
	t_numbers	*list_first;

	list_first = list;
	while (list->next)
		list = list->next;
	list->next = list_first;
	list_first->prev = list;
}
