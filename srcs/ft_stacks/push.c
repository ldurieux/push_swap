#include "ft_stacks.h"

static void	push_list(t_ftfrwlist *from, t_ftfrwlist *to)
{
	t_ftfrwlist_node	*node;

	node = from->first;
	if (!node)
		return ;
	from->first = node->next;
	if (!from->first)
		from->last = NULL;
	from->size--;
	node->next = to->first;
	to->first = node;
	if (!to->last)
		to->last = node;
	to->size++;
}

void		ft_stacks_pa(t_stacks *this)
{
	push_list(this->b, this->a);
}

void		ft_stacks_pb(t_stacks *this)
{
	push_list(this->a, this->b);
}
