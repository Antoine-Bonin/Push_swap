/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:42:52 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/31 00:40:09 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ressource/libft.h"

/****************************process******************************/

void	sb(int *stack_b);
void	sa(int *stack_a);
void	ss(int *sta, int *stb);
void	ra(int *stack_a, int size_a);
void	rb(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rrb(int *stack_b, int size_b);
void	rra(int *stack_a, int size_a);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);
void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);

/*****************************************************************/

int		parsing(char **av, int ac, int *stack_a);

#endif