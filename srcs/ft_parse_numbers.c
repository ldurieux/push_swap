#include "common.h"

static t_bool	parse_number(int *dest, char *number)
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
	return (1);
}

static t_bool	check_dup_criterr(int *cpy)
{
	free(cpy);
	return (0);
}

static t_bool	check_dup(int *values, size_t len)
{
	int		*cpy;
	size_t	idx;

	cpy = malloc(sizeof(int) * len);
	if (!cpy)
		return (check_dup_criterr(NULL));
	ft_memcpy(cpy, values, sizeof(int) * len);
	if (!ft_sort_merge(cpy, len))
		return (check_dup_criterr(cpy));
	idx = 0;
	while (++idx < len)
		if (cpy[idx - 1] == cpy[idx])
			return (check_dup_criterr(cpy));
	free(cpy);
	return (1);
}

static int	*parse_numbers_criterr(int *res)
{
	free(res);
	return (NULL);
}

int	*ft_parse_numbers(char **numbers, size_t len)
{
	int		*res;
	size_t	idx;

	if (!numbers || len == 0)
		return (parse_numbers_criterr(NULL));
	res = malloc(sizeof(int) * len);
	if (!res)
		return (parse_numbers_criterr(NULL));
	idx = (size_t)-1;
	while (++idx < len)
		if (!parse_number(res + idx, numbers[idx]))
			return (parse_numbers_criterr(res));
	if (!check_dup(res, len))
		return (parse_numbers_criterr(res));
	return (res);
}
