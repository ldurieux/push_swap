/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:41:35 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:41:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stacks.h"

void	ft_stacks_delete(t_stacks *this)
{
	if (!this)
		return ;
	ft_frwlist_delete(this->a);
	ft_frwlist_delete(this->b);
	free(this->funcs);
	free(this);
}
