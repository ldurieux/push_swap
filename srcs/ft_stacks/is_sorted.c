/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:08 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

int	ft_stacks_is_sorted(t_stacks *this)
{
	int64_t				last;
	int64_t				value;
	t_ftlist_node	*node;

	if (this->b->size > 0)
		return (0);
	node = this->a->first;
	last = (int64_t)node->value;
	node = node->next;
	while (node)
	{
		value = (int64_t)node->value;
		if (value < last)
			return (0);
		last = value;
		node = node->next;
	}
	return (1);
}
