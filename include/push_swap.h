/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:57:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/28 16:57:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>





# include <stdio.h> //delete this later
# include <string.h> //delete this later

typedef struct s_numbers
{
	int					data;
	int					pos;
	int					index;
	struct s_numbers	*next;
	struct s_numbers	*prev;
}						t_numbers;

typedef struct s_stack
{
	t_numbers			*num;
}						t_stack;

typedef struct s_instructions
{
	char					*data;
	struct s_instructions	*next;
}							t_instructions;

/* Struct utility */
t_numbers	*lst_new(int data);
void		lst_add_back(t_numbers *list, int data);
void		free_list(t_numbers **list);
void		free_stack(t_stack **stack);
void		lst_loop(t_numbers *list);
void		lst_unloop(t_numbers *list);

/* Checker */
int			checker(int argc, char **argv);

/* Rules */
void		swap(t_numbers *num);
int			push(t_stack *a, t_stack *b);
void		rotate(t_numbers *num);
void		reverse_rotate(t_numbers *num);
int			rules(char *rule, t_stack *a, t_stack *b);

/* Parsing */
t_numbers	*fill_numbers(int argc, char **argv);
t_stack		*fill_stack(int argc, char **argv);
int			validate_stack(t_stack *stack);

#endif