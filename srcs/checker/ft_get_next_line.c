#include "checker.h"

#define START_SIZE	64

static t_bool	prepare_data(t_ftvector **vec, char *buf, size_t buf_size)
{
	if (!buf || buf_size == 0)
	{
		*vec = ft_vector_new(sizeof(char), START_SIZE);
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
		(*vec)->_data_size = sizeof(char);
	}
	return (1);
}

static size_t	get_next_line_criterr(t_ftvector *vec, char **buf,
									size_t *buf_size)
{
	if (vec)
	{
		*buf = vec->data;
		*buf_size = vec->size;
		free(vec);
	}
	return (-1);
}

size_t	ft_get_next_line(int fd, char **buf, size_t *buf_size)
{
	t_ftvector	*vec;
	char		chr;

	if (!buf || !buf_size)
		return (get_next_line_criterr(NULL, buf, buf_size));
	if (!prepare_data(&vec, *buf, *buf_size))
		return (get_next_line_criterr(NULL, buf, buf_size));
	while (1)
	{
		if (read(fd, &chr, 1) != 1)
			break ;
		if (!ft_vector_push_back(vec, &chr))
			return (get_next_line_criterr(vec, buf, buf_size));
		if (chr == '\n')
			break ;
	}
	chr = '\0';
	if (!ft_vector_push_back(vec, &chr))
		return (get_next_line_criterr(vec, buf, buf_size));
	*buf = vec->data;
	*buf_size = vec->size - 1;
	free(vec);
	return (*buf_size);
}
