/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:47 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:48 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_idx(t_ftfrwlist *stack)
{
	int					max_idx;
	int					max_val;
	int					cur_idx;
	int					val;
	t_ftfrwlist_node	*node;

	max_idx = 0;
	max_val = *(int *)stack->first->value;
	node = stack->first->next;
	cur_idx = 1;
	while (node)
	{
		val = *(int *)node->value;
		if (val > max_val)
		{
			max_idx = cur_idx;
			max_val = val;
		}
		cur_idx++;
		node = node->next;
	}
	return (max_idx);
}

static int	lowest_idx(t_ftfrwlist *stack)
{
	int					min_idx;
	int					min_val;
	int					cur_idx;
	int					val;
	t_ftfrwlist_node	*node;

	min_idx = 0;
	min_val = *(int *)stack->first->value;
	node = stack->first->next;
	cur_idx = 1;
	while (node)
	{
		val = *(int *)node->value;
		if (val < min_val)
		{
			min_idx = cur_idx;
			min_val = val;
		}
		cur_idx++;
		node = node->next;
	}
	return (min_idx);
}

void	ft_sort_3(t_stacks *stacks)
{
	t_ftfrwlist	*stack;

	stack = stacks->a;
	if (stack->size != 3)
		return ;
	if (highest_idx(stack) == 0)
		ft_stacks_execute(stacks, Ins_Rotate_A);
	else if (highest_idx(stack) == 1)
		ft_stacks_execute(stacks, Ins_Reverse_Rotate_A);
	if (lowest_idx(stack) == 1)
		ft_stacks_execute(stacks, Ins_Swap_A);
}
