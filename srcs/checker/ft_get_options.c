/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:41:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:41:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define DEBUG		0x01
#define COLOR		0x02
#define INTERACTIVE	0x04
#define HELP		0x08
#define INVALID		0x10

static uint8_t	get_full_option(char *str)
{
	if (ft_strcmp(str, "--debug") == 0)
		return (DEBUG);
	if (ft_strcmp(str, "--color") == 0)
		return (COLOR);
	if (ft_strcmp(str, "--interactive") == 0)
		return (INTERACTIVE);
	if (ft_strcmp(str, "--help") == 0)
		return (HELP);
	return (INVALID);
}

static uint8_t	get_option(char chr)
{
	if (chr == 'd')
		return (DEBUG);
	if (chr == 'c')
		return (COLOR);
	if (chr == 'i')
		return (INTERACTIVE);
	if (chr == 'h')
		return (HELP);
	return (INVALID);
}

static uint8_t	get_options(char *str)
{
	uint8_t	res;
	size_t	idx;

	res = 0;
	idx = (size_t)-1;
	while (str[++idx])
	{
		res |= get_option(str[idx]);
		if (res & INVALID)
			return (INVALID);
		if (res & HELP)
			return (HELP);
	}
	return (res);
}

t_checker_flags	ft_get_options(int *argc, char ***argv)
{
	int				idx;
	t_checker_flags	res;

	res.all = 0;
	idx = 0;
	while (++idx < *argc)
	{
		if (!(*argv)[idx])
			break ;
		if ((*argv)[idx][0] != '-')
			break ;
		if (ft_isdigit((*argv)[idx][1]))
			break ;
		if ((*argv)[idx][1] == '-')
			res.all |= get_full_option((*argv)[idx]);
		else
			res.all |= get_options((*argv)[idx] + 1);
		if (res.invalid || res.help)
			return (res);
	}
	if (res.interactive)
		res.debug = 1;
	*argc -= idx;
	*argv += idx;
	return (res);
}
