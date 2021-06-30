/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 13:14:59 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/29 17:05:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_numbers *num)
{
	int	temp;

	if (num->prev->pos <= 1)
		return (-1);
	temp = num->data;
	num->data = num->next->data;
	num->next->data = temp;
	return (0);
}

int	rotate(t_numbers *num)
{
	int	temp;
	int	i;
	int	len;

	len = num->prev->pos;
	if (len <= 1)
		return (-1);
	temp = num->data;
	i = 0;
	while (i < len)
	{
		num->data = num->prev->data;
		num = num->prev;
		i++;
	}
	num->next->data = temp;
	return (0);
}

int	reverse_rotate(t_numbers *num)
{
	int	temp;
	int	i;
	int	len;

	len = num->prev->pos;
	if (len <= 1)
		return (-1);
	temp = num->data;
	i = 0;
	while (i < len)
	{
		num->data = num->next->data;
		num = num->next;
		i++;
	}
	num->prev->data = temp;
	return (0);
}

int	rules(char *rule, t_numbers *a, t_numbers *b)
{
	if (ft_strncmp(rule, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(rule, "pa", 2) == 0)
		add_top(rmv_top(b), a);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		add_top(rmv_top(a), b);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(rule, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(rule, "rra", 2) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(rule, "rrb", 2) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(rule, "rrr", 2) == 0)
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
	else
		return (0);
	return (1);
}
