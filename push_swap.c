/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:04:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/22 17:15:10 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_numbers	*num;

	num = fill_numbers(argc, argv);
	if (!num)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	free_list(num);
	return (0);
}
