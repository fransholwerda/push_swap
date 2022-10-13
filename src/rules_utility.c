/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_utility.c.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:14:34 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/13 13:35:27 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	insert(int data, t_stack *stack)
{
	t_numbers	*num;
	int			temp_a;
	int			temp_b;

	lst_unloop(stack->num);
	num = stack->num;
	temp_a = num->data;
	num->data = data;
	while (num->next)
	{
		num = num->next;
		temp_b = num->data;
		num->data = temp_a;
		temp_a = temp_b;
	}
	lst_add_back(stack->num, temp_a);
	lst_loop(stack->num);
}

void	add_top(int data, t_stack *stack)
{
	if (!stack->num)
	{
		stack->num = lst_new(data);
		if (!stack->num)
			stop("Error\n");
		lst_loop(stack->num);
	}
	else
		insert(data, stack);
}

void	rmv_top(t_stack *stack)
{
	t_numbers	*num;
	t_numbers	*last;

	if (stack->num->pos == stack->num->next->pos)
	{
		free(stack->num);
		stack->num = NULL;
	}
	else
	{
		num = stack->num;
		last = num->prev->prev;
		while (num->next->pos > num->pos)
		{
			num->data = num->next->data;
			num = num->next;
		}
		free(num);
		num = NULL;
		stack->num->prev = last;
		last->next = stack->num;
	}
}