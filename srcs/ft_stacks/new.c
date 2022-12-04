/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:42:10 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:42:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

static t_stacks_func	*make_funcs(void)
{
	t_stacks_func	*res;
	int				idx;

	res = malloc(sizeof(t_stacks_func) * COUNT_INS);
	if (!res)
		return (NULL);
	idx = 0;
	res[idx++] = NULL;
	res[idx++] = ft_stacks_sa;
	res[idx++] = ft_stacks_sb;
	res[idx++] = ft_stacks_ss;
	res[idx++] = ft_stacks_pa;
	res[idx++] = ft_stacks_pb;
	res[idx++] = ft_stacks_ra;
	res[idx++] = ft_stacks_rb;
	res[idx++] = ft_stacks_rr;
	res[idx++] = ft_stacks_rra;
	res[idx++] = ft_stacks_rrb;
	res[idx++] = ft_stacks_rrr;
	return (res);
}

t_stacks	*new_criterr(t_stacks *res)
{
	if (res)
	{
		ft_list_delete(res->a);
		ft_list_delete(res->b);
		free(res->funcs);
	}
	free(res);
	return (NULL);
}

t_stacks	*ft_stacks_new(int *data, size_t size)
{
	t_stacks	*res;

	res = malloc(sizeof(t_stacks));
	if (!res)
		return (NULL);
	res->a = ft_list_new();
	res->b = ft_list_new();
	res->funcs = make_funcs();
	if (!res->a || !res->b || !res->funcs)
		return (new_criterr(res));
	while (size-- > 0)
		if (!ft_list_push_front(res->a, (void *)(int64_t)data[size]))
			return (new_criterr(res));
	return (res);
}
