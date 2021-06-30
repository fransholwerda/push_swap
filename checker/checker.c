/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:43:52 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/29 16:50:31 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_numbers(t_numbers *num)
{
	if (num)
	{
		printf("[");
		while (num->next->pos > num->pos)
		{
			printf("%d,", num->data);
			num = num->next;
		}
		printf("%d]\n", num->data);
	}
}

static void	validate(t_numbers *num)
{
	int	i;
	int	len;

	i = 0;
	len = num->prev->pos;
	while (i < len - 1)
	{
		if (num->data >= num->next->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		num = num->next;
		i++;
	}
	write(1, "OK\n", 3);
}

int	checker(int argc, char **argv)
{
	t_numbers	*num_a;
	t_numbers	*num_b;
	int			i;
	char		buf[5];

	num_a = fill_numbers(argc, argv);
	num_b = NULL;
	ft_bzero(buf, 5);
	if (!num_a)
		return (-1);
	print_numbers(num_a);
	validate(num_a);
	read(0, buf, 5);
	rules(buf, num_a, num_b);
	printf("a: ");
	print_numbers(num_a);
	printf("b: ");
	print_numbers(num_b);
	free_list(&num_a);
	free_list(&num_b);
	return (0);
}
