/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 18:05:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/29 16:29:19 by fholwerd      ########   odam.nl         */
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
	int					pos;
	struct s_numbers	*next;
	struct s_numbers	*prev;
}						t_numbers;

/* Struct utility */
t_numbers	*lst_new(int data);
void		lst_add_back(t_numbers *list, int data);
void		lst_loop(t_numbers *list);
void		free_list(t_numbers **list);
void		lst_unloop(t_numbers *list);
t_numbers	*add_top(int data, t_numbers *list);
int			rmv_top(t_numbers *list);

/* Rules */

int			rules(char *rule, t_numbers *a, t_numbers *b);

/* Parsing */
t_numbers	*fill_numbers(int argc, char **argv);

#endif
