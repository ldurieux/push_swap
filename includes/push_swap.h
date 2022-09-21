#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "common.h"

typedef struct s_pair
{
	int	idx;
	int	dest;
}	t_pair;

int	push_swap(int *numbers, int count);

t_pair	*ft_get_dest_idx(int *numbers, int count);

#endif // PUSH_SWAP_H
