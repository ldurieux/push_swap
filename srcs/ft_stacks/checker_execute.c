/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:41:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:41:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"
#include "checker.h"

void	ft_stacks_execute_one(t_stacks *this, t_instruction ins,
							t_checker_flags flags)
{
	if (ins == Ins_Invalid)
		return ;
	this->funcs[ins](this);
	if (flags.debug)
	{
		ft_putstr_fd("=== ", STDOUT);
		ft_put_instruction_fd(ins, STDOUT);
		ft_putendl_fd(" ===", STDOUT);
		ft_stacks_print(this, flags);
	}
}

void	ft_stacks_execute(t_stacks *this, const t_instruction *ins,
						size_t ins_count, t_checker_flags flags)
{
	size_t	idx;

	idx = (size_t)-1;
	while (++idx < ins_count)
	{
		if (ins[idx] == Ins_Invalid)
			return ;
		this->funcs[ins[idx]](this);
		if (flags.debug)
		{
			if (flags.color)
				ft_putstr_fd(BOLD, STDOUT);
			ft_putstr_fd("=== ", STDOUT);
			ft_put_instruction_fd(ins[idx], STDOUT);
			ft_putendl_fd(" ===", STDOUT);
			if (flags.color)
				ft_putstr_fd(RESET, STDOUT);
			ft_stacks_print(this, flags);
		}
	}
}
