/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:24 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:25 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

static void	swap_list(t_ftlist *list)
{
	t_ftlist_node	*n1;
	t_ftlist_node	*n2;

	n1 = list->first;
	if (!n1)
		return ;
	n2 = n1->next;
	if (!n2)
		return ;
	n1->next = n2->next;
	n2->next = n1;
	list->first = n2;
	if (list->last == n2)
		list->last = n1;
	n1->prev = n2;
	n2->prev = NULL;
	if (n1->next)
		n1->next->prev = n1;
}

void	ft_stacks_sa(t_stacks *this)
{
	swap_list(this->a);
}

void	ft_stacks_sb(t_stacks *this)
{
	swap_list(this->b);
}

void	ft_stacks_ss(t_stacks *this)
{
	swap_list(this->a);
	swap_list(this->b);
}
