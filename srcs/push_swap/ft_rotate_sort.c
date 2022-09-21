/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:46 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_sort(t_stacks *stacks)
{
	int	lowest;

	lowest = ft_find_lowest(stacks->a);
	ft_rotate_by(stacks, 0, lowest);
}
