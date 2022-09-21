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

void	ft_rotate_by(t_stacks *stacks, int which, int count)
{
	t_ftfrwlist		*stack;
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
	ft_stacks_execute_multiple(stacks, ins, count);
}
