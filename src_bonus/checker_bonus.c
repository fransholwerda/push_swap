/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:13:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/14 16:48:29 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <get_next_line_bonus.h>

static void	validate(t_numbers *num, t_stack *b)
{
	if (num && !b->num)
	{
		while (num->next->pos > num->pos)
		{
			if (num->data > num->next->data)
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
	char		*buf;

	a = fill_stack(argc, argv);
	b = (t_stack *)malloc(sizeof(t_stack));
	b->num = NULL;
	if (!a || !b)
		return (0);
	while (get_next_line(0, &buf))
	{
		if (!rules(buf, a, b, 0))
		{
			stop("Error\n");
			free_stack(a);
			free_stack(b);
			return (0);
		}
		free(buf);
	}
	validate(a->num, b);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		checker(argc, argv);
	else
		stop("Error\n");
	return (0);
}
