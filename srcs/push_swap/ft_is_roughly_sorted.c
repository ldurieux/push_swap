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

int	ft_is_roughly_sorted(t_stacks *stacks)
{
	int64_t				lowest;
	int64_t				idx;
	t_ftfrwlist_node	*node;

	if (stacks->a->size < 3)
		return (1);
	lowest = ft_find_lowest(stacks->a);
	idx = 0;
	node = stacks->a->first;
	while (node->next)
	{
		if (idx == lowest - 1)
		{
			node = node->next;
			idx++;
			continue ;
		}
		if ((int64_t)node->value > (int64_t)node->next->value)
			return (0);
		node = node->next;
		idx++;
	}
	if (lowest == 0)
		return (1);
	return ((int64_t)node->value < (int64_t)stacks->a->first->value);
}
