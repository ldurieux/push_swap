/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:21 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:23 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

static void	rotate_list(t_ftfrwlist *list)
{
	t_ftfrwlist_node	*node;

	if (list->size <= 1)
		return ;
	node = list->first;
	list->last->next = node;
	list->first = node->next;
	list->last = node;
	node->next = NULL;
}

void	ft_stacks_ra(t_stacks *this)
{
	rotate_list(this->a);
}

void	ft_stacks_rb(t_stacks *this)
{
	rotate_list(this->b);
}

void	ft_stacks_rr(t_stacks *this)
{
	rotate_list(this->a);
	rotate_list(this->b);
}
