/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/30 23:24:09 by antbonin         ###   ########.fr       */
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
			if (ft_isdigit(tab[x][y]) != 0 || (tab[x][y] == '-'
					&& ft_isdigit(tab[x][y + 1]) != 0))
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

int	find_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	process_tab(char **tab, int *stack_a, int index, int *check)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (find_char(tab[j]) == 1)
			return (-1);
		stack_a[index] = ft_atoi(tab[j], check);
		if (*check == -1)
			return (-1);
		index++;
		j++;
	}
	return (index);
}

int	parsing(char **av, int ac, int *stack_a)
{
	int		i;
	int		index;
	int		check;
	char	**tab;

	i = 1;
	index = 0;
	check = 0;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		if (!tab)
			return (1);
		if ((index = process_tab(tab, stack_a, index, &check)) == -1)
		{
			free_tab(tab);
			return (1);
		}
		free_tab(tab);
		i++;
	}
	return (0);
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
	rra(stack_a, size_a);
	ra(stack_a, size_a);
	rb(stack_b, size_b);
	rr(stack_a, stack_b, size_a, size_b);
	rrb(stack_b, size_b);
	rrr(stack_a, stack_b, size_a, size_b);
	sa(stack_a);
	sb(stack_b);
	ss(stack_a, stack_b);
	pa(stack_a, stack_b, &size_a, &size_b);
	pa(stack_a, stack_b, &size_a, &size_b);
	pb(stack_a, stack_b, &size_a, &size_b);
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
