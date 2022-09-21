/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:41:04 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/21 23:41:05 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define START_SIZE	16

static t_bool	prepare_data(t_ftvector **vec, t_instruction *buf,
							size_t buf_size)
{
	if (!buf || buf_size == 0)
	{
		*vec = ft_vector_new(sizeof(t_instruction), START_SIZE);
		if (!*vec)
			return (0);
	}
	else
	{
		*vec = malloc(sizeof(t_ftvector));
		if (!*vec)
			return (0);
		(*vec)->data = buf;
		(*vec)->size = 0;
		(*vec)->_capacity = buf_size;
		(*vec)->_data_size = sizeof(t_instruction);
	}
	return (1);
}

static t_bool	get_instructions_criterr(t_ftvector *vec, char *line,
									t_instruction **buf, size_t *buf_size)
{
	if (vec)
	{
		*buf = vec->data;
		*buf_size = vec->size;
		free(vec);
	}
	free(line);
	return (0);
}

static t_bool	get_instructions_end(t_ftvector *vec, char *line,
									t_instruction **buf, size_t *buf_size)
{
	*buf = vec->data;
	*buf_size = vec->size;
	free(line);
	free(vec);
	return (1);
}

int	ft_get_one_instruction(int fd, t_instruction *ins)
{
	char	*line;
	size_t	line_size;

	line = NULL;
	if (ft_get_next_line(fd, &line, &line_size) == (size_t)-1)
	{
		free(line);
		return (-1);
	}
	if (line_size == 0 || line[line_size - 1] != '\n')
	{
		free(line);
		return (0);
	}
	line[line_size - 1] = '\0';
	*ins = ft_str_to_instruction(line);
	free(line);
	return (1);
}

t_bool	ft_get_instructions(int fd, t_instruction **buf, size_t *buf_size)
{
	t_ftvector		*vec;
	char			*line;
	size_t			line_size;
	t_instruction	instruction;

	line = NULL;
	if (!buf || !buf_size)
		return (get_instructions_criterr(NULL, line, buf, buf_size));
	if (!prepare_data(&vec, *buf, *buf_size))
		return (get_instructions_criterr(NULL, line, buf, buf_size));
	while (1)
	{
		if (ft_get_next_line(fd, &line, &line_size) == (size_t) - 1)
			return (get_instructions_criterr(vec, line, buf, buf_size));
		if (line_size == 0)
			break ;
		if (line[line_size - 1] != '\n')
			return (get_instructions_criterr(vec, line, buf, buf_size));
		line[line_size - 1] = '\0';
		instruction = ft_str_to_instruction(line);
		if (instruction == Ins_Invalid)
			return (get_instructions_criterr(vec, line, buf, buf_size));
		ft_vector_push_back(vec, &instruction);
	}
	return (get_instructions_end(vec, line, buf, buf_size));
}
