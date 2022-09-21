#include "ft_stacks.h"

static void	swap_list(t_ftfrwlist *list)
{
	t_ftfrwlist_node	*n1;
	t_ftfrwlist_node	*n2;

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
