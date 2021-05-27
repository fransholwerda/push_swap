/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:43:52 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/27 18:02:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_numbers	*fill_numbers(int argc, char **argv)
{
	t_numbers	*num;
	int			i;
	
	if (argc > 1)
		num = lst_new(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		lst_add_back(num, ft_atoi(argv[i]));
		i++;
	}
	lst_loop(num);
	return (num);
}

int	checker(int argc, char **argv)
{
	t_numbers	*num;
	int			i;

	num = fill_numbers(argc, argv);
	if (!num)
		return (-1);
	i = 0;
	while (i < 9)
	{
		printf("'%d'\n", num->data);
		num = num->next;
		i++;
	}
	return (0);
}
