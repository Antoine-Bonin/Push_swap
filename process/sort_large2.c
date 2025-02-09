/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:47 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/09 18:52:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../source/push_swap.h"

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

