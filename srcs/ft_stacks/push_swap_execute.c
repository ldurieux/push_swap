#include "ft_stacks.h"
#include "push_swap.h"

void	ft_stacks_execute(t_stacks *this, t_instruction ins)
{
	if (ins == Ins_Invalid)
		return ;
	this->funcs[ins](this);
	ft_put_instruction_fd(ins, STDOUT);
	ft_putendl_fd("", STDOUT);
}

void	ft_stacks_execute_multiple(t_stacks *this, t_instruction ins,
								int count)
{
	int	idx;

	if (ins == Ins_Invalid)
		return ;
	idx = -1;
	while (++idx < count)
	{
		this->funcs[ins](this);
		ft_put_instruction_fd(ins, STDOUT);
		ft_putendl_fd("", STDOUT);
	}
}
