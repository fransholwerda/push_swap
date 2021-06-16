/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:37:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/30 17:55:26 by fholwerd      ########   odam.nl         */
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

	if (!list)
		list = lst_new(data);
	else
	{
		while (list->next)
			list = list->next;
		new_list = lst_new(data);
		new_list->prev = list;
		list->next = new_list;
	}
}

void	lst_loop(t_numbers *list)
{
	t_numbers	*list_first;

	list_first = list;
	printf("test4\n");
	while (list->next)
	{
		printf("test5\n");
		list = list->next;
		printf("test5.5\n");
	}
	printf("test6\n");
	list->next = list_first;
	list_first->prev = list;
}
