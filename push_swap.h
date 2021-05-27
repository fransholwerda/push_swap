/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 18:05:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/27 18:06:48 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h> //delete this later
# include <string.h> //delete this later
# include "libft/libft.h"

typedef struct s_numbers
{
	int					data;
	struct s_numbers	*next;
	struct s_numbers	*prev;
}						t_numbers;

#endif
