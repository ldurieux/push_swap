/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

static void	reverse_rotate_list(t_ftfrwlist *list)
{
	t_ftfrwlist_node	*node;
	t_ftfrwlist_node	*prev;

	if (list->size <= 1)
		return ;
	node = list->last;
	prev = ft_frwlist_node_at(list, list->size - 2);
	list->last = prev;
	prev->next = NULL;
	node->next = list->first;
	list->first = node;
}

void	ft_stacks_rra(t_stacks *this)
{
	reverse_rotate_list(this->a);
}

void	ft_stacks_rrb(t_stacks *this)
{
	reverse_rotate_list(this->b);
}

void	ft_stacks_rrr(t_stacks *this)
{
	reverse_rotate_list(this->a);
	reverse_rotate_list(this->b);
}
