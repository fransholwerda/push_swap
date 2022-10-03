/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:11:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/03 17:43:55 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

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
static void	rules_extended(char *rule, t_stack *a, t_stack *b)
{
	if (ft_strncmp(rule, "ra", 2) == 0 && rule[2] == '\n')
		rotate(a->num);
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
		stop("Error\n");
}

/* Translating the commands into actions */
void	rules(char *rule, t_stack *a, t_stack *b, int print)
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
		push(a, b);
	else if (ft_strncmp(rule, "pb", 2) == 0 && rule[2] == '\n')
		push(b, a);
	else
		rules_extended(rule, a, b);
	if (print == 1)
		write(1, rule, ft_strlen(rule));
}
	