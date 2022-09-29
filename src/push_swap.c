/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:07:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/29 15:42:53 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	stop(char *s)
{
	if (errno == 0)
		write(2, s, ft_strlen(s));
	else
		perror(s);
	exit(EXIT_FAILURE);
}

static void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	atexit(check_leaks);
	if (argc >= 2)
	{
		a = fill_stack(argc, argv);
		b = malloc(sizeof(t_stack));
		if (!b)
			stop("Error\n");
		free_stack(a);
		free_stack(b);
	}
	else
		stop("Error\n");
	return (0);
}
