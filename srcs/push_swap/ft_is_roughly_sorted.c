/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_roughly_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:38:18 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/22 00:38:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t	lowest_idx(t_ftlist_node *node)
{
	int64_t	lowest;
	int64_t	lowest_idx;
	int64_t	idx;

	idx = 0;
	lowest_idx = 0;
	lowest = (int64_t)node->value;
	while (node->next)
	{
		idx++;
		node = node->next;
		if ((int64_t)node->value < lowest)
		{
			lowest = (int64_t)node->value;
			lowest_idx = idx;
		}
	}
	return (lowest_idx);
}

int	ft_is_roughly_sorted(t_ftlist_node *node)
{
	int64_t	first_value;
	int64_t	lowest;
	int64_t	idx;

	first_value = (int64_t)node->value;
	lowest = lowest_idx(node);
	idx = 0;
	while (node->next)
	{
		if (idx == lowest - 1)
		{
			node = node->next;
			idx++;
			continue ;
		}
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		idx++;
	}
	if (lowest == 0)
		return (1);
	return ((int64_t)node->value < first_value);
}
