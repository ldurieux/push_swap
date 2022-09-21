#ifndef FT_STACKS_H
# define FT_STACKS_H

# include "libft.h"
# include "ft_frwlist.h"
# include "common.h"

struct s_stacks;
union u_checker_flags;

typedef void (*t_stacks_func)(struct s_stacks *);
typedef union u_checker_flags t_checker_flags;

typedef struct s_stacks
{
	t_ftfrwlist		*a;
	t_ftfrwlist		*b;
	t_stacks_func	*funcs;
}	t_stacks;

t_stacks	*ft_stacks_new(int *data, size_t size);
void		ft_stacks_delete(t_stacks *this);

void		ft_stacks_execute(t_stacks *this, const t_instruction *ins,
							size_t ins_count, t_checker_flags flags);
void		ft_stacks_execute_one(t_stacks *this, t_instruction ins,
								t_checker_flags flags);

t_bool		ft_stacks_is_sorted(t_stacks *this);
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
