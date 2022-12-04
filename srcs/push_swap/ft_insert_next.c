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

static int64_t	find_dest_res(int64_t lowest, int64_t highest,
						t_ftlist *stack, int64_t value)
{
	int64_t	biggest_idx;

	biggest_idx = ft_find_biggest_idx(stack);
	if (biggest_idx == (int64_t)stack->size - 1
		&& value > (int64_t)stack->last->value)
		return (0);
	if (lowest)
		return (ft_find_lowest_idx(stack));
	if (highest)
		return (ft_find_biggest_idx(stack) + 1);
	if (value < (int64_t)stack->last->value)
		return ((int64_t)stack->size - 1);
	return (0);
}

static int64_t	find_dest(t_ftlist *stack, int64_t value)
{
	int					idx;
	int64_t				node_val;
	t_ftlist_node	*node;
	int64_t				lowest;
	int64_t				highest;

	node = stack->first;
	if (!node)
		return (0);
	idx = 0;
	lowest = 1;
	highest = 1;
	while (node->next)
	{
		node_val = (int64_t)node->value;
		if (value > node_val && value < (int64_t)node->next->value)
			return (idx + 1);
		if (value > node_val || value > (int64_t)node->next->value)
			lowest = 0;
		if (value < node_val || value < (int64_t)node->next->value)
			highest = 0;
		node = node->next;
		idx++;
	}
	return (find_dest_res(lowest, highest, stack, value));
}

static void	get_insert_cost(t_push_swap_data *data)
{
	int					idx;
	int					tmp;
	int64_t				value;
	t_ftlist_node	*node;

	node = data->stacks->b->first;
	idx = 0;
	while (node)
	{
		tmp = (idx + 1) / 2 + !(idx % 2);
		value = (int64_t)node->value;
		data->buf[idx] = tmp + find_dest(data->stacks->a, value);
		node = node->next;
		idx++;
	}
}

static int64_t	lowest_cost(const int64_t *costs, size_t len)
{
	size_t	idx;
	int64_t	min_val;
	int64_t	min_idx;

	min_val = costs[0];
	idx = 0;
	min_idx = 0;
	while (++idx < len)
	{
		if (costs[idx] < min_val)
		{
			min_idx = (int64_t)idx;
			min_val = costs[idx];
		}
	}
	return (min_idx);
}

void	ft_insert_next(t_push_swap_data *data)
{
	int64_t	min_idx;
	int64_t	dest_idx;

	get_insert_cost(data);
	min_idx = lowest_cost(data->buf, data->stacks->b->size);
	dest_idx = find_dest(data->stacks->a,
			(int64_t)ft_list_value_at(data->stacks->b, min_idx));
	ft_rotate_common(data->stacks, &dest_idx, &min_idx);
	ft_rotate_by(data->stacks, 0, (size_t)dest_idx);
	ft_rotate_by(data->stacks, 1, (size_t)min_idx);
	ft_stacks_execute(data->stacks, Ins_Push_A, 1);
}
