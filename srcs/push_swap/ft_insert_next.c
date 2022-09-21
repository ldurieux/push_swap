#include "push_swap.h"

static int	find_dest(t_ftfrwlist *stack, int value)
{
	int					idx;
	int					node_val;
	t_ftfrwlist_node	*node;
	t_bool				lowest;

	node = stack->first;
	idx = 0;
	lowest = 1;
	while (node->next)
	{
		node_val = *(int *)node->value;
		if (value > node_val && value < *(int *)node->next->value)
			return (idx + 1);
		if (value > node_val || value > *(int *)node->next->value)
			lowest = 0;
		node = node->next;
		idx++;
	}
	if (lowest)
		return (ft_find_lowest(stack));
	if (value < *(int *)node->value)
		return (idx);
	return (0);
}

static t_bool	get_insert_cost(t_push_swap_data *data)
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
	return (1);
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

//TODO: handle error
void	ft_insert_next(t_push_swap_data *data)
{
	int	min_idx;
	int dest_idx;

	if (!get_insert_cost(data))
		return ;
	min_idx = lowest_cost(data->buf, (int)data->stacks->b->size);
	dest_idx = find_dest(data->stacks->a,
		*(int *)ft_frwlist_value_at(data->stacks->b, min_idx));
	ft_rotate_by(data->stacks, 0, dest_idx);
	ft_rotate_by(data->stacks, 1, min_idx);
	ft_stacks_execute(data->stacks, Ins_Push_A);
}
