/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:43:04 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:43:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

#define DEFAULT_VEC_SIZE 512

void	free_strarr(char **arr, size_t count)
{
	size_t	idx;

	idx = (size_t)-1;
	while (++idx < count)
		free(arr[idx]);
	free(arr);
}

static char	**split_args(char **args, size_t *count)
{
	t_ftvector	*vec;
	const char	*str;
	char		*tok;
	char		**res;
	size_t		idx;

	vec = ft_vector_new(sizeof(char *), DEFAULT_VEC_SIZE);
	if (!vec)
		return (NULL);
	idx = 0;
	str = *args;
	while (str)
	{
		tok = ft_strtok_r(str, " \r\f\n\t\v", &str);
		if (!tok)
			return (ft_vector_delete(vec), NULL);
		if (!ft_vector_push_back(vec, &tok))
			return (ft_vector_delete(vec), NULL);
		if (!*str)
			str = args[++idx];
	}
	res = vec->data;
	*count = vec->size;
	free(vec);
	return (res);
}

#define INT_MAX_STR "2147483647"
#define INT_MIN_STR "-2147483648"

static int	str_to_int(char *str, int *num)
{
	char	*end;

	*num = ft_strtoi(str, &end);
	if (*end
		|| (*num == INT_MIN && (ft_strcmp(str, INT_MIN_STR) != 0))
		|| (*num == INT_MAX && (ft_strcmp(str, INT_MAX_STR) != 0)))
		return (0);
	return (1);
}

static int	strs_to_int(char **strs, int *nums, size_t count)
{
	int	*end;

	end = nums + count;
	while (nums != end)
	{
		if (!str_to_int(*strs, nums))
			return (0);
		strs++;
		nums++;
	}
	return (1);
}

int	*ft_parse_numbers(char **args, size_t *count)
{
	char	**numbers_str;
	int		*res;

	numbers_str = split_args(args, count);
	if (!numbers_str)
		return (0);
	res = malloc(sizeof(int) * *count);
	if (!res)
	{
		free_strarr(numbers_str, *count);
		return (0);
	}
	if (!strs_to_int(numbers_str, res, *count))
	{
		free_strarr(numbers_str, *count);
		free(res);
		return (NULL);
	}
	free_strarr(numbers_str, *count);
	if (!ft_normalize_numbers(&res, *count))
	{
		free(res);
		return (NULL);
	}
	return (res);
}
