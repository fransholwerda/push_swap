/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:40:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/11 11:41:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static t_list	*fill_lst(t_list **lstf, t_list *lst, void *(*f)(void *))
// {
// 	t_list	*ptr;

// 	*lstf = malloc(sizeof(t_list));
// 	if (!*lstf)
// 		return (NULL);
// 	ptr = *lstf;
// 	while (lst)
// 	{
// 		(*lstf)->content = f(lst->content);
// 		(*lstf)->next = malloc(sizeof(t_list));
// 		if (!(*lstf)->next)
// 			return (NULL);
// 		*lstf = (*lstf)->next;
// 		lst = lst->next;
// 	}
// 	return (ptr);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstf;
	t_list	**lptr;

	lstf = malloc(sizeof(t_list));
	lptr = malloc(sizeof(t_list *));
	*lptr = lstf;
	while (lst)
	{
		lstf->content = f(lst->content);
		if (!lstf->content)
		{
			ft_lstclear(lptr, del);
			free(lptr);
			return (NULL);
		}
		lstf = lstf->next;
		lst = lst->next;
	}
	return (*lptr);
	// if (!lst)
	// 	return (NULL);
	// lstf = malloc(sizeof(t_list *));
	// if (!lstf)
	// 	return (NULL);
	// *lstf = fill_lst(lstf, lst, f);
	// if (!*lstf)
	// {
	// 	ft_lstclear(lstf, del);
	// 	return (NULL);
	// }
	// return (*lstf);
}
