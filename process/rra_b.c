/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:08:13 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/30 23:14:18 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

void    rra(int *stack_a, int size_a)
{
    int tmp;

    if (size_a <= 1)
        return ;
    tmp = stack_a[size_a - 1];
    ft_memmove(stack_a + 1, stack_a, (size_a - 1) * sizeof(int));
    stack_a[0] = tmp;
    ft_printf("rra\n");
}

void    rrb(int *stack_b, int size_b)
{
    int tmp;

    if (size_b <= 1)
        return ;
    tmp = stack_b[size_b - 1];
    ft_memmove(stack_b + 1, stack_b, (size_b - 1) * sizeof(int));
    stack_b[0] = tmp;
    ft_printf("rrb\n");
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    rra(stack_a, size_a);
    rrb(stack_b, size_b);
}