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

int	ft_find_lowest(t_ftfrwlist *stack)
{
	t_ftfrwlist_node	*node;
	int					min_val;
	int					min_idx;
	int					idx;
	int					value;

	node = stack->first;
	min_val = *(int *)node->value;
	min_idx = 0;
	idx = 1;
	node = node->next;
	while (node)
	{
		value = *(int *)node->value;
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
