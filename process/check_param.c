/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:43:17 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/09 18:50:06 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

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
