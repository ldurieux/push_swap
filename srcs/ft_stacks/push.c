/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:14 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:16 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

static void	push_list(t_ftlist *from, t_ftlist *to)
{
	t_ftlist_node	*node;

	node = from->first;
	if (!node)
		return ;
	from->first = node->next;
	if (!from->first)
		from->last = NULL;
	else
		from->first->prev = NULL;
	from->size--;
	node->next = to->first;
	if (to->first)
		to->first->prev = node;
	to->first = node;
	if (!to->last)
		to->last = node;
	to->size++;
}

void	ft_stacks_pa(t_stacks *this)
{
	push_list(this->b, this->a);
}

void	ft_stacks_pb(t_stacks *this)
{
	push_list(this->a, this->b);
}
