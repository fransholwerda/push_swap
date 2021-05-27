/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 16:26:34 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:22:28 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s12;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s12 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s12[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		s12[i + j] = s2[j];
		j++;
	}
	s12[i + j] = '\0';
	return (s12);
}
