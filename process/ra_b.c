/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:41:32 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/30 23:54:49 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

void	ra(int *stack_a, int size_a)
{
	int	tmp;

	if (size_a <= 1)
		return ;
	tmp = stack_a[0];
	ft_memmove(stack_a, stack_a + 1, (size_a - 1) * sizeof(int));
	stack_a[size_a - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(int *stack_b, int size_b)
{
	int	tmp;

	if (size_b <= 1)
		return ;
	tmp = stack_b[0];
	ft_memmove(stack_b, stack_b + 1, (size_b - 1) * sizeof(int));
	stack_b[size_b - 1] = tmp;
	ft_printf("rb\n");
}

void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rb(stack_b, size_b);
	ra(stack_a, size_a);
}
