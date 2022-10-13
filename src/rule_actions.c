/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rule_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:25:29 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/13 13:26:46 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* Remove a number from stack and and put it in stack b */
void	push(t_stack *a, t_stack *b)
{	
	if (b->num)
	{
		add_top(b->num->data, a);
		rmv_top(b);
	}
}

/* Swapping the top two numbers of a stack with eachother */
void	swap(t_numbers *num)
{
	int	temp;

	if (num)
	{
		temp = num->data;
		num->data = num->next->data;
		num->next->data = temp;
	}
}

/* Moving a number from the top of the stack to the bottom of the stack */
void	rotate(t_numbers *num)
{
	int	temp;
	int	i;
	int	len;

	if (num)
	{
		len = num->prev->pos;
		temp = num->data;
		i = 0;
		while (i < len)
		{
			num->data = num->next->data;
			num = num->next;
			i++;
		}
		num->data = temp;
	}
}

/* Moving a number from the bottom of the stack to the top of the stack */
void	reverse_rotate(t_numbers *num)
{
	int	temp;
	int	i;
	int	len;

	if (num)
	{
		len = num->prev->pos;
		temp = num->data;
		i = 0;
		while (i < len)
		{
			num->data = num->prev->data;
			num = num->prev;
			i++;
		}
		num->data = temp;
	}
}
