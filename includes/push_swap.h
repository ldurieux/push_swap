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

typedef struct s_push_swap_data
{
	t_stacks	*stacks;
	int64_t		*buf;
}	t_push_swap_data;

int		push_swap(int *numbers, int count);

void	prepare_stacks(t_stacks *stacks);

int		ft_is_sorted(const int *numbers, int count);
/* return true if stack a is sorted but the
 * rotation does not matter */
int		ft_is_roughly_sorted(t_stacks *stacks);

/* insert one value from stack b to
 * stack a in the correct position */
void	ft_insert_next(t_push_swap_data *data);

/* use rr or rrr if rot_a or rot_b have a common part */
void	ft_rotate_common(t_stacks *stacks, int64_t *rot_a, int64_t *rot_b);
/* rotate stack which by count
 * which 0 is stack a
 * other values are stack b
 * this function can decide in which way it should
 * rotate, correct way or reverse*/
void	ft_rotate_by(t_stacks *stacks, int which, size_t count);
/* rotate the stack a until it is in the correct rotation
 * this function expect the stack to at least
 * be sorted but in the wrong rotation */
void	ft_rotate_sort(t_stacks *stacks);

int64_t ft_find_lowest(t_ftfrwlist *stack);
int64_t	ft_find_biggest(t_ftfrwlist *stack);

/* in adition to executing the instruction,
 * these functions print it to STDOUT_FILENO */
void	ft_stacks_execute(t_stacks *this, t_instruction ins);
void	ft_stacks_execute_multiple(t_stacks *this, t_instruction ins,
			int64_t count);

#endif // PUSH_SWAP_H
