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

t_bool	ft_stacks_is_sorted(t_stacks *this)
{
	int					last;
	int					value;
	t_ftfrwlist_node	*node;

	if (this->b->size > 0)
		return (0);
	node = this->a->first;
	last = *(int *)node->value;
	node = node->next;
	while (node)
	{
		value = *(int *)node->value;
		if (value < last)
			return (0);
		last = value;
		node = node->next;
	}
	return (1);
}
