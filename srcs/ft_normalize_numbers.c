/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:18:33 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/03 18:18:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	check_duplicate(const int *sorted, size_t count)
{
	size_t	idx;

	idx = 0;
	while (++idx < count)
		if (sorted[idx - 1] == sorted[idx])
			return (0);
	return (1);
}

static int	binary_search(const int *array, int val, size_t count)
{
	size_t	start;
	size_t	end;
	size_t	mid;

	start = 0;
	end = count - 1;
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		if (array[mid] == val)
			return ((int)mid);
		if (array[mid] > val)
			end = mid;
		else
			start = mid;
	}
	if (array[start] == val)
		return ((int)start);
	return ((int)end);
}

static int	*normalize(int *nums, int *sorted, size_t count)
{
	int		*normalized;
	size_t	idx;

	normalized = malloc(sizeof(int) * count);
	if (!normalized)
		return (NULL);
	idx = (size_t)-1;
	while (++idx < count)
		normalized[idx] = binary_search(sorted, nums[idx], count);
	return (normalized);
}

int	ft_normalize_numbers(int **nums, size_t count)
{
	int	*sorted;
	int	*normalized;

	sorted = malloc(sizeof(int) * count);
	if (!sorted)
		return (0);
	ft_memcpy(sorted, *nums, sizeof(int) * count);
	if (!ft_sort_merge(sorted, count))
		return (free(sorted), 0);
	if (!check_duplicate(sorted, count))
		return (free(sorted), 0);
	normalized = normalize(*nums, sorted, count);
	free(*nums);
	free(sorted);
	*nums = normalized;
	return (normalized != NULL);
}
