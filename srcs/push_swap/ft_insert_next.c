/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_dest_res(t_bool lowest, t_bool highest, t_ftfrwlist *stack,
						int value)
{
	if (lowest)
		return (ft_find_lowest(stack));
	if (highest)
		return (ft_find_biggest(stack) + 1);
	if (value < *(int *)stack->last->value)
		return ((int)stack->size - 1);
	return (0);
}

static int	find_dest(t_ftfrwlist *stack, int value)
{
	int					idx;
	int					node_val;
	t_ftfrwlist_node	*node;
	t_bool				lowest;
	t_bool				highest;

	node = stack->first;
	idx = 0;
	lowest = 1;
	highest = 1;
	while (node->next)
	{
		node_val = *(int *)node->value;
		if (value > node_val && value < *(int *)node->next->value)
			return (idx + 1);
		if (value > node_val || value > *(int *)node->next->value)
			lowest = 0;
		if (value < node_val || value < *(int *)node->next->value)
			highest = 0;
		node = node->next;
		idx++;
	}
	return (find_dest_res(lowest, highest, stack, value));
}

static void	get_insert_cost(t_push_swap_data *data)
{
	int					idx;
	int					value;
	t_ftfrwlist_node	*node;

	node = data->stacks->b->first;
	idx = 0;
	while (node)
	{
		value = *(int *)node->value;
		data->buf[idx] = idx + find_dest(data->stacks->a, value);
		node = node->next;
		idx++;
	}
}

static int	lowest_cost(const int *costs, int len)
{
	int	idx;
	int	min_val;
	int	min_idx;

	min_val = costs[0];
	idx = 0;
	min_idx = 0;
	while (++idx < len)
	{
		if (costs[idx] < min_val)
		{
			min_idx = idx;
			min_val = costs[idx];
		}
	}
	return (min_idx);
}

void	ft_insert_next(t_push_swap_data *data)
{
	int	min_idx;
	int	dest_idx;

	get_insert_cost(data);
	min_idx = lowest_cost(data->buf, (int)data->stacks->b->size);
	dest_idx = find_dest(data->stacks->a,
			*(int *)ft_frwlist_value_at(data->stacks->b, min_idx));
	ft_rotate_common(data->stacks, &dest_idx, &min_idx);
	ft_rotate_by(data->stacks, 0, dest_idx);
	ft_rotate_by(data->stacks, 1, min_idx);
	ft_stacks_execute(data->stacks, Ins_Push_A);
}
