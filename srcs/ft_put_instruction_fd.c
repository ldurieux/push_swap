/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_instruction_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:43:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:43:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_put_instruction_fd(t_instruction ins, int fd)
{
	if (ins == Ins_Swap_A)
		ft_putendl_fd("sa", fd);
	else if (ins == Ins_Swap_B)
		ft_putendl_fd("sb", fd);
	else if (ins == Ins_Swap_Both)
		ft_putendl_fd("ss", fd);
	else if (ins == Ins_Push_A)
		ft_putendl_fd("pa", fd);
	else if (ins == Ins_Push_B)
		ft_putendl_fd("pb", fd);
	else if (ins == Ins_Rotate_A)
		ft_putendl_fd("ra", fd);
	else if (ins == Ins_Rotate_B)
		ft_putendl_fd("rb", fd);
	else if (ins == Ins_Rotate_Both)
		ft_putendl_fd("rr", fd);
	else if (ins == Ins_Reverse_Rotate_A)
		ft_putendl_fd("rra", fd);
	else if (ins == Ins_Reverse_Rotate_B)
		ft_putendl_fd("rrb", fd);
	else if (ins == Ins_Reverse_Rotate_Both)
		ft_putendl_fd("rrr", fd);
}
