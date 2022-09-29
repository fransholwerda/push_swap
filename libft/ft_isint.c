/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 14:50:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/29 14:50:52 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
