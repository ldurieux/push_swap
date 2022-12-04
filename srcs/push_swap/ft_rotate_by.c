/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_by.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:44 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_common(t_stacks *stacks, int64_t *rot_a, int64_t *rot_b)
{
	int64_t	mid_a;
	int64_t	mid_b;
	int64_t	min;

	mid_a = (int64_t)stacks->a->size / 2;
	mid_b = (int64_t)stacks->b->size / 2;
	min = (int64_t)ft_min(*rot_a, *rot_b);
	if (*rot_a <= mid_a && (*rot_b <= mid_b || *rot_a == *rot_b))
	{
		ft_stacks_execute_multiple(stacks, Ins_Rotate_Both, min, 1);
		*rot_a -= min;
		*rot_b -= min;
	}
}

void	ft_rotate_by(t_stacks *stacks, int which, size_t count)
{
	t_ftlist		*stack;
	t_instruction	ins;

	stack = stacks->a;
	ins = Ins_Rotate_A;
	if (which)
	{
		ins = Ins_Rotate_B;
		stack = stacks->b;
	}
	if (count > stack->size / 2)
	{
		if (ins == Ins_Rotate_A)
			ins = Ins_Reverse_Rotate_A;
		else
			ins = Ins_Reverse_Rotate_B;
		count = ((int)stack->size) - count;
	}
	ft_stacks_execute_multiple(stacks, ins, (int64_t)count, 1);
}
