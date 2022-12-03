/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:17 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:18 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"
#include "push_swap.h"

void	ft_stacks_execute(t_stacks *this, t_instruction ins)
{
	if (ins == Ins_Invalid)
		return ;
	this->funcs[ins](this);
	ft_put_instruction_fd(ins, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	ft_stacks_execute_multiple(t_stacks *this, t_instruction ins,
								int64_t count)
{
	int64_t	idx;

	if (ins == Ins_Invalid)
		return ;
	idx = -1;
	while (++idx < count)
	{
		this->funcs[ins](this);
		ft_put_instruction_fd(ins, STDOUT_FILENO);
		ft_putendl_fd("", STDOUT_FILENO);
	}
}
