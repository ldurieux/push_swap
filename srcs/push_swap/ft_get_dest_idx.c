/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dest_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//NOLINTNEXTLINE(misc-no-recursion)
static int	binary_search(int *array, int value, int start, int end)
{
	int	item;
	int	mid;

	if (start >= end)
		return (start);
	mid = (start + end) / 2;
	item = array[mid];
	if (item == value)
		return (mid);
	if (item > value)
		return (binary_search(array, value, start, mid));
	return (binary_search(array, value, mid + 1, end));
}

static void	make_pairs(t_pair *res, int *original, int *sorted, int count)
{
	int	idx;
	int	dest_idx;

	idx = -1;
	while (++idx < count)
	{
		dest_idx = binary_search(sorted, original[idx], 0, count - 1);
		res[dest_idx].dst_idx = dest_idx;
		res[dest_idx].src_idx = idx;
	}
}

t_pair	*ft_get_dest_idx(int *numbers, int count)
{
	t_pair	*res;
	int		*cpy;

	res = malloc(sizeof(t_pair) * count);
	if (!res)
		return (NULL);
	cpy = malloc(sizeof(int) * count);
	if (!cpy)
	{
		free(res);
		return (NULL);
	}
	ft_memcpy(cpy, numbers, sizeof(int) * count);
	ft_sort_merge(cpy, count);
	make_pairs(res, numbers, cpy, count);
	free(cpy);
	return (res);
}
