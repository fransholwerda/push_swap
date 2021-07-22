/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:04:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/07/22 14:51:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_numbers(t_numbers *num)
{
	if (num)
	{
		while (num->next->pos > num->pos)
		{
			printf("%d,", num->index);
			num = num->next;
		}
		printf("%d", num->index);
	}
}

static void	print_stack(t_stack *stack)
{
	printf("[");
	print_numbers(stack->num);
	printf("]\n");
}

/* Assigns a postive index to each number in the list,
the lowest number becomes 0, second lowest becomes 1, etc. */
void	index_stack(t_stack *a, int count)
{
	t_numbers	*num;
	t_numbers	*temp;
	int			i;

	i = 0;
	while (i < count)
	{
		num = a->num;
		while (num->index != -1 && num->pos < num->next->pos)
			num = num->next;
		temp = num;
		while (num->pos < num->next->pos)
		{
			if (temp->data > num->data && num->index == -1)
				temp = num;
			num = num->next;
		}
		if (temp->data > num->data && num->index == -1)
			temp = num;
		temp->index = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(argc, argv);
	b = (t_stack *)malloc(sizeof(t_stack));
	b->num = NULL;
	if (!a || !b)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	index_stack(a, argc - 1);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
