/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:50:35 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:50:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "common.h"
#include "ft_stacks.h"

static int	error(int *numbers, int err)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	free(numbers);
	return (err);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		res;
	size_t	len;

	if (argc < 2)
		return (error(NULL, 1));
	numbers = ft_parse_numbers(argv + 1, &len);
	if (!numbers)
		return (error(numbers, 2));
	res = push_swap(numbers, (int)len);
	free(numbers);
	return (res);
}
