#include "ft_stacks.h"

void	ft_stacks_delete(t_stacks *this)
{
	if (!this)
		return ;
	ft_frwlist_delete(this->a);
	ft_frwlist_delete(this->b);
	free(this->funcs);
	free(this);
}
