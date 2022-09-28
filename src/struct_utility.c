/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:59:40 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/28 17:00:12 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_numbers	*lst_new(int data)
{
	t_numbers	*lst;

	lst = (t_numbers *)malloc(sizeof(t_numbers));
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

void	free_stack(t_stack **stack)
{
	t_numbers	*next;
	t_numbers	*temp;

	if (stack && *stack)
	{
		if ((*stack)->num)
		{
			next = (*stack)->num->next;
			while (next && (next != (*stack)->num))
			{
				temp = next;
				next = next->next;
				free(temp);
			}
			free((*stack)->num);
			(*stack)->num = NULL;
		}
		free(*stack);
		*stack = NULL;
	}
}
