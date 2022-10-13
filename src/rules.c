/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 15:11:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/13 15:12:46 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/* Checks if the rule sent valid */
static int	check_if_valid_rule(char *rule)
{
	if (ft_strncmp(rule, "sa", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "sb", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "ss", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "pa", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "pb", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "ra", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "rb", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "rr", 2) == 0 && rule[2] == '\n')
		return (1);
	if (ft_strncmp(rule, "rra", 3) == 0 && rule[3] == '\n')
		return (1);
	if (ft_strncmp(rule, "rrb", 3) == 0 && rule[3] == '\n')
		return (1);
	if (ft_strncmp(rule, "rrr", 3) == 0 && rule[3] == '\n')
		return (1);
	return (0);
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

/* Translating the commands into actions. */
/* Returns 0/1 depending on rule validity intended for the checker program */
int	rules(char *rule, t_stack *a, t_stack *b, int print)
{
	if (!check_if_valid_rule(rule))
		return (0);
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
	return (1);
}
