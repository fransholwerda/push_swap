/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 14:10:49 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/20 13:34:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	minus_checker(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '\0')
		stop("Error\n");
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			stop("Error\n");
		i++;
	}
}

static t_numbers	*multiple_arguments(int argc, char **argv)
{
	t_numbers	*num;
	int			i;

	num = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			minus_checker(argv[i]);
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
	size_t		i;

	num = NULL;
	i = 0;
	while (i < ft_strlen(argv[1]))
	{
		if (argv[1][i] == '-')
			minus_checker(&argv[1][i]);
		if (!(ft_isdigit(argv[1][i]) || argv[1][i] == ' ' || argv[1][i] == '-'))
			stop("Error\n");
		if (ft_isdigit(argv[1][i]) || argv[1][i] == '-')
		{
			if (!num)
				num = lst_new(ft_atoi(&argv[1][i]));
			else
				lst_add_back(num, ft_atoi(&argv[1][i]));
			while (ft_isdigit(argv[1][i]))
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
