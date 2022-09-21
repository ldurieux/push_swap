/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:47:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:47:35 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "common.h"
# include "ft_stacks.h"

typedef struct s_pair
{
	int	src_idx;
	int	dst_idx;
}	t_pair;

typedef struct s_push_swap_data
{
	t_stacks	*stacks;
	int			*buf;
}	t_push_swap_data;

int		push_swap(int *numbers, int count);

t_bool	ft_is_sorted(const int *numbers, int count);
t_pair	*ft_get_dest_idx(int *numbers, int count);

void	ft_sort_3(t_stacks *stacks);
void	ft_insert_next(t_push_swap_data *data);
void	ft_rotate_by(t_stacks *stacks, int which, int count);
void	ft_rotate_sort(t_stacks *stacks);

int		ft_find_lowest(t_ftfrwlist *stack);

void	ft_stacks_execute(t_stacks *this, t_instruction ins);
void	ft_stacks_execute_multiple(t_stacks *this, t_instruction ins,
			int count);

#endif // PUSH_SWAP_H
