/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:47:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:47:32 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "ft_vector.h"

typedef enum e_instruction
{
	Ins_Invalid,
	Ins_Swap_A,
	Ins_Swap_B,
	Ins_Swap_Both,
	Ins_Push_A,
	Ins_Push_B,
	Ins_Rotate_A,
	Ins_Rotate_B,
	Ins_Rotate_Both,
	Ins_Reverse_Rotate_A,
	Ins_Reverse_Rotate_B,
	Ins_Reverse_Rotate_Both,
	COUNT_INS,
}	t_instruction;

/* parse every numbers in numbers and return them
 * if a malloc error occured return NULL
 * if a number is malformed return NULL */
int		*ft_parse_numbers(char **numbers, size_t len);

/* sort len values in data using the merge algorithm
 * if a malloc error occured return null */
int		*ft_sort_merge(int *data, size_t len);

/* put the string representation of ins to fd */
void	ft_put_instruction_fd(t_instruction ins, int fd);

#endif // COMMON_H
