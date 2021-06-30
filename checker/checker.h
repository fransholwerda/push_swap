/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 18:18:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/06/29 15:52:59 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

/* Checker */
int	checker(int argc, char **argv);

/* Game rules */
int	swap(t_numbers *num);
int	push(t_numbers *num_s, t_numbers *num_d);
int	rotate(t_numbers *num);
int	reverse_rotate(t_numbers *num);

#endif
