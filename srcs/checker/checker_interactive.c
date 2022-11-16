/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_interactive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:41:02 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:41:03 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	error(int *numbers, t_stacks *stacks, t_instruction *ins, int err)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	free(numbers);
	ft_stacks_delete(stacks);
	free(ins);
	return (err);
}

int	checker_interactive(t_checker_flags flags, t_stacks *stacks, int *numbers)
{
	t_instruction	ins;
	int				res;

	ft_stacks_print(stacks, flags);
	res = 1;
	while (res)
	{
		res = ft_get_one_instruction(STDIN_FILENO, &ins);
		if (res == -1)
			return (error(numbers, stacks, NULL, 2));
		if (res == 0)
			return (0);
		if (ins == Ins_Invalid)
		{
			ft_putendl_fd("Invalid Instruction", STDOUT_FILENO);
			continue ;
		}
		ft_stacks_execute_one(stacks, ins, flags);
	}
	return (2);
}
