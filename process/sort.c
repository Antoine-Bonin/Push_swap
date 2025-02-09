/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:43:24 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/09 16:49:52 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

int	check_a_is_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	get_min_index(int *stack, int size)
{
	int	i;
	int	min_idx;

	min_idx = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] < stack[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

void	sort_3(int *stack_a, int size_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a[0];
	b = stack_a[1];
	c = stack_a[2];
	if (a < b && b < c)
		return ;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a, size_a);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a, size_a);
	else if (a < b && a > c)
		rra(stack_a, size_a);
	else if (a < b && a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a, size_a);
	}
}

void	sort_4(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	min_idx;

	min_idx = get_min_index(stack_a, *size_a);
	if (min_idx <= *size_a / 2)
		while (min_idx-- > 0)
			ra(stack_a, *size_a);
	else
		while (min_idx++ < *size_a)
			rra(stack_a, *size_a);
	pb(stack_a, stack_b, size_a, size_b);
	sort_3(stack_a, *size_a);
	pa(stack_a, stack_b, size_a, size_b);
}

void	sort_5(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	j;
	int	min_idx;

	j = 0;
	while (j < 2)
	{
		min_idx = get_min_index(stack_a, *size_a);
		if (min_idx <= *size_a / 2)
		{
			while (min_idx-- > 0)
				ra(stack_a, *size_a);
		}
		else
		{
			while (min_idx++ < *size_a)
				rra(stack_a, *size_a);
		}
		pb(stack_a, stack_b, size_a, size_b);
		j++;
	}
	sort_3(stack_a, *size_a);
	while (*size_b > 0)
	{
		pa(stack_a, stack_b, size_a, size_b);
	}
}
