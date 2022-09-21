#include "push_swap.h"

t_bool	ft_is_sorted(const int *numbers, int count)
{
	int	idx;

	idx = 0;
	while (++idx < count)
		if (numbers[idx - 1] >= numbers[idx])
			return (0);
	return (1);
}
