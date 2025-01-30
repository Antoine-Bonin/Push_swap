/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:48:44 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/30 21:49:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"
#include "../libft/ressource/libft.h"

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	tmp;

	if (*size_b == 0)
		return ;
	tmp = stack_b[0];
	ft_memmove(stack_a + 1, stack_a, (*size_a) * sizeof(int));
	stack_a[0] = tmp;
	ft_memmove(stack_b, stack_b + 1, (*size_b - 1) * sizeof(int));
	(*size_a)++;
	(*size_b)--;
	ft_printf("pa\n");
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	tmp;

	if (*size_a == 0)
		return ;
	tmp = stack_a[0];
	ft_memmove(stack_b + 1, stack_b, (*size_b) * sizeof(int));
	stack_b[0] = tmp;
	ft_memmove(stack_a, stack_a + 1, (*size_a - 1) * sizeof(int));
	(*size_b)++;
	(*size_a)--;
	ft_printf("pb\n");
}
