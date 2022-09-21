/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:49 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:50 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	data_new(t_push_swap_data *data, int *numbers, int count)
{
	data->stacks = ft_stacks_new(numbers, count);
	data->buf = malloc(sizeof(int) * count);
	if (!data->stacks)
		return (0);
	return (1);
}

static void	data_delete(t_push_swap_data *data)
{
	ft_stacks_delete(data->stacks);
	free(data->buf);
}

static int	push_swap_criterr(t_push_swap_data *data, int err)
{
	data_delete(data);
	return (err);
}

int	push_swap(int *numbers, int count)
{
	t_push_swap_data	data;

	if (ft_is_sorted(numbers, count))
		return (0);
	if (!data_new(&data, numbers, count))
		return (push_swap_criterr(&data, 3));
	if (!ft_is_roughly_sorted(data.stacks))
	{
		ft_stacks_execute_multiple(data.stacks, Ins_Push_B, count - 3);
		if (data.stacks->a->size == 2)
			ft_stacks_execute(data.stacks, Ins_Swap_A);
		ft_sort_3(data.stacks);
		while (data.stacks->b->size)
			ft_insert_next(&data);
		ft_rotate_sort(data.stacks);
	}
	else
		ft_rotate_sort(data.stacks);
	data_delete(&data);
	return (0);
}
