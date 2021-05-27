/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:25:28 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/17 19:08:29 by fransholwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;

	temp = lst;
	if (lst)
	{
		lst = lst->next;
		del(temp->content);
		free(temp);
	}
}
