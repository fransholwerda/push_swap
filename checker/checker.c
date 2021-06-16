/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:43:52 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/30 17:58:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_numbers	*fill_numbers(int argc, char **argv)
{
	t_numbers	*num;
	int			i;
	
	i = 2;
	num = NULL;
	while (i < argc)
	{
		if (!ft_isint(argv[i]) || argc < 2)
		{
			printf("test1\n");
			write(1, "Wrong input, provide numbers.\n", 30);
			return (NULL);
		}
		printf("test2, argv: %s\n", argv[i]);
		lst_add_back(num, ft_atoi(argv[i]));
		i++;
	}
	printf("test3 num: %d\n", num->data);
	lst_loop(num);
	printf("test4\n");
	return (num);
}

int	checker(int argc, char **argv)
{
	t_numbers	*num;
	int			i;

	printf("test0\n");
	num = fill_numbers(argc, argv);
	printf("test\n");
	if (!num)
		return (-1);
	i = 0;
	while (i < argc)
	{
		printf("'%d'\n", num->data);
		num = num->next;
		i++;
	}
	return (0);
}
