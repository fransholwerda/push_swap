/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:07:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/20 13:35:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/* Replacing the data (number) with the index itself */
static void	replace_data(t_stack *a)
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
static void	index_stack(t_stack *a, int count)
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
	replace_data(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		a = fill_stack(argc, argv);
		check_duplicate(a);
		b = malloc(sizeof(t_stack));
		b->num = NULL;
		if (!b)
			stop("Error\n");
		if (!validate_stack(a))
		{
			index_stack(a, a->num->prev->pos);
			if (a->num->prev->pos <= 4)
				five_sort(a, b);
			else
				radix_sort(a, b);
		}
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
