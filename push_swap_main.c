#include "push_swap.h"
#include "common.h"
#include "ft_stacks.h"

static int	error(int *numbers, int err)
{
	ft_putendl_fd("Error", STDOUT);
	free(numbers);
	return (err);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	res;

	if (argc <= 1)
		return (1);
	numbers = ft_parse_numbers(argv + 1, argc - 1);
	if (!numbers)
		return (error(numbers, 2));
	res = push_swap(numbers, argc - 1);
	free(numbers);
	return (res);
}
