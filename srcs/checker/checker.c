#include "checker.h"

static int	error(int *numbers, t_stacks *stacks, t_instruction *ins, int err)
{
	ft_putendl_fd("Error", STDOUT);
	free(numbers);
	ft_stacks_delete(stacks);
	free(ins);
	return (err);
}

int checker(t_checker_flags flags, t_stacks *stacks, int *numbers)
{
	t_instruction	*ins;
	size_t			ins_count;

	ins = NULL;
	if (!ft_get_instructions(STDIN, &ins, &ins_count))
		return (error(numbers, stacks, ins, 2));
	ft_stacks_print(stacks, flags);
	ft_stacks_execute(stacks, ins, ins_count, flags);
	free(ins);
	return (0);
}
