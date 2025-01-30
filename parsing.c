/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:38:14 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/31 00:45:41 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ressource/libft.h"
#include "source/push_swap.h"

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

int	check_double(int *stack_a, int total_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < total_size)
	{
		j = i + 1;
		while (j < total_size)
		{
			if (stack_a[i] == stack_a[j])
			{
				ft_printf("Error\n%d appear multiple times\n", stack_a[i]);
				return (1);
			}
			j++;
		}
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
	if (check_double(stack_a, index))
		return (-1);
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
		index = process_tab(tab, stack_a, index, &check);
		if (index == -1)
		{
			free_tab(tab);
			return (1);
		}
		free_tab(tab);
		i++;
	}
	return (0);
}
