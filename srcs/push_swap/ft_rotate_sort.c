#include "push_swap.h"

void	ft_rotate_sort(t_stacks *stacks)
{
	int	lowest;

	lowest = ft_find_lowest(stacks->a);
	ft_rotate_by(stacks, 0, lowest);
}
