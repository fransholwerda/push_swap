/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:52:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/17 19:08:36 by fransholwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	size_t	len;

	len = ft_lstsize(lst);
	while (len > 1)
	{
		lst = lst->next;
		len--;
	}
	return (lst);
}
