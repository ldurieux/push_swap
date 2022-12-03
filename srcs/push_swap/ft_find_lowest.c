/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	ft_find_lowest(t_ftfrwlist *stack)
{
	t_ftfrwlist_node	*node;
	int64_t				min_val;
	int64_t				min_idx;
	int64_t				idx;
	int64_t				value;

	node = stack->first;
	min_val = (int64_t)node->value;
	min_idx = 0;
	idx = 1;
	node = node->next;
	while (node)
	{
		value = (int64_t)node->value;
		if (value < min_val)
		{
			min_val = value;
			min_idx = idx;
		}
		node = node->next;
		idx++;
	}
	return (min_idx);
}

int64_t	ft_find_biggest(t_ftfrwlist *stack)
{
	t_ftfrwlist_node	*node;
	int64_t				max_val;
	int64_t				max_idx;
	int64_t				idx;
	int64_t				value;

	node = stack->first;
	max_val = (int64_t)node->value;
	max_idx = 0;
	idx = 1;
	node = node->next;
	while (node)
	{
		value = (int64_t)node->value;
		if (value > max_val)
		{
			max_val = value;
			max_idx = idx;
		}
		node = node->next;
		idx++;
	}
	return (max_idx);
}
