/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:47:29 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:47:30 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# include "libft.h"
# include "ft_vector.h"
# include "ft_stacks.h"

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define BLUE	"\e[34m"
# define BOLD	"\e[1m"
# define RESET	"\e[0m"

typedef union u_checker_flags
{
	uint8_t	all;
	struct
	{
		uint8_t	debug : 1;
		uint8_t	color : 1;
		uint8_t	interactive : 1;
		uint8_t	help : 1;
		uint8_t	invalid : 1;
	};
}	t_checker_flags;

int				checker(t_checker_flags flags, t_stacks *stacks,
					int *numbers);
int				checker_interactive(t_checker_flags flags,
					t_stacks *stacks, int *numbers);

int				ft_get_instructions(int fd, t_instruction **buf,
					size_t *buf_size);
int				ft_get_one_instruction(int fd, t_instruction *ins);
size_t			ft_get_next_line(int fd, char **buf, size_t *buf_size);

t_checker_flags	ft_get_options(int *argc, char ***argv);

/* return the value of the instruction
 * if no instruction was found return Ins_Invalid */
t_instruction	ft_str_to_instruction(const char *str);

void			ft_stacks_execute(t_stacks *this, const t_instruction *ins,
					size_t ins_count, t_checker_flags flags);
void			ft_stacks_execute_one(t_stacks *this, t_instruction ins,
					t_checker_flags flags);

#endif // CHECKER_H
