/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:59:40 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/29 15:56:02 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_numbers	*lst_new(int data)
{
	t_numbers	*lst;

	lst = (t_numbers *)malloc(sizeof(t_numbers));
	if (!lst)
		stop("Error\n");
	lst->data = data;
	lst->pos = 0;
	lst->index = -1;
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

void	free_stack(t_stack *stack)
{
	t_numbers	*next;
	t_numbers	*temp;

	if (stack)
	{
		if (stack->num)
		{
			next = stack->num->next;
			while (next && (next != stack->num))
			{
				temp = next;
				next = next->next;
				free(temp);
			}
			free(stack->num);
			stack->num = NULL;
		}
		free(stack);
		stack = NULL;
	}
}

/* Connecting the first and last entries of the list with eachother, 
making it circular */
void	lst_loop(t_numbers *list)
{
	t_numbers	*list_first;

	if (!list)
		return ;
	list_first = list;
	while (list->next && list->next->pos > list->pos)
		list = list->next;
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
