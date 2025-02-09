/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:45:19 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/09 18:45:16 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

static int	get_max_index(int *stack, int size)
{
	int	i;
	int	max_idx;

	max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

static void	optimize_rotation(int *stack, int *size, int index, int is_stack_a)
{
	if (index <= *size / 2)
	{
		while (index-- > 0)
		{
			if (is_stack_a)
				ra(stack, *size);
			else
				rb(stack, *size);
		}
	}
	else
	{
		while (index++ < *size)
		{
			if (is_stack_a)
				rra(stack, *size);
			else
				rrb(stack, *size);
		}
	}
}

static void	push_to_b_chunks(int *stack_a, int *stack_b, int *size_a,
		int *size_b)
{
	int	chunk_size;
	int	chunk_max;
	int	i;

	chunk_size = get_optimal_chunk_size(*size_a);
	chunk_max = chunk_size;
	while (*size_a > 0)
	{
		i = 0;
		while (i < *size_a)
		{
			if (stack_a[i] <= chunk_max)
			{
				optimize_rotation(stack_a, size_a, i, 1);
				pb(stack_a, stack_b, size_a, size_b);
				if (stack_b[0] < chunk_max - (chunk_size / 2))
					rb(stack_b, *size_b);
				i = -1;
			}
			i++;
		}
		chunk_max += chunk_size;
	}
}

static void	push_back_to_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	max_idx;

	while (*size_b > 0)
	{
		max_idx = get_max_index(stack_b, *size_b);
		optimize_rotation(stack_b, size_b, max_idx, 0);
		pa(stack_a, stack_b, size_a, size_b);
	}
}

void	sort_large(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push_to_b_chunks(stack_a, stack_b, size_a, size_b);
	push_back_to_a(stack_a, stack_b, size_a, size_b);
}
