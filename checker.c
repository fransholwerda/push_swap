/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:43:52 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/08/05 14:43:45 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_numbers(t_numbers *num)
// {
// 	if (num)
// 	{
// 		while (num->next->pos > num->pos)
// 		{
// 			printf("%d,", num->data);
// 			num = num->next;
// 		}
// 		printf("%d", num->data);
// 	}
// }

// static void	print_stack(t_stack *stack)
// {
// 	printf("[");
// 	print_numbers(stack->num);
// 	printf("]\n");
// }

static void	validate(t_numbers *num)
{
	if (num)
	{
		while (num->next->pos > num->pos)
		{
			if (num->data >= num->next->data)
			{
				write(1, "KO\n", 3);
				return ;
			}
			num = num->next;
		}
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	checker(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		buf[5];

	a = fill_stack(argc, argv);
	b = (t_stack *)malloc(sizeof(t_stack));
	b->num = NULL;
	if (!a || !b)
		return (0);
	ft_bzero(buf, 5);
	while (read(0, buf, 4))
	{
		if (!rules(buf, a, b))
		{
			printf("oops!\n");
			free_stack(&a);
			free_stack(&b);
			return (0);
		}
	}
	validate(a->num);
	free_stack(&a);
	free_stack(&b);
	return (1);
}

int	main(int argc, char **argv)
{
	checker(argc, argv);
	return (0);
}
