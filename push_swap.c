/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 16:04:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/08/04 14:09:20 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_numbers(t_numbers *num)
{
	if (num)
	{
		while (num->next->pos > num->pos)
		{
			printf("%d,", num->data);
			num = num->next;
		}
		printf("%d", num->data);
	}
}

static void	print_stack(t_stack *stack)
{
	printf("[");
	print_numbers(stack->num);
	printf("]\n");
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	bit_digits;
	int	i;
	int	j;

	size = a->num->prev->pos;
	bit_digits = 0;
	while ((size >> bit_digits) != 0)
		bit_digits++;
	i = 0;
	while (i < bit_digits)
	{
		j = 0;
		while (j <= size)
		{
			if (((a->num->data >> i) & 1) == 1)
			{
				write(1, "ra\n", 3);
				rules("ra\n", a, b);
			}
			else
			{
				write(1, "pb\n", 3);
				rules("pb\n", a, b);
			}
			j++;
		}
		while (b->num)
		{
			write(1, "pa\n", 3);
			rules("pa\n", a, b);
		}
		i++;
	}
}

void	replace_data(t_stack *a, int count)
{
	t_numbers	*num;

	num = a->num;
	while (num->pos < num->next->pos)
	{
		num->data = num->index;
		num = num->next;
	}
	num->data = num->index;
}

/* Assigns a postive index to each number in the list,
the lowest number becomes 0, second lowest becomes 1, etc. */
void	index_stack(t_stack *a, int count)
{
	t_numbers	*num;
	t_numbers	*temp;
	int			i;

	i = 0;
	while (i <= count)
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
	replace_data(a, count);
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
	//print_stack(a);
	index_stack(a, a->num->prev->pos);
	//print_stack(a);
	radix_sort(a, b);
	// printf("a: ");
	// print_stack(a);
	// printf("b: ");
	// print_stack(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
