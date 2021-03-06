/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 13:14:59 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/08/05 14:39:04 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* Extension of the function below, 25 line limit is not enough */
static int	rules_extended(char *rule, t_stack *a, t_stack *b)
{
	if (ft_strncmp(rule, "ra", 2) == 0 && rule[2] == '\n')
	{
		rotate(a->num);
	}
	else if (ft_strncmp(rule, "rb", 2) == 0 && rule[2] == '\n')
		rotate(b->num);
	else if (ft_strncmp(rule, "rr", 2) == 0 && rule[2] == '\n')
	{
		rotate(a->num);
		rotate(b->num);
	}
	else if (ft_strncmp(rule, "rra", 3) == 0 && rule[3] == '\n')
		reverse_rotate(a->num);
	else if (ft_strncmp(rule, "rrb", 3) == 0 && rule[3] == '\n')
		reverse_rotate(b->num);
	else if (ft_strncmp(rule, "rrr", 3) == 0 && rule[3] == '\n')
	{
		reverse_rotate(a->num);
		reverse_rotate(b->num);
	}
	else
		return (0);
	return (1);
}

/* Translating the commands into actions */
int	rules(char *rule, t_stack *a, t_stack *b)
{
	if (ft_strncmp(rule, "sa", 2) == 0 && rule[2] == '\n')
		swap(a->num);
	else if (ft_strncmp(rule, "sb", 2) == 0 && rule[2] == '\n')
		swap(b->num);
	else if (ft_strncmp(rule, "ss", 2) == 0 && rule[2] == '\n')
	{
		swap(a->num);
		swap(b->num);
	}
	else if (ft_strncmp(rule, "pa", 2) == 0 && rule[2] == '\n')
	{
		if (push(a, b))
			return (1);
	}
	else if (ft_strncmp(rule, "pb", 2) == 0 && rule[2] == '\n')
	{
		if (push(b, a))
			return (1);
	}
	else
		return (rules_extended(rule, a, b));
	return (1);
}
