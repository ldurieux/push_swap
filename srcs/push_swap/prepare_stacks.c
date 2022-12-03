/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:18:41 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/03 18:18:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"
#include "push_swap.h"

static int	send_biggest_back(t_stacks *stacks, t_ftfrwlist_node *curr,
							t_ftfrwlist_node **last,
							t_ftfrwlist_node **before_last)
{
	if (((int64_t)curr->value - (int64_t)(*last)->value) > 0
		&& ((int64_t)curr->value - (int64_t)(*last)->value) < 13)
	{
		ft_stacks_execute(stacks, Ins_Rotate_A);
		*before_last = *last;
		*last = stacks->a->last;
		return (1);
	}
	if (*before_last
		&& ((int64_t)curr->value - (int64_t)(*before_last)->value) > 0
		&& ((int64_t)curr->value - (int64_t)(*before_last)->value) < 13)
	{
		ft_stacks_execute(stacks, Ins_Reverse_Rotate_A);
		ft_stacks_execute(stacks, Ins_Swap_A);
		ft_stacks_execute(stacks, Ins_Rotate_A);
		*before_last = stacks->a->last;
		ft_stacks_execute(stacks, Ins_Rotate_A);
		return (1);
	}
	ft_stacks_execute(stacks, Ins_Push_B);
	return (1);
}

void	prepare_stacks(t_stacks *stacks)
{
	t_ftfrwlist_node	*last;
	t_ftfrwlist_node	*before_last;

	if (stacks->a->size <= 3)
		return ;
	last = stacks->a->last;
	while ((int64_t)last->value > (int64_t)stacks->a->size / 2)
	{
		ft_stacks_execute(stacks, Ins_Reverse_Rotate_A);
		last = stacks->a->last;
	}
	before_last = NULL;
	while (!ft_is_roughly_sorted(stacks))
		if (!send_biggest_back(stacks, stacks->a->first, &last, &before_last))
			break ;
}
