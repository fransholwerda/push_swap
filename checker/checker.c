/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:43:52 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/22 17:16:33 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_numbers(int argc, t_numbers *num)
{
	int	i;

	i = 1;
	printf("[");
	while (i < argc)
	{
		printf("%d", num->data);
		if ((argc - i) > 1)
			printf(",");
		num = num->next;
		i++;
	}
	printf("]\n");
}

int	swap(int len, t_numbers *num)
{
	int	temp;

	if (len <= 1)
		return (-1);
	temp = num->data;
	num->data = num->next->data;
	num->next->data = temp;
	return (0);
}

int	rotate(int len, t_numbers *num)
{
	int	temp;
	int	i;

	if (len <= 1)
		return (-1);
	temp = num->data;
	i = 0;
	while (i < len)
	{
		num->data = num->prev->data;
		num = num->prev;
		i++;
	}
	num->next->data = temp;
	return (0);
}

int	reverse_rotate(int len, t_numbers *num)
{
	int	temp;
	int	i;

	if (len <= 1)
		return (-1);
	temp = num->data;
	i = 0;
	while (i < len)
	{
		num->data = num->next->data;
		num = num->next;
		i++;
	}
	num->prev->data = temp;
	return (0);
}

static void	validate(int len, t_numbers *num)
{
	int	i;

	i = 0;
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
	t_numbers	*num;
	int			i;
	char		buf[5];

	num = fill_numbers(argc, argv);
	if (!num)
		return (-1);
	print_numbers(argc, num);
	validate(argc - 1, num);
	rotate(argc - 1, num);
	print_numbers(argc, num);
	validate(argc - 1, num);
	// read(0, buf, 5);
	// buf[4] = '\0';
	// printf("%s", buf);
	free_list(num);
	return (0);
}
