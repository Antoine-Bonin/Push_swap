/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/31 00:45:47 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ressource/libft.h"
#include "source/push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	check_is_digits(char **tab)
{
	int	x;
	int	y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if ((ft_isdigit(tab[x][y]) != 0 && ft_isdigit(tab[x][y + 1]) != 0)
				|| (tab[x][y] == '-' && ft_isdigit(tab[x][y + 1]) != 0))
				return (0);
			if (ft_isalpha(tab[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	count_number(char **av, int ac)
{
	int		i;
	int		j;
	int		total;
	char	**tab;

	i = 1;
	total = 0;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		if (!tab)
			return (0);
		j = 0;
		if (check_is_digits(tab) != 1)
		{
			ft_printf("Error\nonly digits\n");
			return (free_tab(tab), 0);
		}
		while (tab[j])
			j++;
		total += j;
		free_tab(tab);
		i++;
	}
	return (total);
}

int	main(int ac, char **av)
{
	int	len;
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	i;

	len = count_number(av, ac);
	if (len == 0)
	{
		ft_printf("Error\n Expecting numbers");
		return (0);
	}
	size_a = len;
	size_b = 0;
	/***************************************************/
	stack_a = ft_calloc(sizeof(int), len + 1);
	if (!stack_a)
		return (0);
	stack_b = ft_calloc(sizeof(int), len + 1);
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	/*************************************************/
	if (parsing(av, ac, stack_a) == 1)
	{
		ft_printf("Error\nParsing\n");
		free(stack_a);
		free(stack_b);
		return (0);
	}
	/*******************test************************/
	i = 0;
	ft_printf("before\n");
	while (i < len)
	{
		ft_printf("stack_a = %d stack_b = %d\n", stack_a[i], stack_b[i]);
		i++;
	}
	// rra(stack_a, size_a);
	// ra(stack_a, size_a);
	// rb(stack_b, size_b);
	// rr(stack_a, stack_b, size_a, size_b);
	// rrb(stack_b, size_b);
	// rrr(stack_a, stack_b, size_a, size_b);
	// sa(stack_a);
	// sb(stack_b);
	// ss(stack_a, stack_b);
	// pa(stack_a, stack_b, &size_a, &size_b);
	// pa(stack_a, stack_b, &size_a, &size_b);
	// pb(stack_a, stack_b, &size_a, &size_b);
	// pb(stack_a, stack_b, &size_a, &size_b);
	i = 0;
	ft_printf("after\n");
	while (i < size_b)
	{
		ft_printf("stack_b = %d\n", stack_b[i]);
		i++;
	}
	i = 0;
	ft_printf("\nafter stack a\n");
	while (i < size_a)
	{
		ft_printf("stack_a = %d\n", stack_a[i]);
		i++;
	}
	/**********************************************/
	free(stack_a);
	free(stack_b);
	return (0);
}
