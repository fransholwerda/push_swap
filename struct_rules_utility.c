/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_rules_utility.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 13:29:26 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/30 15:58:45 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_top(int data, t_stack *stack)
{
	t_numbers	*num;
	int			temp_a;
	int			temp_b;

	if (!stack->num)
	{
		stack->num = lst_new(data);
		if (!stack->num)
			return (0);
		lst_loop(stack->num);
	}
	else
	{
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
	return (1);
}

static void	rmv_top(t_stack *stack)
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

int	push(t_stack *a, t_stack *b)
{	
	if (b->num)
	{
		if (!add_top(b->num->data, a))
			return (0);
		rmv_top(b);
	}
	return (1);
}
