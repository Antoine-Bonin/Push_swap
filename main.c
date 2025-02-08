/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/08 18:42:01 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ressource/libft.h"
#include "source/push_swap.h"
#include <limits.h>
#include <stdlib.h>

/* Prototypes */
void	sort_min(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	sort_3(int *stack_a, int size_a);
void	sort_4(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	sort_5(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	sort_large(int *stack_a, int *stack_b, int *size_a, int *size_b);

/* Variable globale pour compter les opérations */
int			g_op_count = 0;

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
	{
		sa(stack_a);
		g_op_count++;
	}
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a, size_a);
		g_op_count += 2;
	}
	else if (a > b && a > c && b < c)
	{
		ra(stack_a, size_a);
		g_op_count++;
	}
	else if (a < b && a > c)
	{
		rra(stack_a, size_a);
		g_op_count++;
	}
	else if (a < b && a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a, size_a);
		g_op_count += 2;
	}
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

void	sort_4(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	min_idx;

	min_idx = get_min_index(stack_a, *size_a);
	if (min_idx <= *size_a / 2)
		while (min_idx-- > 0)
		{
			ra(stack_a, *size_a);
			g_op_count++;
		}
	else
		while (min_idx++ < *size_a)
		{
			rra(stack_a, *size_a);
			g_op_count++;
		}
	pb(stack_a, stack_b, size_a, size_b);
	g_op_count++;
	sort_3(stack_a, *size_a);
	pa(stack_a, stack_b, size_a, size_b);
	g_op_count++;
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
			while (min_idx-- > 0)
			{
				ra(stack_a, *size_a);
				g_op_count++;
			}
		else
			while (min_idx++ < *size_a)
			{
				rra(stack_a, *size_a);
				g_op_count++;
			}
		pb(stack_a, stack_b, size_a, size_b);
		g_op_count++;
		j++;
	}
	sort_3(stack_a, *size_a);
	while (*size_b > 0)
	{
		pa(stack_a, stack_b, size_a, size_b);
		g_op_count++;
	}
}

static int	get_optimal_chunk_size(int n)
{
    if (n >= 100)
        return (20);  // Pour les grands nombres, chunks plus grands
    if (n >= 50)
        return (10);  // Pour les nombres moyens
    if (n >= 15)
        return (5);   // Pour les petits nombres > 15
    if (n >= 10)
        return (4);   // Pour les nombres entre 10 et 14
    if (n >= 6)
        return (3);   // Pour les nombres entre 6 et 9
    return (n);      // Pour 5 ou moins
}

void	sort_large(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int	chunk_size;
    int	remaining;
    int	elements_pushed;

    chunk_size = get_optimal_chunk_size(*size_a);
    remaining = *size_a;
    elements_pushed = 0;

    while (remaining > 5)  // Garde les 5 derniers pour sort_5
    {
        int current_chunk = (remaining < chunk_size) ? remaining : chunk_size;
        int j = 0;
        
        // Pousse le chunk actuel vers B
        while (j < current_chunk)
        {
            int min_idx = get_min_index(stack_a, *size_a);
            if (min_idx <= *size_a / 2)
                while (min_idx-- > 0)
                {
                    ra(stack_a, *size_a);
                    g_op_count++;
                }
            else
                while (min_idx++ < *size_a)
                {
                    rra(stack_a, *size_a);
                    g_op_count++;
                }
            pb(stack_a, stack_b, size_a, size_b);
            g_op_count++;
            j++;
            elements_pushed++;
        }

        remaining = *size_a;
    }

    // Trie les derniers éléments dans A
    sort_min(stack_a, stack_b, size_a, size_b);

    // Fusionne B dans A
    while (*size_b > 0)
    {
        int max_idx = get_max_index(stack_b, *size_b);
        if (max_idx <= *size_b / 2)
            while (max_idx-- > 0)
            {
                rb(stack_b, *size_b);
                g_op_count++;
            }
        else
            while (max_idx++ < *size_b)
            {
                rrb(stack_b, *size_b);
                g_op_count++;
            }
        pa(stack_a, stack_b, size_a, size_b);
        g_op_count++;
    }
}

void	sort_min(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    if (*size_a == 2 && stack_a[0] > stack_a[1])
        sa(stack_a);
    else if (*size_a == 3)
        sort_3(stack_a, *size_a);
    else if (*size_a == 4)
        sort_4(stack_a, stack_b, size_a, size_b);
    else if (*size_a == 5)
        sort_5(stack_a, stack_b, size_a, size_b);
    else if (*size_a > 5)
        sort_large(stack_a, stack_b, size_a, size_b);
}

int	main(int ac, char **av)
{
	int	len;
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	// int	i;
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
	if (check_a_is_sorted(stack_a, size_a) == 1)
	{
		ft_printf("stack_a is sorted\n");
		free(stack_a);
		free(stack_b);
		return (0);
	}
	/*******************test************************/
	// int i = 0;
	int div = size_a / 2; // ce que je dois envoyer dans stack_b
	ft_printf("div = %d\n", div);
	ft_printf("multiple de : %d\n", get_optimal_chunk_size(div));
		// le sort que je devrais utiliser
	sort_min(stack_a, stack_b, &size_a, &size_b);
    ft_printf("\nNombre total d'opérations : %d\n", g_op_count);
	// ft_printf("after\n");
	// while (i < size_b)
	// {
	// 	ft_printf("stack_b = %d\n", stack_b[i]);
	// 	i++;
	// }
	// i = 0;
	// ft_printf("\nafter stack a\n");
	// while (i < size_a)
	// {
	// 	ft_printf("stack_a = %d\n", stack_a[i]);
	// 	i++;
	// }
	/**********************************************/
	free(stack_a);
	free(stack_b);
	return (0);
}
