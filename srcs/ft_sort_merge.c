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

typedef struct s_subarrays
{
	size_t	len_left;
	size_t	len_right;
	size_t	idx_left;
	size_t	idx_right;
	int		*left;
	int		*right;
}	t_subarrays;

static void	ft_merge_inside(int *data, t_subarrays *d)
{
	size_t	idx_left;
	size_t	idx_right;
	int		*left;
	int		*right;

	idx_left = 0;
	idx_right = 0;
	left = d->left;
	right = d->right;
	ft_memcpy(left, data, sizeof(int) * d->len_left);
	ft_memcpy(right, data + d->len_left, sizeof(int) * d->len_right);
	while (idx_left < d->len_left && idx_right < d->len_right)
	{
		if (left[idx_left] <= right[idx_right])
			*data++ = left[idx_left++];
		else
			*data++ = right[idx_right++];
	}
	ft_memcpy(data, left + idx_left, sizeof(int) * (d->len_left - idx_left));
	ft_memcpy(data + d->len_left - idx_left, right + idx_right,
		sizeof(int) * (d->len_right - idx_right));
}

static t_bool	ft_merge(int *data, size_t mid, size_t end)
{
	t_subarrays	d;

	d.len_left = mid + 1;
	d.len_right = end - mid;
	d.left = malloc(sizeof(int) * (d.len_left + d.len_right));
	d.right = d.left + d.len_left;
	if (!d.left)
		return (0);
	ft_merge_inside(data, &d);
	free(d.left);
	return (1);
}

//NOLINTNEXTLINE (misc-no-recursion)
static t_bool	ft_sort_merge_recursive(int *data, size_t start, size_t end)
{
	size_t	mid;

	if (start >= end)
		return (1);
	mid = start + (end - start) / 2;
	if (!ft_sort_merge_recursive(data, start, mid))
		return (0);
	if (!ft_sort_merge_recursive(data, mid + 1, end))
		return (0);
	return (ft_merge(data + start, mid - start, end - start));
}

int	*ft_sort_merge(int *data, size_t len)
{
	if (!ft_sort_merge_recursive(data, 0, len - 1))
		return (NULL);
	return (data);
}
