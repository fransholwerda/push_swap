/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:13:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/13 17:44:08 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	stop(char *s)
{
	if (errno == 0)
		write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

static void	validate(t_numbers *num, t_stack *b)
{
	if (num && !b->num)
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
		if (!rules(buf, a, b, 0))
		{
			write(1, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			return (0);
		}
	}
	validate(a->num, b);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	checker(argc, argv);
	return (0);
}
