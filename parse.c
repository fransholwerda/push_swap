/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:59:49 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/22 17:00:02 by fholwerd      ########   odam.nl         */
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
		if (!ft_isint(argv[i]) || argc < 2)
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
