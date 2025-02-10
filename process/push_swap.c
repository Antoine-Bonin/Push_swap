/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:18:32 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/10 15:05:33 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	sort_min(t_data *data)
{
	if (data->size_a == 2 && data->stack_a[0] > data->stack_a[1])
		sa(data->stack_a);
	else if (data->size_a == 3)
		sort_3(data->stack_a, data->size_a);
	else
		sort_large(data->stack_a, data->stack_b, &data->size_a, &data->size_b);
}

static int	init_data(t_data *data, int ac, char **av)
{
	data->len = count_number(av, ac);
	if (data->len == 0)
	{
		ft_printf("Error\n Expecting numbers");
		return (1);
	}
	data->size_a = data->len;
	data->size_b = 0;
	data->stack_a = ft_calloc(sizeof(int), data->len + 1);
	if (!data->stack_a)
		return (1);
	data->stack_b = ft_calloc(sizeof(int), data->len + 1);
	if (!data->stack_b)
	{
		free(data->stack_a);
		return (1);
	}
	return (0);
}

static int	handle_errors(t_data *data, int ac, char **av)
{
	if (parsing(av, ac, data->stack_a) == 1)
	{
		ft_printf("Error\nParsing\n");
		free(data->stack_a);
		free(data->stack_b);
		return (1);
	}
	if (check_a_is_sorted(data->stack_a, data->size_a) == 1)
	{
		ft_printf("stack_a is sorted\n");
		free(data->stack_a);
		free(data->stack_b);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (init_data(&data, ac, av))
		return (0);
	if (handle_errors(&data, ac, av))
		return (0);
	sort_min(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
