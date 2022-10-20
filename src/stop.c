/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 16:47:12 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/20 13:36:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	stop(char *s)
{
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
