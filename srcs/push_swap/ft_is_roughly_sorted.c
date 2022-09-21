#include "push_swap.h"

t_bool	ft_is_roughly_sorted(t_stacks *stacks)
{
	int					lowest;
	int					idx;
	t_ftfrwlist_node	*node;

	lowest = ft_find_lowest(stacks->a);
	if (lowest == 0)
		return (ft_stacks_is_sorted(stacks));
	idx = 0;
	node = stacks->a->first;
	while (node->next)
	{
		if (idx == lowest - 1)
		{
			node = node->next;
			idx++;
			continue ;
		}
		if (*(int *)node->value > *(int *)node->next->value)
			return (0);
		node = node->next;
		idx++;
	}
	return (*(int *)node->value < *(int *)stacks->a->first->value);
}
