/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:47:32 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:47:33 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACKS_H
# define FT_STACKS_H

# include "libft.h"
# include "ft_list.h"
# include "common.h"

struct							s_stacks;
union							u_checker_flags;

typedef void					(*t_stacks_func)(struct s_stacks *);
typedef union u_checker_flags	t_checker_flags;

typedef struct s_stacks
{
	t_ftlist		*a;
	t_ftlist		*b;
	t_stacks_func	*funcs;
}	t_stacks;

t_stacks	*ft_stacks_new(int *data, size_t size);
void		ft_stacks_delete(t_stacks *this);

/* return true only if stack b is empty and
 * stack is sorted and in the correct rotation */
int			ft_stacks_is_sorted(t_stacks *this);
void		ft_stacks_print(t_stacks *this, t_checker_flags flags);

void		ft_stacks_sa(t_stacks *this);
void		ft_stacks_sb(t_stacks *this);
void		ft_stacks_ss(t_stacks *this);

void		ft_stacks_pa(t_stacks *this);
void		ft_stacks_pb(t_stacks *this);

void		ft_stacks_ra(t_stacks *this);
void		ft_stacks_rb(t_stacks *this);
void		ft_stacks_rr(t_stacks *this);

void		ft_stacks_rra(t_stacks *this);
void		ft_stacks_rrb(t_stacks *this);
void		ft_stacks_rrr(t_stacks *this);

#endif // FT_STACKS_H
