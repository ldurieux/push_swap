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


static void	reverse_rotate_list(t_ftlist *list)
{
	t_ftlist_node	*node;
	t_ftlist_node	*prev;

	if (list->size <= 1)
		return ;
	node = list->last;
	node->next = list->first;
	list->first->prev = node;
	prev = node->prev;
	prev->next = NULL;
	node->prev = NULL;
	list->first = node;
	list->last = prev;
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
