/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:43:08 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:43:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_merge_inside(int *data, int *left, size_t len_left,
						size_t len_right)
{
	size_t	idx_left;
	size_t	idx_right;
	int		*right;

	idx_left = 0;
	idx_right = 0;
	right = data + len_left;
	ft_memcpy(left, data, sizeof(int) * len_left);
	while (idx_left < len_left && idx_right < len_right)
	{
		if (left[idx_left] <= right[idx_right])
			*data++ = left[idx_left++];
		else
			*data++ = right[idx_right++];
	}
	ft_memcpy(data, left + idx_left, sizeof(int) * (len_left - idx_left));
}

static void	ft_merge(int *data, size_t mid, size_t end, int *buf)
{
	ft_merge_inside(data, buf, mid + 1, end - mid);
}

//NOLINTNEXTLINE (misc-no-recursion)
static void	ft_sort_merge_recursive(int *data, size_t start, size_t end,
								int *buf)
{
	size_t	mid;

	if (start >= end)
		return ;
	mid = start + (end - start) / 2;
	ft_sort_merge_recursive(data, start, mid, buf);
	ft_sort_merge_recursive(data, mid + 1, end, buf);
	ft_merge(data + start, mid - start, end - start, buf);
}

int	*ft_sort_merge(int *data, size_t len)
{
	int	*buf;

	buf = malloc(sizeof(int) * (len / 2 + 1));
	if (!buf)
		return (NULL);
	ft_sort_merge_recursive(data, 0, len - 1, buf);
	free(buf);
	return (data);
}
