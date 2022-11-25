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

#define INT32_MAX_STR "2147483647"
#define INT32_MIN_STR "-2147483648"

static int	parse_number(int *dest, char *number)
{
	if (!dest || !number)
		return (0);
	if (number[0] != '-' && !ft_isdigit(number[0]))
		return (0);
	if (number[0] == '-' && !ft_isdigit(number[1]))
		return (0);
	if (!ft_str_isdigit(number + 1))
		return (0);
	*dest = ft_strtoi(number, NULL);
	if ((*dest == INT32_MAX && ft_strcmp(number, INT32_MAX_STR))
		|| (*dest == INT32_MIN && ft_strcmp(number, INT32_MIN_STR)))
		return (0);
	return (1);
}

static int	check_dup(int *values, size_t len)
{
	int		*cpy;
	size_t	idx;

	cpy = malloc(sizeof(int) * len);
	if (!cpy)
		return (0);
	ft_memcpy(cpy, values, sizeof(int) * len);
	if (!ft_sort_merge(cpy, len))
		return (free(cpy), 0);
	idx = 0;
	while (++idx < len)
		if (cpy[idx - 1] == cpy[idx])
			return (free(cpy), 0);
	free(cpy);
	return (1);
}

static void	free_strarr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = (size_t)-1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static int	*parse_numbers_criterr(int *res, char **numbers, char **argv)
{
	free(res);
	if (numbers != argv)
		free_strarr(numbers);
	return (NULL);
}

int	*ft_parse_numbers(char **argv, size_t *len)
{
	int		*res;
	size_t	idx;
	char	**numbers;

	numbers = argv;
	if (!argv[1])
		numbers = ft_strsplit(argv[0], " \n\r\f\t\v");
	if (!numbers)
		return (parse_numbers_criterr(NULL, numbers, argv));
	*len = (size_t)-1;
	while (numbers[++(*len)])
		;
	res = malloc(sizeof(int) * *len);
	if (!res)
		return (parse_numbers_criterr(NULL, numbers, argv));
	idx = (size_t)-1;
	while (++idx < *len)
		if (!parse_number(res + idx, numbers[idx]))
			return (parse_numbers_criterr(res, numbers, argv));
	if (!check_dup(res, *len))
		return (parse_numbers_criterr(res, numbers, argv));
	if (numbers != argv)
		free_strarr(numbers);
	return (res);
}
