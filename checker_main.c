/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:50:32 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:50:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "checker.h"
#include "ft_stacks.h"

static int	help(void)
{
	char	*output;

	output = "Usage: checker [OPTION]... [NUMBER]...\n"
		"Check if a set of instructions will sort the numbers.\n\n"
		"  -d, --debug         print the array after every "
		"instructions.\n"
		"  -c, --color         color the output.\n"
		"  -i, --interactive   execute the instruction after each"
		"new line.\n"
		"  -h, --help          display this help and exit.";
	ft_putendl_fd(output, STDOUT);
	return (0);
}

static int	error(int *numbers, t_stacks *stacks, t_instruction *ins, int err)
{
	ft_putendl_fd("Error", STDOUT);
	free(numbers);
	ft_stacks_delete(stacks);
	free(ins);
	return (err);
}

static int	main_end(t_stacks *stacks, int *numbers, int res,
					t_checker_flags flags)
{
	if (res)
		return (res);
	if (ft_stacks_is_sorted(stacks))
	{
		if (flags.color)
			ft_putstr_fd(GREEN, STDOUT);
		ft_putendl_fd("OK", STDOUT);
	}
	else
	{
		if (flags.color)
			ft_putstr_fd(RED, STDOUT);
		ft_putendl_fd("KO", STDOUT);
	}
	if (flags.color)
		ft_putstr_fd(RESET, STDOUT);
	ft_stacks_delete(stacks);
	free(numbers);
	return (res);
}

int	main(int argc, char **argv)
{
	int				*numbers;
	t_stacks		*stacks;
	t_checker_flags	flags;
	int				res;

	if (argc <= 1)
		return (1);
	flags = ft_get_options(&argc, &argv);
	if (flags.help || flags.invalid)
		return (help());
	numbers = ft_parse_numbers(argv, argc);
	if (!numbers)
		return (error(numbers, NULL, NULL, 2));
	stacks = ft_stacks_new(numbers, argc);
	if (!stacks)
		return (error(numbers, stacks, NULL, 2));
	if (flags.interactive)
		res = checker_interactive(flags, stacks, numbers);
	else
		res = checker(flags, stacks, numbers);
	return (main_end(stacks, numbers, res, flags));
}
