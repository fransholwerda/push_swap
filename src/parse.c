/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 14:10:49 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/29 15:06:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static t_numbers	*multiple_arguments(int argc, char **argv)
{
	t_numbers	*num;
	int			i;

	num = NULL;
	i = 1;
	while (i < argc)
	{
		if ((!ft_isint(argv[i]) && (argv[i][0] != '-')) || argc < 2)
			stop("Error\n");
		if (!num)
			num = lst_new(ft_atoi(argv[i]));
		else
			lst_add_back(num, ft_atoi(argv[i]));
		i++;
	}
	return (num);
}

static t_numbers	*single_argument(char **argv)
{
	t_numbers	*num;
	int			i;

	num = NULL;
	i = 0;
	while (ft_isdigit(argv[1][i]) || argv[1][i] == ' ' || argv[1][i] == '-')
	{
		if (ft_isdigit(argv[1][i]) || argv[1][i] == '-')
		{
			if (!num)
				num = lst_new(ft_atoi(&argv[1][i]));
			else
				lst_add_back(num, ft_atoi(&argv[1][i]));
			if (argv[1][i] == '-' && !ft_isdigit(argv[1][i + 1]))
				stop("Error\n");
			while (ft_isdigit(argv[1][i]) || argv[1][i] == '-')
				i++;
		}
		i++;
	}
	return (num);
}

t_numbers	*fill_numbers(int argc, char **argv)
{
	t_numbers	*num;

	num = NULL;
	if (argc > 2 || (argc == 2 && ft_isint(argv[1])))
		num = multiple_arguments(argc, argv);
	else
		num = single_argument(argv);
	lst_loop(num);
	return (num);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		stop("Error\n");
	stack->num = fill_numbers(argc, argv);
	return (stack);
}

int	validate_stack(t_stack *stack)
{
	t_numbers	*num;

	if (stack)
	{
		num = stack->num;
		if (num)
		{
			while (num->next->pos > num->pos)
			{
				if (num->data >= num->next->data)
					return (0);
				num = num->next;
			}
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}
