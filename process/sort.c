/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:43:24 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/10 15:01:30 by antbonin         ###   ########.fr       */
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

int	get_optimal_chunk_size(int n)
{
	if (n >= 500)
		return (n / 9);
	if (n >= 100)
		return (n / 5);
	if (n >= 50)
		return (n / 3);
	return (n / 5);
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
