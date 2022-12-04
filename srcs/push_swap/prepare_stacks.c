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

static int	send_highest_back(t_stacks *stacks, t_ftlist_node *curr,
							t_ftlist_node *last)
{
	int64_t	before_last_val;
	int64_t	curr_val;

	curr_val = (int64_t)curr->value;
	if ((curr_val - (int64_t)last->value) > 0
		&& (curr_val - (int64_t)last->value) < 13)
	{
		ft_stacks_execute(stacks, Ins_Rotate_A, 1);
		return (1);
	}
	before_last_val = (int64_t)last->prev->value;
	if (before_last_val < (int64_t)last->value
		&& (curr_val - before_last_val) > 0
		&& (curr_val - before_last_val) < 13)
	{
		ft_stacks_execute(stacks, Ins_Reverse_Rotate_A, 1);
		ft_stacks_execute(stacks, Ins_Swap_A, 1);
		ft_stacks_execute_multiple(stacks, Ins_Rotate_A, 2, 1);
		return (1);
	}
	ft_stacks_execute(stacks, Ins_Push_B, 1);
	return (1);
}

void	prepare_stacks(t_stacks *stacks)
{
	if (stacks->a->size <= 3)
		return ;
	while ((int64_t)stacks->a->last->value > (int64_t)stacks->a->size / 2)
		ft_stacks_execute(stacks, Ins_Reverse_Rotate_A, 1);
	while (!ft_is_roughly_sorted(stacks->a->first))
		if (!send_highest_back(stacks, stacks->a->first, stacks->a->last))
			break ;
}
