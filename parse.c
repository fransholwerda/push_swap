/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:59:49 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/30 13:34:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*fill_numbers(int argc, char **argv)
{
	t_numbers	*num;
	int			i;

	i = 1;
	num = NULL;
	while (i < argc)
	{
		if ((!ft_isint(argv[i]) && (argv[i][0] != '-')) || argc < 2)
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		if (i == 1)
			num = lst_new(ft_atoi(argv[i]));
		else
			lst_add_back(num, ft_atoi(argv[i]));
		i++;
	}
	lst_loop(num);
	return (num);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->num = fill_numbers(argc, argv);
	return (stack);
}
