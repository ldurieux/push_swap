/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:42 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_is_sorted(const int *numbers, int count)
{
	int	idx;

	idx = 0;
	while (++idx < count)
		if (numbers[idx - 1] >= numbers[idx])
			return (0);
	return (1);
}
