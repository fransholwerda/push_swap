/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:04:29 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:20:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!*lst)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}
